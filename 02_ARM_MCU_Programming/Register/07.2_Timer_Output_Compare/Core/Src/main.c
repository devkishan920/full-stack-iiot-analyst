//Q) Timer TIM2 is configured as an up-counter.
//By default, the system clock is * running at 16 MHz.
//The prescaler is set to divide by 16,000 that gives a 1 kHz clock to the counter.
//The timer is set up for output compare interrupt for channel 1.
//
//When the counter matches the CCR1 register, the output toggles and
//an interrupt is triggered.
//
//In the interrupt handler, the PERIORD value is added CCR1 so that the next CCR1 match occurs after the PERIOR count.
//
//When the PERIOD is set to 1000, the output toggles at 1 Hz.
//The output of TIM2 Channel 1 is PA5 which is connected to the LED

//-------------------------------------------------------------------


//#include "stm32f446xx.h"
//
//void gpio_init()
//{
//  RCC->AHB1ENR |= (1<<0);
//
//  GPIOA->MODER &= ~(1<<(2*5));
//  GPIOA->MODER |= (1<<(2*5));
//}
//
//void tim2_config() // for 1msec
//{
//  //Timer 2, ch1 : AF1 PA0
//
//  GPIOA->MODER |= 0x00000800;/* set pin to alternate function */
////   GPIOA->MODER |= (1<<1);
//
//   GPIOA->AFR[0] &= 0x00F00000; /* clear pin AF bits */
////   GPIOA->AFR[0] &= ~(1<<0);
//
//   GPIOA->AFR[0] |= 0x00100000; /* set pin to AF1 for TIM2 CH1 */
////   GPIOA->AFR[0] |= (1<<0);
//
//
//  //configuration
//  RCC->APB1ENR |= (1<<0); // Enable clock to Timer2
//  TIM2->CR1 &= ~(1<<0); // Disable Counter Timer
//
//  // psc = (16000/16000000) = 1ms
//  TIM2->PSC = 16000-1;// Loading Pre-Scaler Value
//  TIM2->ARR = 1000; // Load Auto Reload Register
//
//  TIM2->CCMR1 = 0x30; /* set output to toggle on match */
//   TIM2->CCR1 = 0; /* set match value */
//   TIM2->CCER |= 1; /* enable CH1 compare mode */
//   TIM2->CNT = 0; /* clear counter */
////
//
//    TIM2->DIER |= (1 << 1); // Enable update interrupt for CH1
//    NVIC_EnableIRQ(TIM2_IRQn); // Enable TIM2 interrupt in NVIC
//  TIM2->CR1 |= (1<<0); //  Enable Counter Timer
//  // bit 4; by default 0 - upcounter
//}
//
//int main()
//{
//  gpio_init();
//  tim2_config();
//
//  while(1)
//    {
//      // infinite loop
////      GPIOA->ODR |= (1<<5);
////      delay(1);
////      GPIOA->ODR &= ~(1<<5);
////      delay(1);
//    }
//}

// Working
//--------------------------------------------------------------------


//#include "stm32f4xx.h"
//int main(void)
//{
//// Configure PA5 as output to drive the LED
//    RCC->AHB1ENR |= 1; /* enable GPIOA clock */
//    GPIOA->MODER &= ~0x00000C00;             /* clear pin mode */
//    GPIOA->MODER |= 0x00000800;  /* set pin to alternate function */
//    GPIOA->AFR[0] &= 0x00F00000; /* clear pin AF bits */
//    GPIOA->AFR[0] |= 0x00100000; /* set pin to AF1 for TIM2 CH1 */
//
//    // configure TIM2 to wrap around at 1 Hz and toggle CH1 output when the counter value is 0
//    RCC->APB1ENR |= 1;     /* enable TIM2 clock */
//    TIM2->PSC = 16000 - 1;  /* divided by 1600 */
//    TIM2->ARR = 1000; /* divided by 10000 */
//    TIM2->CCMR1 = 0x30;    /* set output to toggle on match */
//    TIM2->CCR1 = 0;        /* set match value */
//    TIM2->CCER |= 1;       /* enable CH1 compare mode */
//    TIM2->CNT = 0;         /* clear counter */
//    TIM2->CR1 = 1;         /* enable TIM2 */
//    while (1)
//    {
//    }
//}

// Step 1 : PA5 - o/p. Hence need to set it to O/P compare Mode of Timer

#include "stm32f4xx.h"
int main(void)
{
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

    while (1){}

  return 0;
}


