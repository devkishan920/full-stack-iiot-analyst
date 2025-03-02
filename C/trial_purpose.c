// Using I2C1 - PB6(SCL), PB7(SDA), AF4

#include "stm32f4xx.h"

void i2c1_init()
{
  RCC->AHB1ENR |= (1 << 1); // enable clock to port B

  GPIOB->MODER &= ~(0xF000);
  GPIOB->MODER |= (0xA000);

  GPIOB->AFR[0] |= (0x44000000);

  RCC->AHB1ENR |= (1 << 21);

  /* PB8, PB9 I2C1 SCL, SDA */

  GPIOB->OTYPER |= 0x00000300; /* output open-drain */
  GPIOB->PUPDR &= ~0x000F0000; /* with pull-ups */
  GPIOB->PUPDR |= 0x00050000;
  /* this funtion writes a byte of data to the memory location maddr
  of
  I2C1->CR1 = 0x8000;
  /* software reset I2C1 */
  I2C1->CR1 &= ~0x8000; /* out of reset */ 
  I2C1->CR2 = 0x0010; /* peripheral clock is 16 MHz*/
  I2C1->CCR = 80;    /* standard mode, 100kHz clock */
  I2C1->TRISE = 17; /* maximum rise time */
  I2C1->CR1 |= 0x0001; /* enable I2C1 module */
}
