//// Following code receives and prints to console Character by character
//#include "stm32f446xx.h"
//#include <stdio.h>
//
//void usart2_init()
//{
//  RCC->AHB1ENR |= (1<<0);
//  RCC->APB1ENR |= (1<<17); // Enable Clock to USART2
//
//  // PA3 supports USART2 Rx. So (10) setu to moder 3
//  GPIOA->MODER |= (1<<7);
//
//  GPIOA->MODER |= (1<<(2*5));
//
//  // Using GPIO Alternate Function Register having required functionality, i.e., AF7 have USART2 Rx at PA3.
//  // So for this at desired pin, set the code provided for AF7
//  GPIOA->AFR[0] |= (0x7000); // 0 - for low register,  1 - for high register
//
//  USART2->BRR |= (0x8B); // 115200 oversampling by 16
//
//  // OVER8 = 0 ; by default oversampling by 16
//  USART2->CR1 |= (1<<13); // USART Enable
//  // word length = 0; by default 8 bit data
//  USART2->CR1 |= (1<<2); // Receive
//
//  // STOP = 00;  by default 1 stop bit
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
//uint8_t usart2_rx()
//{
////  while((USART2->SR)&(1<<5)) // whether data recieved or not
//    while(!(USART2->SR&1<<5)) // whether data recieved or not
//	{
//
//	}
//    return(USART2->DR & (0xFF));
//}
//
//int main()
//{
////  unsigned char data[10];
////  int i=0;
//  usart2_init();
//
//  while(1)
//    {
////      unsigned char receive[10] = usart2_rx();
//      unsigned char receive = usart2_rx();
////      if((receive == '\r') || (receive == '\n'))
////	{
////	  data[i++] = receive;
////	}
//
////	  printf("Received Data : %s\r\n",data);
////  	  printf("Received Data : %s\r\n",receive);
//      	  printf("Received Data : %c\r\n",receive);
////	  delay(500);
//    }
//}

#include "stm32f446xx.h"
#include <stdio.h>

uint8_t data;

void gpio_init()
{
  RCC->AHB1ENR |= (1<<0);
}

void usart2_init()
{
  RCC->APB1ENR |= (1<<17);

  GPIOA->MODER |= (1<<7);
  GPIOA->MODER &= ~(1<<6);

  GPIOA->AFR[0] |= (0x7000);

  USART2->BRR |= (0x8B);

  // Oversampling by 16 (by default)
  USART2->CR1 |= (1<<13);
  // 8 bit workd length (by default)
  USART2->CR1 |= (1<<2);

  // 00 stop bit (by default)
}

int main()
{
  gpio_init();
  usart2_init();

  while(1)
    {
      while(!((USART2->SR) & (1<<5)))
	{

	}
	  data = USART2->DR;
	  printf("%c\r\n",data);
    }
}
