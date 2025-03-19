#include "stm32f4xx.h"

void delay(int n)
{
  int temp;
  for(int i=0; i<n; i++)
    {
      temp = n;
      while(temp>0)
        {
          temp--;
        }
    }
}

void LCD_command(char command)
{
  GPIOB->ODR &= ~(1<<5); // RS LOW
  GPIOB->ODR &= ~(1<<6); // R/W LOW
  delay(500);

  GPIOC->ODR = command;

  GPIOB->ODR |= (1<<7); // EN HIGH
  delay(200);
  GPIOB->ODR &= ~(1<<7); // EN LOW
  delay(1000);
}

void LCD_data(char data)
{
  GPIOB->ODR |= (1<<5); // RS HIGH
  GPIOB->ODR &= ~(1<<6); // R/W LOW
  delay(500);

  GPIOC->ODR = data;

  GPIOB->ODR |= (1<<7); // EN HIGH
  delay(200);
  GPIOB->ODR &= ~(1<<7); // EN LOW
  delay(1000);
}

void LCD_init()
{
//  LCD_command(0x30);
//  delay(10);
//  LCD_command(0x30);
//  delay(1);
//  LCD_command(0x30);
  LCD_command(0x38); /*set 8-bit data, 2-line, 5x8 font */

//  LCD_command(0x06); /*move cursor right after each char */
  LCD_command(0x01); /*clear screen, move cursor to home */
  LCD_command(0x0F); /*turn on display, cursor blinking */
}
/* PC0-PC7 for LCD D0-D7, respectively. */
/* PB5 for LCD R/S */
/* PB6 for LCD R/W */
/* PB7 for LCD EN */





int main()
{
  RCC->AHB1ENR |= (0x6);

  GPIOB->MODER &= ~(0xFFFF);
  GPIOB->MODER |= (0x5400);

  GPIOC->MODER &= ~(0xFFFF);
  GPIOC->MODER |= (0x5555);

  GPIOB->ODR &= ~(1<<6); // R/W LOW
  GPIOB->ODR &= ~(1<<7); // EN LOW

  //	  custom special characters
  	  char cc1[] = {0x00, 0x00, 0x0A, 0x00,0x11, 0x0E, 0x00, 0x00};
  	char cc2[] = {
  	  0x04,
  	  0x04,
  	  0x0A,
  	  0x0A,
  	  0x0A,
  	  0x0A,
  	  0x04,
  	  0x00
  	};

  	char cc3[] = {
  	  0x00,
  	  0x10,
  	  0x18,
  	  0x1E,
  	  0x1E,
  	  0x1F,
  	  0x00,
  	  0x00
  	};

  	char cc4[] = {
  	  0x00,
  	  0x01,
  	  0x03,
  	  0x07,
  	  0x0F,
  	  0x1F,
  	  0x00,
  	  0x00
  	};

  	char cc5[] = {
  	  0x00,
  	  0x01,
  	  0x03,
  	  0x07,
  	  0x0F,
  	  0x1F,
  	  0x00,
  	  0x00
  	};

  	char cc6[] = {
  	  0x10,
  	  0x18,
  	  0x15,
  	  0x13,
  	  0x13,
  	  0x12,
  	  0x0C,
  	  0x00
  	};

  	char cc7[] = {
  	  0x01,
  	  0x03,
  	  0x15,
  	  0x19,
  	  0x19,
  	  0x09,
  	  0x06,
  	  0x00
  	};



  //	  saving custom character in CGRAM
  	  LCD_command(0x40); // staring address of CGRAM
  	  for(int i=0; i<8; i++)
  	    {
  	      LCD_data(cc1[i]);
  	    }

  	  LCD_command(0x40+8); // staring address of CGRAM
  	  for(int i=0; i<8; i++)
  	    {
  	      LCD_data(cc2[i]);
  	    }

  	  LCD_command(0x40+16); // staring address of CGRAM
  	  for(int i=0; i<8; i++)
  	    {
  	      LCD_data(cc3[i]);
  	    }

  	  LCD_command(0x40+24); // staring address of CGRAM
  	  for(int i=0; i<8; i++)
  	    {
  	      LCD_data(cc4[i]);
  	    }

  	  LCD_command(0x40+32); // staring address of CGRAM
  	  for(int i=0; i<8; i++)
  	    {
  	      LCD_data(cc5[i]);
  	    }

  	  LCD_command(0x40+40); // staring address of CGRAM
  	  for(int i=0; i<8; i++)
  	    {
  	      LCD_data(cc6[i]);
  	    }

  	  LCD_command(0x40+48); // staring address of CGRAM
  	  for(int i=0; i<8; i++)
  	    {
  	      LCD_data(cc7[i]);
  	    }
  LCD_init();

//	  pre-defined special characters
	  LCD_data(0xE2);
	  LCD_data(0x14);
	  LCD_data(0xE0);

	  LCD_data(0);
	  LCD_data(1);
	  LCD_data(2);
	  LCD_data(3);
	  LCD_data(4);
	  LCD_data(5);

}
