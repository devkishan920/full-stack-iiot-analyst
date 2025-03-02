// Function defined in C, calling itself is known as Recursion.

// Recursion : Function ke andar wahi function.

// Fatorial using Recursion

#include<stdio.h>

int factorial(int x);    // Creating Factorial function with parameter (x)

int main()
{
  int a;
  printf("Enter the number whose factorial you want : ");
  scanf("%d",&a);

  printf("Factorial of %d is %d",a,factorial(a)); // <---- Here the factorial function is called for input value (a)
  return 0;
}

int factorial(int x)   //  <---- Here  value of (a) is passed to int (x) . This is defined factorial function 
{
  // printf("Calling factorial of (%d)\n",x);

  if(x == 1 || x == 0)  //Base Condition : Doesn't call the function in recursive manner.
                        // i.e, Stops the Recursion
  {
    return 1;
  }  

  // since factorial (n) =  1 x 2 x 3 x 4 x.......x n
  // then  factorial (n) =  1 x 2 x 3 x 4 x.....(n-1) x n
  // hence factorial (n) =  factorial(n-1) x n   

  else
  {
    int f = x * factorial(x-1);  // <---- Here the factorial function is calling itself for (x-1)
    return f; 
  }
}

