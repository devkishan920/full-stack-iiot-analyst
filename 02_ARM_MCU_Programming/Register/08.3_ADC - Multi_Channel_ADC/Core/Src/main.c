#include"stm32f4xx.h"
#include <stdio.h>

uint32_t adc_val[2];

void delay(int n)
{
  while(n*1000 > 0)
    {
      n--;
    }
}

void adc_config()
{
  RCC->AHB1ENR |= (1<<0); // Port A Enabled

  GPIOA->MODER &= ~(0x3 << (2*1)) & ~(0x3 << (2*2) & ~(0x3 << (2*3)));
  GPIOA->MODER |= (0x3 << (2*1)) | (0x3 << (2*2)) | (0x3 << (2*3)); // Set to Analog Mode

  RCC->APB2ENR |= (1<<8); // ADC1 Enabled

//  ADC1->CCR |= (1<<16); // OPTIONAL - Set Prescaler to (/4)

  ADC1->CR2 &= ~(1<<0); // ADC Disabled
  ADC1->CR2 |= (1<<1); // Continuous Mode
  // Right Align by default

//  NEW----------------------------------------------
  // Resolution 12 bit by default
  ADC1->CR1 |= (1<<8); // Enable Scan Mode, since we are using Multi Channel

  ADC1->CR2 |= (1<<10); // Enable EOCS : End of Conversion Selection

  // Select Sample Timer using SMPR - 000 by default

  // Configure/Decide number of Channels
  ADC1->SQR1 |= (1<<20); // Set for 2 channels

//  ---------------------------------------------

  ADC1->CR2 |= (1<<0); // ADC Enabled

}

void adc_start(int channel)
{
  ADC1->SQR3 = 0;
  ADC1->SQR3 |= (channel << 0); // Setting Channel Sequence -- putting one channel at a time

  ADC1->SR = 0;

  ADC1->CR2 |= (1<<30);
}

uint16_t wait_read()
{
  while(!(ADC1->SR & 1<<1))
	{

	}
  return ADC1->DR;
}


int main()
{
  adc_config();

  while(1)
    {
      adc_start(1); // started ADC for Channel 1
      adc_val[0] = wait_read();

      delay(1000);

      adc_start(2); // started ADC for Channel 2
      adc_val[1] = wait_read();

    }
}
