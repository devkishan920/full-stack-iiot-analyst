// Following Transmits the String to Terminal via USART2----------------------

//#include "stm32f446xx.h"
//
//void usart2_init()
//{
//  RCC->AHB1ENR |= (1<<0); // Enable clock to GPIOA, since PA2 USART2_Tx
//  RCC->APB1ENR |= (1<<17); // Enable Clock to USART2
//
//  // PA2 supports Alternate Function of USART2 Tx. So (10) setu to moder 2
//  GPIOA->MODER |= (1<<5);
//  GPIOA->MODER &= ~(1<<4);
//
//  // Using GPIO Alternate Function Register having required functionality, i.e., AF7 have USART2 Tx at PA2.
//  // So for this at desired pin, set the code proived for AF7
//  GPIOA->AFR[0] |= (0x700); // 0 - for low register,  1 - for high register
//
//  USART2->BRR |= (0x8B); // Set Baud Rate using Baud Rate Register; 115200 oversampling by 16
//
//  // OVER8 = 0 ; by default oversampling by 16
//  USART2->CR1 |= (1<<13); // USART Enable
//  // word length = 0; by default 8 bit data
//  USART2->CR1 |= (1<<3); // Transmit Enable (TE)
//
//  // STOP = 00; in Control Register 2; by default 1 stop bit
//}
//
//void delay(int n)
//{
//  while(n>0)
//    {
//      n--;
//    }
//}
//
//void usart2_data(unsigned char data)
//{
//  while((USART2->SR)&(1<<7)) // checking Transmitter Empty Bit, whether data transmitted or not
//	{
//	      USART2->DR |= (data & 0xFF);
//	      delay(500);
//	      break;
//	}
//}
//
//void usart2_tx(char *ptr)
//{
//  while(*ptr)
//    {
//      usart2_data(*ptr);
//      delay(500);
//      ptr++;
//    }
//}
//
//int main()
//{
//  usart2_init();
//
//  while(1)
//    {
//      usart2_tx("Hello World\r\n");
//    }
//}

// Simple program to Transmit single character to Terminal via USART2---------


#include "stm32f446xx.h"

void gpio_init()
{
  RCC->AHB1ENR |= (1<<0);
}

void usart2_init()
{
  RCC->APB1ENR |= (1<<17);

  GPIOA->MODER |= (1<<5);
  GPIOA->MODER &= ~(1<<4);

  GPIOA->AFR[0] |= (0x700);

  USART2->BRR |= (0x8B);

  // Obersampling by 16 (by default)
  USART2->CR1 |= (1<<13);
  // 8 bit workd lenght (by default)
  USART2->CR1 |= (1<<3);

  // 00 stop bit (by default)
}

int main()
{
  gpio_init();
  usart2_init();

//  char message[20] = "Hello World";

  while(1)
    {
      while((USART2->SR) & (1<<7))
	{
	  USART2->DR = 'h';
	}
    }
}
