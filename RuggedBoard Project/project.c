#include <stdio.h>      /* Standard input/output definitions */
#include <stdlib.h>     /* Standard library definitions */
#include <string.h>     /* String function definitions */
#include <unistd.h>     /* UNIX standard function definitions */
#include <fcntl.h>      /* File control definitions */
#include <errno.h>      /* Error number definitions */
#include <termios.h>    /* POSIX terminal control definitions */
#include <sys/select.h> /* For select() */
#include "MQTTClient.h" /* Include the MQTTClient library */

#define SERIAL_PORT "/dev/ttyS3"    /* Define the serial port */
#define BAUDRATE B115200            /* Define the baud rate */
#define BUFFER_SIZE 256             /* Define the buffer size */

#define ADDRESS     "tcp://mqtt.eclipseprojects.io:1883"    /* MQTT broker address */
#define CLIENTID    "ExampleClientPub"                      /* Client ID */
#define TOPIC       "MQTT projects"                         /* Topic to publish to */
#define QOS         1                                       /* Quality of Service level */
#define TIMEOUT     10000L                                  /* Timeout in milliseconds */
char buffer[BUFFER_SIZE];                                   /* Buffer to store received data */

int pub()
{
    MQTTClient client; /* MQTT client handle */
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer; /* Connection options */
    MQTTClient_message pubmsg = MQTTClient_message_initializer; /* Message structure */
    MQTTClient_deliveryToken token; /* Delivery token */
    int rc; /* Return code */
    /* Initialize the MQTT client */
    MQTTClient_create(&client, ADDRESS, CLIENTID,MQTTCLIENT_PERSISTENCE_NONE, NULL); 
    conn_opts.keepAliveInterval = 20; /* Keep alive interval */
    conn_opts.cleansession = 1; /* Clean session flag */
    /* Connect to the MQTT broker */
    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        exit(EXIT_FAILURE);
    }
    pubmsg.payload = buffer; // Use the buffer as the payload
    pubmsg.payloadlen = (int)strlen(buffer); // Length of the payload
    pubmsg.qos = QOS; // Quality of Service level
    pubmsg.retained = 0; // Retained message flag
    /* Publish the message */
    MQTTClient_publishMessage(client, TOPIC, &pubmsg, &token);
    printf("Waiting for up to %d seconds for publication of %s\n"
            "on topic %s for client with ClientID: %s\n",
            (int)(TIMEOUT/1000), buffer, TOPIC, CLIENTID);
    rc = MQTTClient_waitForCompletion(client, token, TIMEOUT);
    printf("Message with delivery token %d delivered\n", token);
    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);
    return rc;
}
int main() {
    int fd;                 /* File descriptor for the serial port */
    struct termios tty;      /* Structure to hold the serial port settings */
    
    int ret;
    fd_set readfds;         /* File descriptor set for select() */
    struct timeval tv;      /* Timeout structure for select() */

    /* Open the serial port */
    fd = open(SERIAL_PORT, O_RDWR | O_NOCTTY | O_NDELAY); /* Open the serial port in read/write mode, no controlling terminal, non-blocking */
    if (fd < 0) {
        perror("Error opening serial port");
        return 1;
    }

    /* Get the current serial port settings */
    if (tcgetattr(fd, &tty) < 0) {
        perror("Error getting serial port settings");
        close(fd);
        return 1;
    }

    /* Configure the serial port settings */
    tty.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;  /* Set baud rate, 8 data bits, no control, enable read */
    tty.c_iflag = IGNPAR;                           /* Ignore parity errors */
    tty.c_oflag = 0;                                /* Raw output */
    tty.c_lflag = 0;                                  /* Non-canonical mode */
    tty.c_cc[VMIN]  = 0;                  /* Minimum number of characters to read */
    tty.c_cc[VTIME] = 5;                 /* Read timeout in deciseconds (0.5s)*/

    /* Apply the serial port settings */
    if (tcsetattr(fd, TCSANOW, &tty) < 0) {
        perror("Error setting serial port settings");
        close(fd);
        return 1;
    }

    /* Clear the input buffer */
    tcflush(fd, TCIFLUSH);

    printf("Serial port %s opened and configured.  Waiting for data...\n", SERIAL_PORT);

    while (1) {
        /* Initialize the file descriptor set */
        FD_ZERO(&readfds);
        FD_SET(fd, &readfds); /* Add the serial port to the set */

        /* Set the timeout (adjust as needed) */
        tv.tv_sec = 2;         /* 2 seconds */
        tv.tv_usec = 0; 

        /* Wait for data to be available or timeout */
        ret = select(fd + 1, &readfds, NULL, NULL, &tv);

        if (ret < 0) {
            perror("Error in select()");
            close(fd);
            return 1;
        } else if (ret == 0) {
            printf("Timeout: No data received.\n");
            continue; /* Go back to the beginning of the loop */
        } else {
             /* Data is available to be read */
            if (FD_ISSET(fd, &readfds)) {
                /* Read the data */
                memset(buffer, 0, BUFFER_SIZE); // Clear the buffer before reading
                ret = read(fd, buffer, BUFFER_SIZE - 1);  /* Read up to BUFFER_SIZE - 1 bytes */
                if (ret > 0) {
                    /* Print the received data */
                    printf("Received %d bytes: %s", ret, buffer);
					pub(); // Call the publish function
                    fflush(stdout); /* Ensure the output is printed immediately */
                } else if (ret == 0) {
                    printf("End of file reached (serial port closed).\n");
                    break; /* Exit the loop */
                } else {
                    perror("Error reading from serial port");
                    close(fd);
                    return 1;
                }
            }
        }
    }

    /* Close the serial port */
    close(fd);
    return 0;
}