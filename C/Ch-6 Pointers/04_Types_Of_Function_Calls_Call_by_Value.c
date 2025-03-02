//--------------------CALL BY VALUE--------------------//
// This function only and only calls the copy of arguments (value given to parameters) 
// Using the (User defined) function we can't change the variables of main OR original values (given to parameters)

#include<stdio.h>

int sum (int a, int b);

int main()
{
   int x=3 , y=4;

   printf("Value of x and y before call is %d and %d \n",x,y);
   printf("The sum of 3+4 is %d \n",sum(x,y)); 
   printf("Value of x and y after call is %d and %d \n",x,y);    

   return 0;
}

int sum (int a, int b) //---------| 
{                      //         |
   return a+b;         //         |
   a = 45675;          //         |----->>> This is a good conceptualthing LOOK IT !!! USE IT !!!
   b = 34906869;       //         |
   // return a+b;       //---------|
}


