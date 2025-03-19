#include "stm32f446xx.h"

uint32_t adc_read;


void adc1_in1_config()
{
  // Enable clock to Port, selected for ADC
  RCC->AHB1ENR |= (1<<0); // enable clock to Port A

  // Set ADC pin to Analog Mode (in this case PA1) ; PA0 is "Wakeup Pin" by default. Hence changing pin to PA1
  GPIOA->MODER &= ~(0x3 << (2*1));
  GPIOA->MODER |= (0x3 << (2*1)); // set pin to Analog Mode


  // Enable clock to ADC1
  RCC->APB2ENR |= (1<<8);

  // Turn off ADC1 - via control register 2
  ADC1->CR2 &= ~(1<<0);

  //   adjust result using (ALIGN) bit, conversion mode - using ADC_CR2 register.

//    ADC1->CR2 |= (0<<11); // right justified
  ADC1->CR2 |= (1<<1); // continuous mode

  // ----------------------------------------
  // set conversion sequence
  ADC1->SQR3 |= (1<<0);

  // set number of conversions or Conversion Sequence Length
  ADC1->SQR1 = (0x0000); // setting conversion sequence length to be 1
  // ----------------------------------------

  // Enable End of Conversion Interrupt
  ADC1->CR1 |= (1<<5);
  // Turn on ADC1 - via control register 2
  ADC1->CR2 |= (1<<0);

  NVIC_EnableIRQ(ADC_IRQn);
  ADC1->CR2 |= (1<<30); // Start ADC conversion using SWSTART bit
}

int main()
{
  adc1_in1_config();
  while(1)
    {

    }
}

//void ADC_IRQHandler()
//{
//  while(!(ADC1->SR & 1<<1))
//	{
//
//	}
//  adc_read = ADC1->DR;
//  ADC1->SR &= ~(1<<1); // Clear the end of conversion flag
//}

//		OR

void ADC_IRQHandler()
{
  if (ADC1->SR & (1<<1)) // Check if end of conversion flag is set
  {
     adc_read = ADC1->DR; // Read the ADC value
     ADC1->SR &= ~(1<<1); // Clear the end of conversion flag
  }
}
