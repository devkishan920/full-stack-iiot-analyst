// Configuring Timer2
// for (clk_f = 16000000); (delay = 1 sec); then (Arr = 1000)

#include "stm32f446xx.h"

void gpio_init()
{
  RCC->AHB1ENR |= (1<<0);

  GPIOA->MODER &= ~(1<<(2*5));
  GPIOA->MODER |= (1<<(2*5));
}

void tim2_config() // for 1msec
{
  //configuration
  RCC->APB1ENR |= (1<<0); // Enable clock to Timer2
  TIM2->CR1 &= ~(1<<0); // Disable Counter Timer

  // psc = (16000/16000000) = 1ms
  TIM2->PSC = 16000-1;// Loading Pre-Scaler Value
  TIM2->ARR = 1000; // Load Auto Reload Register

  TIM2->CR1 |= (1<<0); //  Enable Counter Timer
  // bit 4; by default 0 - upcounter
}

void delay(int ms)
{
  TIM2->CNT = 0;
  while(TIM2->CNT < ms);
}

int main()
{
  gpio_init();
  tim2_config();

  while(1)
    {
      // infinite loop
      GPIOA->ODR |= (1<<5);
      delay(1000);
      GPIOA->ODR &= ~(1<<5);
      delay(1000);
    }
}
