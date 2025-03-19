#include "stm32f4xx.h"

void gpio_init()
{
  RCC->AHB1ENR |= (1<<0);
  GPIOA->MODER &= ~(1<<(2*5));
  GPIOA->MODER |= (1<<(2*5));
}


void SysTick_1s()
{

// Enable SysTick timer with processor clock

//  SysTick->CTRL = 0x5;
//  OR
  SysTick->CTRL |= (1<<0); // Counter Enabled
  SysTick->CTRL |= (1<<2); // Clk Source set to Processor Clock


  // To set desired Delay, Load Value to STRVR register (24 bit, hence max value is (2^24 = 16777216))
//  SysTick->LOAD |= (16777000);
  SysTick->LOAD = (16000000);

  SysTick->VAL = 0;// Clear the current value register

  while((SysTick->CTRL & (1<<16))==0);// Wait until the COUNTFLAG is set
  SysTick->CTRL = 0;// Clear the Count Flag

//  OR

//  while(!(SysTick->CTRL & (1<<16)))// Wait until the COUNTFLAG is set // Works
//  {
//
//  }
//   SysTick->CTRL = 0;// Clear the Count Flag

   // OR

//  while(!(SysTick->CTRL & (1<<16)));// Wait until the COUNTFLAG is set // Works
//  SysTick->CTRL = 0;// Disable SysTick timer
}

int main()
{

  gpio_init();

  while(1)
    {
      GPIOA->ODR |= (1<<5);
      SysTick_1s();
      GPIOA->ODR &= ~(1<<5);
      SysTick_1s();
    }

}


