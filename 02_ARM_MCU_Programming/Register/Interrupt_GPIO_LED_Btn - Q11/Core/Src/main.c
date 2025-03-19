// PB7 o/p
#include "stm32f4xx.h"
#include <stdio.h>

//int press_count = 0;
//int led1_state = 0;
//int led2_state = 0;
int flag = 0;
int count = 0;

int main()
{

  __disable_irq();

  RCC->AHB1ENR |= (0x7); // Enable Clock for Port A, B, C

  GPIOA->MODER &= ~(0x3<<(2*5)); // First LED
  GPIOA->MODER |= (1<<(2*5));

  GPIOB->MODER &= ~(0x3<<(2*7)); // Second LED
  GPIOB->MODER |= (1<<(2*7));

  GPIOC->MODER &= ~(0x3<<(2*13));

  RCC->APB2ENR |= (1<<14);
  SYSCFG->EXTICR[3] |= (1<<5); // set interrupt to PC13
  EXTI->IMR |= (1<<13);
  EXTI->FTSR |= (1<<13);
  EXTI->RTSR &= ~(1<<13);
  NVIC_EnableIRQ(EXTI15_10_IRQn);

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

void EXTI15_10_IRQHandler()
{

  delay(80000);
  if (EXTI->PR & (1 << 13))
    { // Check if interrupt occurred
      EXTI->PR |= (1 << 13); // Clear pending register for bit 13
      count ++;
      if (flag == 0)
	{
	  GPIOA->ODR |= (1 << 5); // Turn ON First LED (PA5)
	GPIOB->ODR &= ~(1 << 7); // Turn OFF Second LED (PB7)
	flag = 1;
	}

      else
	{
	  GPIOA->ODR &= ~(1 << 5); // Turn OFF First LED (PA5)
	  GPIOB->ODR |= (1 << 7); // Turn ON Second LED (PB7)
	  flag = 0;
      }

      printf("Button is pressed %d times\n",count);
    }

// Second Method------------------------------------
//	if (EXTI->PR & (1 << 13)) // checks whether interrupt occured or not
//	{
//	  EXTI->PR |= (1<<13); // clearing pending register for bit 13
//	}
//
//	press_count++;
//
//	if (press_count % 2 == 1)
//	  { // 1st or 3rd press
//	    led1_state = 1;
//	    led2_state = 0;
//	  }
//
//	else
//	  { // 2nd press
//	    led1_state = 0;
//	    led2_state = 1;
//	  }
//
//	// Update LED states
//	if (led1_state)
//	  {
//	    GPIOA->ODR |= (1<<5);
//	  }
//
//	else
//	  {
//	    GPIOA->ODR &= ~(1<<5);
//	  }
//
//	if (led2_state)
//	  {
//	    GPIOB->ODR |= (1<<7);
//	  }
//
//	else
//	  {
//	    GPIOB->ODR &= ~(1<<7);
//	  }


//	if(!(GPIOC->IDR & (1<<13))&&(flag==0))
//	  {
//	    GPIOA->ODR |= (1<<5);
//	    GPIOB->ODR &= ~(1<<7);
//	    delay(500);
//	  }
//
//	if(!(GPIOC->IDR & (1<<13))&&(flag==1))
//	  {
//	    GPIOA->ODR &= ~(1<<5);
//	    GPIOB->ODR |= (1<<7);
//	    delay(500);
//	  }

//	flag ^= flag;
}
