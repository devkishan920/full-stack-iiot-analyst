// Reading Time Stamps
// Using Timer 3 Ch1 - PA6 AF2

#include "stm32f446xx.h"

volatile unsigned int time_count = 0;

void gpio_init() // Step 1 : Configure PA6 to Alternate Function
{
  RCC->AHB1ENR |= (1<<0); // Enable clock to Port A

  GPIOA->MODER &= ~(0x3 << (2*6));
  GPIOA->MODER |= (0x2 << (2*6)); // Set PA6 to Alternate Mode

  GPIOA->AFR[0] &= ~(0xF000000);
  GPIOA->AFR[0] |= (0x2000000); // PA6 to AF2 : Timer3 Ch1
}

// PreScaler : division factor useful for setting the frequency, at which timer operates

void tim3_init() // Step 2 : Timer Configuration - Timer3 Ch1 for Input Capture Mode
{
  RCC->APB1ENR |= (1<<1); // Giving clock to Timer3

  TIM3->PSC = (1600-1); // 16000000/1600 = 10KHz. Timer frequency is set to 10KHz, For Capturing Time Stamps

  //** Set Tim3 Ch1 to "Input Capture Mode", using "TIMx capture/compare mode register 1 (TIMx_CCMR1)" See Pg. - 569
  TIM3->CCMR1 &= ~(0x3); // Cleared Bit 0,1
  TIM3->CCMR1 |= (0x1); //  CC1 channel is configured as input, IC1 is mapped on TI1 Bit0-1, Bit1-0

  TIM3->CCER |= (1<<0); // Enable Input Capture Mode using "TIMx capture/compare enable register (TIMx_CCER)" bit0 CC1E

  TIM3->CCER &= ~(1<<1) & ~(1<<3); //** Setting POLARITY of Input Capture Module, i.e., Capturing Interrupt should be either at Rising, Falling or Both. This is done using "TIMx capture/compare enable register (TIMx_CCER)"  see pg.- 571


  // Enable TImer3
  TIM3->CR1 |= (1<<0);
}

int main()
{
  gpio_init();
  tim3_init();

//  ------------------------------------------ Output Compare Code
  // Configuring PA5 to to Output Timer Compare Mode
   RCC->AHB1ENR |= (1 << 0); // Enable GPIOA clock

   GPIOA->MODER &= ~(3 << (2 * 5)); // Clear mode for PA5

   GPIOA->MODER |= (2 << (2 * 5)); // Set PA5 to alternate function mode
   // OR
   // GPIOA->MODER |= (1 << ((2 * 5)+1));


   GPIOA->AFR[0] &= ~(0xF << (4 * 5)); // Clear pin alternate function bits for PA5
   // OR
 //  GPIOA->AFR[0] &= ~(0xF00000);

   // AF1 PA5 : Timer2 Ch1
   GPIOA->AFR[0] |= (1 << (4 * 5)); // Set pin to AF1 for TIM2 CH1
   // OR
 //  GPIOA->AFR[0] |= (0x100000);


 // Step 2 - Configure TIM2 to 1 Hz and
   RCC->APB1ENR |= (1 << 0); // Enable TIM2 clock
   TIM2->PSC = (16000 - 1); // Set Pre-Scaler (16000000/16000 = 1KHz). Timer frequency is set to 1KHz, For Generating Pulses
   TIM2->ARR = 1000; // Set auto-reload register to 1000

 // Step 3 - Toggle CH1 output when the counter value is 0
   TIM2->CCMR1 = 0x30; //(3 << 4); // Set output to toggle on match (OC1M = 0110)
   TIM2->CCR1 = 0; // Set compare match value to 0 (CCR1 = 0)
   TIM2->CCER |= (1 << 0); // Enable CH1 compare mode (CC1E = 1)
   TIM2->CNT = 0; // Clear counter (CNT = 0)
   TIM2->CR1 = (1 << 0);

//  -------------------------------------------

  // Step 3 : Capture Timer Count Value at each rising edge. This is using "TIMx status register (TIMx_SR)", see pg.-564

  while(1)
    {
      while(!(TIM3->SR & (1<<0))) // Wait till Input Capture Rising Edge Interrupt Detected
	{

	}
      // Holding Capture value in "TIMx capture/compare register 1 (TIMx_CCR1)"
      time_count = TIM3->CCR1; // reading the capture register
    }

}
