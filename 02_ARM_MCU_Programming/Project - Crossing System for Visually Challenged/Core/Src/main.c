// #include "stm32f4xx.h"
//
//// PA5, PA6, PA7 : LEDs
//// TIM2
// int a=0, i=0;
//
// void gpio_init()
//{
//  RCC->AHB1ENR |= (1<<0); // Clock enable for Port A
//
//  GPIOA->MODER &= ~(0x3<<(2*5)) & ~(0x3<<(2*6)) & ~(0x3<<(2*7)); // clear moder
//  GPIOA->MODER |= (1<<(2*5)) | (1<<(2*6)) | ((1<<(2*7))); // set as output
//}
//
// void tim2_init() // timer2 set for delay
//{
//  RCC->APB1ENR |= (1<<0);
//  TIM2->CR1 &= ~(1<<0);
//
//  // psc = (16000/16000000) = 1ms
//   TIM2->PSC = 16000-1;// Loading Pre-Scaler Value
//   TIM2->ARR = 1000; // Load Auto Reload Register
//
//   TIM2->CR1 |= (1<<0); //  Enable Counter Timer
//}
//
// void delay_1sec(int ms)
//{
//  TIM2->CNT = 0;
//  while(TIM2->CNT < ms);
//}
//
// void delay(int sec)
//{
//  while(sec>0)
//    {
//      delay_1sec(1000);
//      sec--;
//      a++;
//    }
//}
//
// void cross_button() // setting pc13 as interrupt
//{
//  __disable_irq();
//  RCC->AHB1ENR |= (1<<2);
//  RCC->APB2ENR |= (1<<14);
//  SYSCFG->EXTICR[3] |= (0x20);
//  EXTI->IMR |= (1<<13);
//  EXTI->RTSR |= (1<<13);
//  NVIC_EnableIRQ(EXTI15_10_IRQn);
//  __enable_irq();
//}
//
//
// int main()
//{
//
//  gpio_init();
//  tim2_init();
//  cross_button();
//
//  while(1)
//    {
//      // Traffic lights working normally
//      GPIOA->ODR |= (1<<7); // Red
//      GPIOA->ODR &= ~(1<<6);
//      GPIOA->ODR &= ~(1<<5);
//      delay(50);
//
//      GPIOA->ODR &= ~(1<<7);
//      GPIOA->ODR |= (1<<6); // Yellow
//      GPIOA->ODR &= ~(1<<5);
//      delay(10);
//
//      GPIOA->ODR &= ~(1<<7);
//      GPIOA->ODR &= ~(1<<6);
//      GPIOA->ODR |= (1<<5); // Green
//      delay(50);
//
//      GPIOA->ODR &= ~(1<<7);
//      GPIOA->ODR |= (1<<6); // Yellow
//      GPIOA->ODR &= ~(1<<5);
//      delay(10);
//    }
//}
//
// void EXTI15_10_IRQHandler()
//{
//	if (EXTI->PR & (1 << 13)) // checks whether interrupt occured or not
//	{
//	  EXTI->PR |= (1<<13); // clearing pending register for bit 13
//	}
//
//	GPIOA->ODR &= ~(1<<7);
//	GPIOA->ODR |= (1<<6); // Yellow
//	GPIOA->ODR &= ~(1<<5);
//	delay(10);
//
//	GPIOA->ODR |= (1<<7); // Red
//	GPIOA->ODR &= ~(1<<6);
//	GPIOA->ODR &= ~(1<<5);
//	delay(60);
//}

/*I see what you're describing—after the interrupt is handled, your code does not seem to resume from where it left off in the main loop. This issue might be related to the fact that the delay function is being called within the interrupt handler.

When you use the delay() function inside your EXTI15_10_IRQHandler() interrupt handler, it effectively halts the execution of your main program. Here’s why that might cause issues:

Interrupt Handling: Interrupts should generally be as fast as possible. Delays within interrupts can cause missed or delayed responses to other interrupts.

Global State: Delays within interrupts might also interfere with the main program, since you’re modifying the a variable within the delay() function.

One solution could be to remove any long delays within the interrupt handler and instead set a flag or a state variable that the main loop can handle.

Here's an example to give you an idea of how you might modify your approach:*/

