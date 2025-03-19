#include"stm32f4xx.h"

void gpio()
{
//	RCC->APB1ENR |= 101<<0; //
//	GPIOA->MODER |= 10<<11;
//	GPIOA->AFR[0]|=0X2000000;

	RCC->AHB1ENR |= (1<<0); //  GPIOA clock
	RCC->APB1ENR |= (1<<0); //  TIM2 clock
	RCC->APB1ENR |= (1<<1); //  TIM3 clock

	GPIOA->MODER |= (2<<12); // AF
	GPIOA->AFR[0] |= (2<<24); // PA6 as AF2 (TIM3_CH1)
}
void tim()
{
//	RCC->AHB1ENR |= 11<<0;
	TIM2->PSC = 16000-1;
	TIM2->ARR = 3000-1;
	TIM2->CNT = 0;
	TIM2->DIER |= 1<<0; //EN INT
	TIM2->CR1 |=1<<0; //TIM EN
	NVIC_EnableIRQ(TIM2_IRQn);

	TIM3->PSC = 160-1;
	TIM3->ARR = 100-1;
	TIM3->CNT = 0 ;
	TIM3->CCMR1 |= 0X60;
	TIM3->CCMR1 |=0X8;
	TIM3->CCER|=1;
	TIM3->CR1 |=1<<7;
	TIM3->CCR1 = 50;
	TIM3->CR1 |=1;
}
int a,x=0;
void TIM2_IRQHandler(void)
{
	TIM2->SR &= ~(1);
		  switch (x)
		  {
			case 0:
				TIM3->ARR = 100-1;
				TIM3->CCR1 = 50;
				x=1;
				break;
			case 1:
				TIM3->ARR = 50-1;
				TIM3->CCR1 = 25;
				x=0;
				break;
		  }
}
int main()
{
	gpio();
	tim();
	while(1)
	{
		a=GPIOC->IDR&1<<8;
	}
}


//// Using General Purpose Timer2 Ch1 AF1

#include "stm32f446xx.h"

void delay(int d)
{
  for(int i=0; i<d*100; i++);
}

void gpio_init() // Setting PA5 to Alternate Mode
{
  RCC->AHB1ENR |= (1<<0);

  GPIOA->MODER &= ~(0x3<<(2*5));
  GPIOA->MODER |= (0x2<<(2*5));

  GPIOA->AFR[0] |= (0x100000); // set to alternate function of timer2_ch1
}

void tim2_pwm_init()
{
  RCC->APB1ENR |= (1<<0); // Enabling Clock to Timer2

  TIM2->PSC = 15; // Set PreScaler Value = 15 (16-1) , i.e., fck/16 = 1MHz
  TIM2->ARR = 1000-1; // Set ARR Value

  TIM2->CCMR1 |= (0x60);// Set timer to PWM, using TIMx capture/compare mode register 1 (TIMx_CCMR1) - OC1M (bit 4,5,6)

  TIM2->CCMR1 |= (0x8);//Enable PreLoad; Bit 3 OC1PE: Output compare 1 preload enable

  TIM2->CCER |= (1<<0); // Set timer_pwm to output capture mode using, TIMx capture/compare enable register (TIMx_CCER) - bit 0 (CC1E) = enable output

  TIM2->CR1 |= (1 << 7);      // Enable auto-reload preload
  TIM2->CR1 |= (1<<0); // Enable Timer2
}

void pwm_duty_cycle(uint16_t duty)
{
  TIM2->CCR1 = duty; // writing preload value, TIMx capture/compare register 1 (TIMx_CCR1). Preload Register Assignment: When setting the duty cycle, you should use the assignment operator (=) instead of the OR assignment operator (|=). This ensures that the CCR1 register is directly set to the desired value.
}


int main()
{
  gpio_init();
  tim2_pwm_init();

    while (1)
      {

        for(int i=0; i<1000; i++)
          {
            pwm_duty_cycle(i);
            delay(50);
          }

        for(int i=1000; i>0; i--)
          {
            pwm_duty_cycle(i);
            delay(50);
          }
      }
}


//#include "stm32f446xx.h"
//
//void delay(int d)
//{
//    for(int i=0; i<d*100; i++);
//}
//
//void gpio_init()
//{
//    RCC->AHB1ENR |= (1<<0); // Enable GPIOA clock
//
//    GPIOA->MODER &= ~(0x3<<(2*5)); // Clear mode for PA5
//    GPIOA->MODER |= (0x2<<(2*5));  // Set PA5 to Alternate mode
//
////    GPIOA->AFR[0] |= (0x1<<(4*5)); // Set PA5 to AF1 (TIM2_CH1)
//    GPIOA->AFR[0] |= (0x100000);
//}
//
//void tim2_pwm_init()
//{
//    RCC->APB1ENR |= (1<<0); // Enable TIM2 clock
//
//    TIM2->PSC = 15;          // Set prescaler to 16 (PSC + 1)
//    TIM2->ARR = 1000 - 1;    // Set auto-reload register
//
////    TIM2->CCMR1 |= (0x6 << 4);  // Set PWM mode 1 on TIM2_CH1 (OC1M = 110)
//    TIM2->CCMR1 |= (0x60);
//
////    TIM2->CCMR1 |= (1 << 3);    // Enable preload for TIM2_CH1
//    TIM2->CCMR1 |= (0x8);
//
//    TIM2->CCER |= (1 << 0);     // Enable output for TIM2_CH1
//
//    TIM2->CR1 |= (1 << 7);      // Enable auto-reload preload
//    TIM2->CR1 |= (1 << 0);      // Enable TIM2
//}
//
//void pwm_duty_cycle(uint16_t duty)
//{
//    TIM2->CCR1 = duty; // Direct assignment to the capture/compare register
//}
//
//int main()
//{
//    gpio_init();
//    tim2_pwm_init();
//
//    while (1)
//      {
//
//        for(int i=0; i<1000; i++)
//          {
//            pwm_duty_cycle(i);
//            delay(50);
//          }
//
//        for(int i=1000; i>0; i--)
//          {
//            pwm_duty_cycle(i);
//            delay(50);
//          }
//    }
//}

