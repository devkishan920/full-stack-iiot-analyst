#include "stm32f4xx.h"
#include "led.h"


//void delay(int seconds)
//{
//  for(int i=0; i<seconds; i++)
//    {
//      while(seconds>0)
//        {
//          seconds--;
//        }
//    }
//}



int main()
{
  gpio_init();

//  while(1)
//    {
      toggle(5);
      delay(1000);
//    }
}
