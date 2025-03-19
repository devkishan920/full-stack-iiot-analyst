/*
 * led.c
 *
 *  Created on: Dec 29, 2024
 *      Author: Dev Kishan Prajapat
 */
#include "stm32f4xx.h"

void delay(int n)
{
	int i;
	for (; n > 0; n--)
		for (i = 0; i < 3195; i++);
}

void toggle(int n)
{
  while(n>0)
    {
      GPIOA->ODR |= (1<<5);
      delay(200);
      GPIOA->ODR &= ~(1<<5);
      delay(200);
      n--;
    }
}

void gpio_init()
{
  RCC->AHB1ENR |= (1<<0);

  GPIOA->MODER &= ~(1<<(2*5));
  GPIOA->MODER |= (1<<(2*5));
}


