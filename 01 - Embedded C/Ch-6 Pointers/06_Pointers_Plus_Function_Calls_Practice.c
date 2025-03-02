// Ch-6 Practice Set

// Q-1

// #include<stdio.h>
// #include<conio.h>
// int main()
// {
//  int a=5;  
//  int *b;

//  b = &a;
 
//  printf("Address of a is %u\n",&a);
//  printf("Address of a is %u\n",b);

//  printf("Value of a is %d\n",*b);
//  printf("Value of a is %d\n",a);
//  printf("Value of a is %d\n",*(&a));
//  return 0;
// }

// Q-2

// #include<stdio.h>
// #include<conio.h>

// void address(int x);

// int main()
// {
//  int i=8;

//  printf("Address of i is %u\n",&i);
//  address(i);
//  printf("Address of i is %u\n",&i);
   
//  return 0;
// }

// void address(int x)
// {
//   printf("Address of x is %u\n",&x); 
//   printf("Value of x is %d\n",x);  
// }

// // ADDRESS OF x AND i IS NOT SAME

// Q-3 DOUBT

// Wrong way

// #include<stdio.h>
// int tentimes(int *x);
// int main()
// {
//     int a = 5;
//     printf("Ten times of given vaule is : %d",tentimes(&a));
//     return 0;
// }

// int tentimes(int *x)
// {
//     int j = *(&x);
//     return (10*j);
// }

// Correct way

// #include<stdio.h>
// #include<conio.h>

// int multiply(int *x);

// int main()
// {
//     int a;
//     printf("Enter the number whose 10 time you want : ");
//     scanf("%d",&a);
//     printf("10 times of given number is %d",multiply(&a));
//     return 0;
// }

// int multiply(int *x)
// {
//   int d = *x;
//   int c = d * 10;
//   return c;
// }

// #include<stdio.h>
// void change(int *a);
// int main()
// {
//     int x=5;
//     change(&x);
//     printf("Value of x = %d",x);
//     return 0;
// }

// void change(int *a)
// {
//     *a = (*a) * 10;
// }

// Q-4 NICE, BEST, Power of Pointers

#include<stdio.h>
#include<conio.h>

void SumandAvg(int a , int b , int *sum , float *avg);

int main()
{
    int a,b,sum;
    float avg;

    printf("Enter the value of a,b = : ");
    scanf("%d %d",&a,&b);

    SumandAvg(a,b, &sum, &avg);

    printf("The value of sum is %d\n",sum);
    printf("The value of avg is %0.2f\n",avg);

    return 0;
}

void SumandAvg(int a , int b , int *sum , float *avg)   
// here we have a problem that with a function we can return only one thing either the sum or average
// So to return both sum and avg we peform as shown,
{
    // here we are decoding,i.e, getting values from function 
    *sum = a+b;
    *avg = (float)(*sum)/2;
}

// Q-5 ULTIMATE QUESTION

// #include<stdio.h>
// #include<conio.h>
// int main()
// {
//  int i , *a ,**b;

//  a = &i;
//  b = &a; 

//  printf("Enter the value of i : ");
//  scanf("%d",&i);

//  printf("The value of i %d",*(*b)); // we can say jitni decoding utne stars
  
//  return 0;
// }

// Q-6

// #include<stdio.h>
// #include<conio.h>

// int multiply(int a);

// int main()
// {
//  int a;

//  printf("Enter a number whose 10 time you want : ");
//  scanf("%d",&a);
//  multiply(a);
//  printf("10 times of your number is : %d",a);
//  return 0;
// }

// int multiply(int a)
// {
//   int d = a*10;
//   return d;
// }

// Hence proved that in call by value only a copy of variable is 
// passed hence no one can change the values inside the main body