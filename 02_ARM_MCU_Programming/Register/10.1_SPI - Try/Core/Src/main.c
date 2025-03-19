#include "stm32f4xx.h"

void spi1_config()
{
  RCC->APB2ENR |= (1<<12); // enable clock to SPI1

  SPI1->CR1 |= (1<<0) | (1<<1);// setting clk phase and clk polarity - acc. to slave device

  SPI1->CR1 |= (1<<2); // master mode

  SPI1->CR1 |= (0x3 << 3);// setting baud rate to 5MHz - since apb2 running at 90MHz. so (90/16 ~ 5) - it's also acc. to slave device

  SPI1->CR1 &= ~(1<<7);// Set frame format - it's again ACC to slave device

  SPI1->CR1 |= (1<<9) | (1<<8); // using software slave management

  SPI1->CR1 &= ~(1<<10); // full duplex mode
  SPI1->CR1 &= ~(1<<11); // 8-bit data format

  SPI1->CR2 = 0; // since CR2 is for DMA and Interrupt purpose
}

// PA 5, 6, 7, 9 : SCK, MISO, MOSI, SS

void gpio_config()
{
  RCC->AHB1ENR |= (1<<0); // enable clock to port A

  GPIOA->MODER &= ~(0x3 << (2*5)) & ~(0x3 << (2*6)) & (~0x3 << (2*7)) & ~(0x3 << (2*9));

  GPIOA->MODER |= (2 << (2*5)) | (2 << (2*6)) | (2 << (2*7)) | (1 << (2*9));

  // ospeeder register to fast

  GPIOA->AFR[0] |= (5 << 20) | (5 << 24) | (5 << 28); // alternate function AF5
}

void spi1_enable()
{
  SPI1->CR1 |= (1<<6);
}

void spi1_disable()
{
  SPI1->CR1 &= ~(1<<6);
}

void cs_enable()
{
  GPIOA->ODR |= (1<<9);
}

void cs_disable()
{
  GPIOA->ODR &= ~(1<<9);
}

void spi1_transmit(uint8_t *data, int size)
{
  int i=0;

  while(i < size)
    {
      while(!(SPI1->SR & (1<<1))); // wait for TXE to set, i.e, wait till tx register is empty

      SPI1->DR = data[i]; // load data into Data register
      i++;
    }
//  During discontinuous communications, there is a 2 APB clock period delay between the write operation to the SPI_DR register and BSY bit setting. As a consequence it is mandatory to wait first until TXE is set and then until BSY is cleared after writing the last data.
  while(!(SPI1->SR & (1<<1))); // wait for txe bit to set
  while(SPI1->SR & (1<<7)); // wait for bsy bit to reset, i.e., SPI is not busy

  // clear overrun flag by reading DR and SR
  uint8_t temp=0;
  temp = SPI1->DR;
  temp = SPI1->SR;
}

void spi1_receive(uint8_t *data, int size)
{
  while(size)
    {
      while(SPI1->SR & (1<<7)); // wait for bsy bit to reset, i.e., SPI is not busy
      SPI1->DR = 0; // send dummy data
      while(!(SPI1->SR & (1<<0))); // wait for rxne bit to set, i.e., indicates RXNE bit not empty
      *data++ = (SPI1->DR);
      size--;
    }
}

void spi2_slave_config()
{
    RCC->AHB1ENR |= (1 << 1);      // Enable clock to port B
    GPIOB->MODER &= ~(0xFC000000); // Clear MODER PB 13,14,15
    GPIOB->MODER |= (0xA8000000);  // Set to Alternate mode for PB 13(SCK),14(MISO),15(MOSI)
    GPIOB->AFR[1] |= (0x55500000); // Set AF5 for PB 13,14,15

    RCC->APB1ENR |= (1 << 14); // Enable clock to SPI2

    SPI2->CR1 &= ~(1 << 2);  // Slave mode
    SPI2->CR1 &= ~(1 << 11); // 8-bit data frame
    SPI2->CR1 |= (1 << 6);   // Enable SPI2
}

char spi2_receive()
{
    while (!(SPI2->SR & (1 << 0))); // Wait till RXNE flag is set
    return SPI2->DR; // Receive data
}

uint8_t data[1] = {'a'};
uint8_t rx[1];
uint8_t new_rx[1];

/*
 * SPI1<---------->SPI2 (SCK),(MISO),(MOSI)
 * PA5 : SCK	: PB13
 * PA6 : MISO	: PB14
 * PA7 : MOSI	: PB15
 * PA9 : SS	:
 */


int main()
{
  gpio_config();
  spi1_config();
  spi1_enable();
  spi2_slave_config();
  while(1)
    {
      spi1_transmit(data, 1);
      rx[0] = spi2_receive();
      sprintf(rx, "%c", rx);
//      printf("%d",rx);
      printf("%c",rx);
    }
}
