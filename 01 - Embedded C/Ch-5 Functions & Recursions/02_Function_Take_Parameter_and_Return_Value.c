#include<stdio.h>

int sum(int a , int b);   //  <----- Function Prototype Declaration
                          //  here a & b are parameters (place holders for values of a & b) 

void main()                 
// variables declared in sum function and main function
// are totally different, independent of each other.
{         
    int result;
    result = sum(34,45);              //  <----- Function Call. Actual values given to a function (here 34 & 45) are called "Arguments". Only a copy of these values(34 & 45) is passed to the funtions. Hence, functions can't change the original values.  
                                       
    printf("the sum is %d ",result);
}

int sum(int a , int b)   //-----|
{                        //     | 
   int result;           //     |  -----> Function Defination    
   result = a+b;         //     |
   return result;        //     |
}                        //-----| 

