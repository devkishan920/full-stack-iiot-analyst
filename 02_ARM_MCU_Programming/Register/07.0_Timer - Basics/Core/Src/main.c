//#include "stm32f4xx.h"
//
//#define TIMER_FREQUENCY_HZ 1000
//#define DELAY_SECONDS 1
//#define LED_PIN GPIO_PIN_5
//#define LED_PORT GPIOA
//
///* Calculate the required delay */
//#define ANY_DELAY_REQUIRED (TIMER_FREQUENCY_HZ * DELAY_SECONDS)
//
//void Timer6_Init(void) {
//    // Enable the TIM6 clock
//    __HAL_RCC_TIM6_CLK_ENABLE();
//
//    // Configure the timer prescaler to generate 1 kHz timer frequency
//    TIM6->PSC = (uint32_t)(SystemCoreClock / TIMER_FREQUENCY_HZ) - 1;
//
//    // Set the required delay
//    TIM6->ARR = ANY_DELAY_REQUIRED - 1;
//
//    // Enable the update event interrupt
//    TIM6->DIER |= TIM_DIER_UIE;
//
//    // Start the timer counter
//    TIM6->CR1 |= TIM_CR1_CEN;
//
//    // Enable TIM6 interrupt in NVIC
//    NVIC_EnableIRQ(TIM6_IRQn);
//}
//
//
//void GPIO_Init(void) {
//    // Enable the GPIOA clock
//    __HAL_RCC_GPIOA_CLK_ENABLE();
//
//    // Configure the LED pin
//    GPIO_InitTypeDef GPIO_InitStruct;
//    GPIO_InitStruct.Pin = LED_PIN;
//    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//    GPIO_InitStruct.Pull = GPIO_NOPULL;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//    HAL_GPIO_Init(LED_PORT, &GPIO_InitStruct);
//}
//
//
//void TIM6_IRQHandler(void) {
//    if (TIM2->SR & TIM_SR_UIF)
//    {
//        // Clear the update interrupt flag
//        TIM2->SR &= ~TIM_SR_UIF;
//
//        // Toggle the LED
//        HAL_GPIO_TogglePin(LED_PORT, LED_PIN);
//    }
//}
//
//
//
//int main(void) {
////    HAL_Init();
////    SystemClock_Config();
//
//    // Initialize GPIO
//    GPIO_Init();
//
//    // Initialize Timer6
//    Timer6_Init();
//
//    while (1) {
//        // Main loop
//    }
//}
//
//void SystemClock_Config(void) {
//    // Configure system clock if needed (depends on your setup)
//}


// Snippets

//// Snippet for 1 second delay at 500 Hz
//
//#define TIMER_FREQUENCY_HZ 500
//#define DELAY_SECONDS 1
//
///* Calculate the required delay */
//#define ANY_DELAY_REQUIRED (TIMER_FREQUENCY_HZ * DELAY_SECONDS)
//
///* Clear the update event flag */
//TIM6->SR = 0;
//
///* Set the prescaler value to generate 500 Hz timer frequency */
//TIM6->PSC = (uint32_t)(SystemCoreClock / TIMER_FREQUENCY_HZ) - 1;
//
///* Set the required delay */
//TIM6->ARR = ANY_DELAY_REQUIRED - 1;
//
///* Start the timer counter */
//TIM6->CR1 |= TIM_CR1_CEN;
//
///* Loop until the update event flag is set */
//while (!(TIM6->SR & TIM_SR_UIF));
//
///* The required time delay has been elapsed */
///* User code can be executed */
//
//// Snippet for 1 millisecond delay at 1000 Hz
//
//#define TIMER_FREQUENCY_HZ 1000
//#define DELAY_MILLISECONDS 1
//
///* Calculate the required delay */
//#define ANY_DELAY_REQUIRED (TIMER_FREQUENCY_HZ * DELAY_MILLISECONDS / 1000)
//
///* Clear the update event flag */
//TIM6->SR = 0;
//
///* Set the prescaler value to generate 1 kHz timer frequency */
//TIM6->PSC = (uint32_t)(SystemCoreClock / TIMER_FREQUENCY_HZ) - 1;
//
///* Set the required delay */
//TIM6->ARR = ANY_DELAY_REQUIRED - 1;
//
///* Start the timer counter */
//TIM6->CR1 |= TIM_CR1_CEN;
//
///* Loop until the update event flag is set */
//while (!(TIM6->SR & TIM_SR_UIF));
//
///* The required time delay has been elapsed */
///* User code can be executed */

//-------------------------------------------------------
//#include "stm32f4xx.h"
//
//void timer_init()
//{
//  RCC->APB1ENR |= (1<<3);
//  GPIOA->MODER |= (1<<1);
//  GPIOA->AFR[0] |= (1<<1);
//}
//
//void timer_delay()
//{
//  TIM5->PSC |= 16000-1;
//  TIM5->ARR |= 1000-1;
//  TIM5->CNT |= 0;
//  TIM5->CR1 |= 1;
//}
//
//int main()
//{
//  RCC->AHB1ENR |= (0x1);
//
////  GPIOA->MODER |= (1<<10);
//  timer_init();
//
//  while(1)
//    {
//      timer_delay();
//      while(!(TIM5->SR) & 1);
//      GPIOA->ODR ^= (0x20);
//      TIM5->SR |= 0;
//    }
//}

//-------------------------------------------------

//#include "stm32f4xx.h" // Include the appropriate header file for your STM32 series
//
//void delay_ms(uint32_t ms) {
//    // Enable the clock for TIM2
//    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
//
//    // Configure the prescaler (assuming a 16 MHz clock)
//    TIM2->PSC = 16000 - 1; // Prescale to 1 kHz (1 ms per tick)
//
//    // Configure the auto-reload value for the desired delay
//    TIM2->ARR = ms;
//
//    // Reset the counter
//    TIM2->CNT = 0;
//
//    // Enable the timer
//    TIM2->CR1 |= TIM_CR1_CEN;
//
//    // Wait until the update event flag is set
//    while (!(TIM2->SR & TIM_SR_UIF)) {}
//
//    // Clear the update event flag
//    TIM2->SR &= ~TIM_SR_UIF;
//
//    // Disable the timer
//    TIM2->CR1 &= ~TIM_CR1_CEN;
//}
//
//int main(void) {
//    // Initialize system
//  RCC->AHB1ENR |= (1<<0);
//
//  GPIOA->MODER &= ~(0x3<<(2*5));
//  GPIOA->MODER |= (1<<(2*5));
//
//    // Create a delay
////    delay_ms(1000); // Delay for 1000 ms (1 second)
//
//    while (1) {
//        // Main loop
//	GPIOA->ODR ^= (1<<5);
//	delay_ms(500); // Delay for 1000 ms (1 second)
//    }
//}

// Working
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




