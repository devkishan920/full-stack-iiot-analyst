// PC9 i/p	-	PA8 o/p
#include "stm32f4xx.h"

int main()
{
  __disable_irq();

  RCC->AHB1ENR |= (0x5); // Enable Clock for Port A, C
  GPIOA->MODER &= ~(0x3<<(2*8));
  GPIOA->MODER |= (1<<(2*8));
  GPIOC->MODER &= ~(0x3<<(2*9));

  RCC->APB2ENR |= (1<<14);
  SYSCFG->EXTICR[2] |= (1<<5);
  EXTI->IMR |= (1<<9);
  EXTI->FTSR |= (1<<9);
  EXTI->RTSR &= ~(1<<9);
  NVIC_EnableIRQ(EXTI9_5_IRQn);

  __enable_irq();

  while(1)
    {

    }
}

void delay(int n)
{
  while(n>0)
    {
      n--;
    }
}

void EXTI9_5_IRQHandler()
{
  delay(80000);

	if (EXTI->PR & (1 << 9)) // checks whether interrupt occured or not
	{
	  EXTI->PR |= (1<<9); // clearing pending register for bit 13
	}

	while(!(GPIOC->IDR & (1<<9)))
	  {
	    GPIOA->ODR |= (1<<8);
	  }

	GPIOA->ODR &= ~(1<<8);
}