// #include "stm32f4xx.h"
//
//// PA5, PA6, PA7 : LEDs
//// TIM2
// int a=0, i=0, b=0;
//
// void gpio_init()
//{
//  RCC->AHB1ENR |= (1<<0); // Clock enable for Port A
//
//  GPIOA->MODER &= ~(0x3<<(2*5)) & ~(0x3<<(2*6)) & ~(0x3<<(2*7)); // clear moder
//  GPIOA->MODER |= (1<<(2*5)) | (1<<(2*6)) | ((1<<(2*7))); // set as output
//}
//
// void tim2_init() // timer2 set for delay
//{
//  RCC->APB1ENR |= (1<<0);
//  TIM2->CR1 &= ~(1<<0);
//
//  // psc = (16000/16000000) = 1ms
//   TIM2->PSC = 16000-1;// Loading Pre-Scaler Value
//   TIM2->ARR = 1000; // Load Auto Reload Register
//
//   TIM2->CR1 |= (1<<0); //  Enable Counter Timer
//}
//
// void delay_1sec(int ms)
//{
//  TIM2->CNT = 0;
//  while(TIM2->CNT < ms);
//}
//
// void delay(int sec)
//{
//  while(sec>0)
//    {
//      delay_1sec(1000);
//      sec--;
//      a++;
//    }
//}
//
// void cross_button() // setting pc13 as interrupt
//{
//  __disable_irq();
//  RCC->AHB1ENR |= (1<<2);
//  RCC->APB2ENR |= (1<<14);
//  SYSCFG->EXTICR[3] |= (0x20);
//  EXTI->IMR |= (1<<13);
//  EXTI->RTSR |= (1<<13);
//  NVIC_EnableIRQ(EXTI15_10_IRQn);
//  __enable_irq();
//}
//
// volatile int interrupt_flag = 0;
//
// void SysTick_1s()
//{
//
//// Enable SysTick timer with processor clock
//  SysTick->CTRL |= (1<<0); // Counter Enabled
//  SysTick->CTRL |= (1<<2); // Clk Source set to Processor Clock
//
//
//// To set desired Delay, Load Value to STRVR register (24 bit, hence max value is (2^24 = 16777216))
//
//  SysTick->LOAD = (16000000);
//
//  SysTick->VAL = 0;// Clear the current value register
//
//  while((SysTick->CTRL & (1<<16))==0);// Wait until the COUNTFLAG is set
//  SysTick->CTRL = 0;// Clear the Count Flag
//}
//
// void sysTick_delay(int n)
//{
//  while(n>0)
//    {
//      SysTick_1s();
//      n--;
//      b++;
//    }
//}
//
//
// int main()
//{
//  gpio_init();
//  tim2_init();
//  cross_button();
//
//  while(1)
//  {
//    if (interrupt_flag)
//    {
//      GPIOA->ODR &= ~(1<<7);
//      GPIOA->ODR |= (1<<6); // Yellow
//      GPIOA->ODR &= ~(1<<5);
//      delay(10);
//
//      GPIOA->ODR |= (1<<7); // Red
//      GPIOA->ODR &= ~(1<<6);
//      GPIOA->ODR &= ~(1<<5);
//      delay(60);
//
//      interrupt_flag = 0; // clear the flag
//    }
//
//    else
//    {
//      // Traffic lights working normally
//      GPIOA->ODR |= (1<<7); // Red
//      GPIOA->ODR &= ~(1<<6);
//      GPIOA->ODR &= ~(1<<5);
//      delay(50);
//
//      GPIOA->ODR &= ~(1<<7);
//      GPIOA->ODR |= (1<<6); // Yellow
//      GPIOA->ODR &= ~(1<<5);
//      delay(10);
//
//      GPIOA->ODR &= ~(1<<7);
//      GPIOA->ODR &= ~(1<<6);
//      GPIOA->ODR |= (1<<5); // Green
//      delay(50);
//
//      GPIOA->ODR &= ~(1<<7);
//      GPIOA->ODR |= (1<<6); // Yellow
//      GPIOA->ODR &= ~(1<<5);
//      delay(10);
//    }
//  }
//}
//
// void EXTI15_10_IRQHandler()
//{
//	if (EXTI->PR & (1 << 13)) // checks whether interrupt occured or not
//	{
//	  EXTI->PR |= (1<<13); // clearing pending register for bit 13
//	}
//
//	GPIOA->ODR &= ~(1<<7);
//	GPIOA->ODR |= (1<<6); // Yellow
//	GPIOA->ODR &= ~(1<<5);
//	sysTick_delay(10);
//
//	GPIOA->ODR |= (1<<7); // Red
//	GPIOA->ODR &= ~(1<<6);
//	GPIOA->ODR &= ~(1<<5);
//	sysTick_delay(60);
//}

