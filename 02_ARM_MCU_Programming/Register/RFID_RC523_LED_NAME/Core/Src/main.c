/*SPI CONNECTION:
 *
 * MOSI----->PA7
 * MISO----->PA6
 * RST------>PA8
 * SCK------>PA5
 * SDA/CS------>PB0
 * VCC--------->3.3V
 *
 *
 ***************************
 * I2C_LCD CONNECTION:
 *
 * SDA-------->PB9
 * SCL-------->PB8
 * VCC-------->5V
 *
 ***************************
 *
 */

#include "LiquidCrystal_PCF8574.h"
#include "delay.h"
#include "stdio.h"
#include "RFID.h"
extern void SysClockConfig(void);
#include "stm32f4xx.h"

uint8_t rfid_id[4];
char data[20];

int main(void)
{
	// For LEDs
    RCC->AHB1ENR |= (1 << 0);
    GPIOA->MODER &= ~(0x3 << (2 * 4));
    GPIOA->MODER |= (1 << (2 * 4));
    GPIOA->MODER &= ~(0x3 << (2 * 1));
    GPIOA->MODER |= (1 << (2 * 1));

    //     SysClockConfig();
    systick_init_ms(16000000);
    rc522_init();
    lcd_init();
    setCursor(0, 0);
    lcd_send_string("TESTING RFID!");
    setCursor(3, 1);
    lcd_send_string("with STM32F4");
    while (1)
    {
        if (rc522_checkCard(rfid_id))
        {
//            lcd_clear();
//            //	char data[20];
//            setCursor(0, 0);
//            lcd_send_string("RFID code is");
//            setCursor(0, 1);
            sprintf(data, "0x%x 0x%x 0x%x 0x%x", rfid_id[0], rfid_id[1], rfid_id[2], rfid_id[3]);
//            lcd_send_string(data);
            delay(1000);
        }

        // prints RFIDs in console
        for (int i = 0; i < 20; i++)
        {
            printf("%c", data[i]);
        }
        delay(100);
        printf("\n");

        // Check if the RFID ID matches the specified ID
        if (rfid_id[0] == 0xc3 && rfid_id[1] == 0x95 && rfid_id[2] == 0x2d && rfid_id[3] == 0xda)
        {
            // Turn on the LED
            GPIOA->ODR |= (1 << 4);
            setCursor(0, 0);
            lcd_send_string("RFID A");
            setCursor(0, 1);
            sprintf(data, "0x%x 0x%x 0x%x 0x%x", rfid_id[0], rfid_id[1], rfid_id[2], rfid_id[3]);

        }
        else
        {
            // Turn off the LED
            GPIOA->ODR &= ~(1 << 4);
        }

        if (rfid_id[0] == 0x77 && rfid_id[1] == 0xb8 && rfid_id[2] == 0x1c && rfid_id[3] == 0x2f)
        {
            // Turn on the LED
            GPIOA->ODR |= (1 << 1);
            setCursor(0, 0);
            lcd_send_string("RFID B");
            setCursor(0, 1);
            sprintf(data, "0x%x 0x%x 0x%x 0x%x", rfid_id[0], rfid_id[1], rfid_id[2], rfid_id[3]);
        }
        else
        {
            // Turn off the LED
            GPIOA->ODR &= ~(1 << 1);
        }
    }
}
