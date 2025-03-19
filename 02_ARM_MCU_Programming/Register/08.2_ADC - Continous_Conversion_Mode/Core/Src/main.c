// Choose ADC - ADC1
// Choose Channel (simply the pin on which adc conversion) - Ch1 ; see pin description table [ADC being a Additional Functionality] : PA1; // not using PA0

#include "stm32f446xx.h"

uint32_t adc_read;

void gpio_init() // Step 1
{
  // Enable clock to Port, selected for ADC
  RCC->AHB1ENR |= (1<<0); // enable clock to Port A

  // Set ADC pin to Analog Mode (in this case PA1) ; PA0 is "Wakeup Pin" by default. Hence changing pin to PA1
  GPIOA->MODER &= ~(0x3 << (2*1));
  GPIOA->MODER |= (0x3 << (2*1)); // set pin to Analog Mode
}


void adc1_in1_config() // Step 2
{
  // Enable clock to ADC1
  RCC->APB2ENR |= (1<<8);

  // Turn off ADC1 - via control register 2
  ADC1->CR2 &= ~(1<<0);

  //   adjust result using (ALIGN) bit, conversion mode - using ADC_CR2 register.

  ADC1->CR2 |= (0<<11); // right justified (by default)
  ADC1->CR2 |= (1<<1); // continuous mode

  // ----------------------------------------
  // set conversion sequence
  ADC1->SQR3 |= (1<<0);

  // set number of conversions or Conversion Sequence Length
  ADC1->SQR1 = (0x0000); // setting conversion sequence length to be 1
  // ----------------------------------------

  // Turn on ADC1 - via control register 2
  ADC1->CR2 |= (1<<0);

  // Step 3 - Start the ADC conversion ONCE
   ADC1->CR2 |= (1<<30); // using SWSTART bit
}

int main()
{
  gpio_init();
  adc1_in1_config();
  while(1)
    {
      // Step 4 - Wait/Check for Conversion completion - EOC bit (bit 1) in Status register
      while(!(ADC1->SR & 1<<1))
	{

	}

      // Step 5 - Read the converted data
      adc_read = ADC1->DR;
    }
}