#include "stm32f4xx.h"

// PA5, PA6, PA7 : LEDs
// TIM2
int a = 0, i = 0, b = 0, remaining = 0;

void gpio_init()
{
    RCC->AHB1ENR |= (1 << 0); // Clock enable for Port A

    GPIOA->MODER &= ~(0x3 << (2 * 5)) & ~(0x3 << (2 * 6)) & ~(0x3 << (2 * 7)); // clear moder
    GPIOA->MODER |= (1 << (2 * 5)) | (1 << (2 * 6)) | (1 << (2 * 7));          // set as output
}

void tim2_init() // timer2 set for delay
{
    RCC->APB1ENR |= (1 << 0);
    TIM2->CR1 &= ~(1 << 0);

    // psc = (16000/16000000) = 1ms
    TIM2->PSC = 16000 - 1; // Loading Pre-Scaler Value
    TIM2->ARR = 1000;      // Load Auto Reload Register

    TIM2->CR1 |= (1 << 0); //  Enable Counter Timer
}

void delay_1sec(int ms)
{
    TIM2->CNT = 0;
    while (TIM2->CNT < ms)
        ;
}

void delay(int sec)
{
    while (sec > 0)
    {
        delay_1sec(1000);
        sec--;
        a++;

        if (i == 1)
        {
            remaining = 10 - a;
        }
    }
}

void cross_button() // setting pc13 as interrupt
{
    __disable_irq();
    RCC->AHB1ENR |= (1 << 2);
    RCC->APB2ENR |= (1 << 14);
    SYSCFG->EXTICR[3] |= (0x20);
    EXTI->IMR |= (1 << 13);
    EXTI->RTSR |= (1 << 13);
    NVIC_EnableIRQ(EXTI15_10_IRQn);
    __enable_irq();
}

volatile int interrupt_flag = 0;

void SysTick_1s()
{
    // Enable SysTick timer with processor clock
    SysTick->CTRL |= (1 << 0); // Counter Enabled
    SysTick->CTRL |= (1 << 2); // Clk Source set to Processor Clock

    // To set desired Delay, Load Value to STRVR register (24 bit, hence max value is (2^24 = 16777216))

    SysTick->LOAD = (16000000);

    SysTick->VAL = 0; // Clear the current value register

    while ((SysTick->CTRL & (1 << 16)) == 0)
        ;              // Wait until the COUNTFLAG is set
    SysTick->CTRL = 0; // Clear the Count Flag
}

void sysTick_delay(int n)
{
    while (n > 0)
    {
        SysTick_1s();
        n--;
        b++;
    }
}

void red()
{
    GPIOA->ODR |= (1 << 7); // Red
    GPIOA->ODR &= ~(1 << 6);
    GPIOA->ODR &= ~(1 << 5);
}

void yellow()
{
    GPIOA->ODR &= ~(1 << 7);
    GPIOA->ODR |= (1 << 6); // Yellow
    GPIOA->ODR &= ~(1 << 5);
}

void green()
{
    GPIOA->ODR &= ~(1 << 7);
    GPIOA->ODR &= ~(1 << 6);
    GPIOA->ODR |= (1 << 5); // Green
    i = 1;
}

int main()
{
    gpio_init();
    tim2_init();
    cross_button();

    while (1)
    {
        // Traffic lights working normally
        red();
        delay(10);
        a = 0;

        yellow();
        delay(5);
        a = 0;

        green();
        delay(10);
        a = 0;
        i = 0;

        yellow();
        delay(5);
        a = 0;
    }
}

void EXTI15_10_IRQHandler()
{
    if (EXTI->PR & (1 << 13)) // checks whether interrupt occured or not
    {
        EXTI->PR |= (1 << 13); // clearing pending register for bit 13
    }

    yellow();
    sysTick_delay(5);
    b = 0;

    red();
    sysTick_delay(10);
    b = 0;

    if (remaining != 0)
    {
        GPIOA->ODR &= ~(1 << 7);
        GPIOA->ODR &= ~(1 << 6);
        GPIOA->ODR |= (1 << 5); // Green
        i = 0;
        delay(remaining);
        a = 0;
    }
}
