#include<stdio.h>

int sum(int a , int b);   //  <----- Function Prototype Declaration
                          //  here a & b are parameters (place holders for values of a & b) 

void main()                 

{         
    int result;
    result = sum(34,45);                                                    
    printf("the sum is %d ",result);
}

int sum(int a , int b)   // Function Defination 
{                         
   int result;               
   result = a+b;         
   return result;        
}                         

