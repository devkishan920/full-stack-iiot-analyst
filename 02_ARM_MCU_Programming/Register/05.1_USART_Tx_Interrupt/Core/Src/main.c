//// Uses ISR for receiving data ONLY when  Data is RECEIVED
//
//
//#include "stm32F446xx.h"
//
//void gpio_init()
//{
//  RCC->AHB1ENR |= (1<<0);
//}
//
//void usart2_init()
//{
//  RCC->APB1ENR |= (1<<17);
//  // PA2 : USART2_Tx	PA3 : USART2_Rx
//  GPIOA->MODER |= (1<<((2*2)+1)); // PA2 set to alternate function
//  GPIOA->MODER |= (1<<((2*3)+1)); // PA3 set to alternate function
//
//  GPIOA->AFR[0] |= (0x700);
//  GPIOA->AFR[0] |= (0x7000);
//
//  USART2->BRR |= (0x8B);
//
//  // Only new lines added-------------
//  USART2->CR1 |= (1<<5); // Enable RXNEIE : Enabels interrupt on USART2 Rx
//  // Enable Interrupt in NVIC controller
//  NVIC_EnableIRQ(USART2_IRQn);
////  -----------------------------------
//  USART2->CR1 |= (1<<13) | (1<<3) | (1<<2);
//}
//
//int main()
//{
//  gpio_init();
//  usart2_init();
//
//  while(1)
//    {
//
//    }
//}
//
//void USART2_IRQHandler() // Name of this function must be similiar to that of Interrrupt Handler for USART2 - only called when reception takes place
//{
//  uint8_t data;
//
//  while(!((USART2->SR) & (1<<5)))
//	{
//
//	}
//  data = USART2->DR;
//  while(!((USART2->SR) & (1<<7)))
//	{
//
//	}
//  USART2->DR = data;
//}


#include "stm32f4xx.h"

// Function prototypes
void USART2_Init(void);
void USART2_Transmit(char data);
void USART2_IRQHandler(void);

void delay(int d)
{
  int temp;
  temp = d;
  while(d>0)
    {
      for(int i=0; i<d; i++)
	{
	  temp++;
	}
      d--;
    }
}
int main(void) {
    // Initialize USART2
    USART2_Init();

    // Example string to send
    char *msg = "Hello, USART2!\r\n";
    while (*msg) {
        USART2_Transmit(*msg++);
    }

    while (1) {
        // Main loop can do other things while transmission is handled by interrupt
	GPIOA->ODR ^= (1<<5);
	delay(500);
    }
}

void USART2_Init(void) {
    // Enable GPIOA clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    GPIOA->MODER &= ~(1<<(2*5));
    GPIOA->MODER |= (1<<(2*5));
    // Enable USART2 clock
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

    // Configure PA2 (USART2_TX) as alternate function
    GPIOA->MODER &= ~(GPIO_MODER_MODER2);
    GPIOA->MODER |= GPIO_MODER_MODER2_1;  // Alternate function mode
    GPIOA->AFR[0] |= (7 << 8);            // AF7 (USART2_TX) for PA2

    // Configure USART2
    USART2->BRR = 0x0683;  // Baud rate 9600 at 16 MHz
    USART2->CR1 |= USART_CR1_TE | USART_CR1_TXEIE | USART_CR1_UE;  // Transmit enable, TXE interrupt enable, USART enable

    // Enable USART2 interrupt in NVIC
    NVIC_EnableIRQ(USART2_IRQn);
}

void USART2_Transmit(char data) {
    while (!(USART2->SR & USART_SR_TXE));  // Wait until TXE (transmit data register empty) flag is set
    USART2->DR = data;
}

void USART2_IRQHandler(void) {
    if (USART2->SR & USART_SR_TXE)
      /*checking the status of the USART2 Status Register (SR) to see if the Transmit Data Register Empty (TXE) flag is set.

Here's a detailed breakdown:

USART2->SR refers to the Status Register of USART2.

USART_SR_TXE is a specific bit within the Status Register that indicates whether the Transmit Data Register (DR) is empty and ready for new data.

When (USART2->SR & USART_SR_TXE) evaluates to true, it means that the TXE flag is set, indicating that the transmit data register is empty and can accept new data to be transmitted.*/
      {
        USART2->CR1 &= ~USART_CR1_TXEIE;  // Disable TXE interrupt
    }
}
