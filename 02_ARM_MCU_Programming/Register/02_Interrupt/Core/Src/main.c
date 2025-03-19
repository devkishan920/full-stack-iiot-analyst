#include "stm32f4xx.h"

int main()
{
  __disable_irq();

  RCC->AHB1ENR |= (1<<0);
  RCC->AHB1ENR |= (2<<1);

  GPIOA->MODER &= ~(0x3<<(2*5));
  GPIOA->MODER |= (1<<(2*5));

  GPIOC->MODER &= ~(0x3<<(2*13));
//  -------------------------------------------
  EXTI->IMR |= (1<<13); // unmask interrupt

  EXTI->FTSR |= (1<<13); // enabling rising edge trigger
  EXTI->RTSR &= ~(1<<13); // disabling rising edge trigger

  RCC->APB2ENR |= (1<<14); // enabling clock for syconfig controller

  SYSCFG->EXTICR[3] |= (1<<5); // enable interrupt source PC13

  NVIC_EnableIRQ(EXTI15_10_IRQn); // Enable Interrupt

//  NVIC_SetPriority(EXTI15_10_IRQn, 15); // Lower the value, higher the priority

  __enable_irq();

  while(1)
    {
      // only required in Polling Mode
    }
}

void delay(int n)
{
  while(n>0)
    {
      n--;
    }
}

void EXTI15_10_IRQHandler(void) // void <any_name>_<IRQHandler()>
{
//  GPIOA->ODR |= (1<<5);	// Toggles LED
//  delay(500);
//  GPIOA->ODR &= ~(1<<5);
  delay(80000);

  	if (EXTI->PR & (1 << 13)) // checks whether interrupt occured or not
  	{
  	  EXTI->PR |= (1<<13); // clearing pending register for bit 13
  	}

  	GPIOA->ODR ^= (1<<5);
//		if (!(GPIOC->IDR & (1 << 13)))
//		{
//			GPIOA->ODR |= (1<<5);
//		}
//		else
//		{
//			GPIOA->ODR &= ~(1<<5);
//		}
}

