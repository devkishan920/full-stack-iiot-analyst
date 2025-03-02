// First use your c boiler plate code

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>   // (2)  <---- hence to solve warning in (1) we included this library which is required in 
                     // generation of random number. But after including this library it is still generating 41 as random number.   

#include<time.h>     // (4) <---- Hence to solve problem in (3) we included this library

int main()
{
    int number;
    srand(time(0)); // (3)  <----To solve problem (2) OR to make our program generate a new random number everytime
                    //   we initlalise the function srand() as shown. Time(0) means for every different value of time (in seconds) it would give diiferent random value.
                    // Here it generates random everytime but also gives warning that we didn't included the time library.          

    number = rand();      // rand() functions generates a random number
    printf("The random number is %d",number);     // (1)  if we use only function rand() it would only generate 41 as random number
                                                  // and also gives a warring that we not include the required library.
return 0;
}