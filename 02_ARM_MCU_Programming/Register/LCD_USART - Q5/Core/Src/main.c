/* PC0-PC7 for LCD D0-D7, respectively. */
/* PB5 for LCD R/S */
/* PB6 for LCD R/W */
/* PB7 for LCD EN */

#include "stm32f4xx.h"

#define RS 0x20 		/* PB5 mask for reg select */
#define RW 0x40 		/* PB6 mask for read/write */
#define EN 0x80 		/* PB7 mask for enable */

void delayMs(int n);
void LCD_command(unsigned char command);
//void LCD_string(char []);
void LCD_data(char data);
void LCD_init(void);
void PORTS_init(void);

void usart2_init()
{
  RCC->AHB1ENR |= (1<<0);
  RCC->APB1ENR |= (1<<17); // Enable Clock to USART2

  // PA3 supports USART2 Rx. So (10) setu to moder 3
  GPIOA->MODER |= (1<<7);

  GPIOA->MODER |= (1<<(2*5));

  // Using GPIO Alternate Function Register having required functionality, i.e., AF7 have USART2 Rx at PA3.
  // So for this at desired pin, set the code provided for AF7
  GPIOA->AFR[0] |= (0x7000); // 0 - for low register,  1 - for high register

  USART2->BRR |= (0x8B); // 115200 oversampling by 16

  // OVER8 = 0 ; by default oversampling by 16
  USART2->CR1 |= (1<<13); // USART Enable
  // word length = 0; by default 8 bit data
  USART2->CR1 |= (1<<2); // Receive

  // STOP = 00;  by default 1 stop bit
}

void delay(int n)
{
  while(n>0)
    {
      n--;
    }
}

uint8_t usart2_rx()
{
//  while((USART2->SR)&(1<<5)) // whether data recieved or not
    while(!(USART2->SR&1<<5)) // whether data recieved or not
	{

	}
    return(USART2->DR & (0xFF));
}


int main(void)
{
	usart2_init();
	/* initialize LCD controller */
	LCD_init();
while(1)
	{

          unsigned char receive = usart2_rx();
//       	  printf("Received Data : %c\r\n",receive);
//    	  delay(500);

//	LCD_string("WELCOME ALL");
          if(receive=='a')
            LCD_data(0xE0); // alpha

          if(receive=='b')
            LCD_data(0xE2); //1110 0010

          if(receive=='p')
            LCD_data(0xF7); // 0111 1111
	delayMs(500);
	}
}

void LCD_string(char str[])
{
	for(int i=0;str[i]!='\0';i++)
	{
		LCD_data(str[i]);
	}

}


/* initialize port pins then initialize LCD controller */ void
LCD_init(void)
{
	PORTS_init();
	delayMs(30); /* initialization sequence */
	LCD_command(0x30);
	delayMs(10);
	LCD_command(0x30);
	delayMs(1);
	LCD_command(0x30);
	LCD_command(0x38);		/*set 8-bit data, 2-line, 5x7 font */
	LCD_command(0x06);		/*move cursor right after each char */
	LCD_command(0x01);		/*clear screen, move cursor to home */
	LCD_command(0x0F);		/*turn on display, cursor blinking */


}

void PORTS_init(void)
{
	RCC->AHB1ENR |= 0x06; 			/* enable GPIOB/C clock */
	GPIOB->MODER &= ~0x0000FC00; 		/* clear pin mode */
	GPIOB->MODER |= 0x00005400; 		/* set pin output mode */
	GPIOB->BSRR = 0x00C00000; 		/*turn off EN and R/W */
	GPIOC->MODER &= ~0x0000FFFF; 		/* clear pin mode */
	GPIOC->MODER |= 0x00005555; 		/* set pin output mode */
}

void LCD_command(unsigned char command)
{

	GPIOB->BSRR = (RS | RW) << 16; 		/* RS = 0, R/W = 0 */
	GPIOC->ODR =command; 				/* put command on data bus */
	GPIOB->BSRR = EN; 				/* pulse E high */
	delayMs(0);
	GPIOB->BSRR = EN << 16; 			/* clear E */
	if (command < 4)
		delayMs(2); 				/* command 1 and 2 needs up to 1.64ms */
	else
		delayMs(1); 				/* all others 40 us */
}

void LCD_data(char data)
{
	GPIOB->BSRR = RS; 			/* RS = 1 */
	GPIOB->BSRR = RW << 16; 		/* R/W = 0 */
	delayMs(1);

	GPIOC->ODR = data; 			/* put data on data bus */
	GPIOB->BSRR = EN; 			/*pulse E high */
	delayMs(0);
	GPIOB->BSRR = EN << 16; 		/* clear E */

}

/* delay n milliseconds (16 MHz CPU clock) */
void delayMs(int n)
{
	int i;
	for (; n > 0; n--)
		for (i = 0; i < 3195; i++) ;
}

