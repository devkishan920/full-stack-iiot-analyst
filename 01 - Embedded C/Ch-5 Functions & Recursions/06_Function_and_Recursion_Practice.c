// Find Average using function.

// #include<stdio.h>

// float average(int a, int b, int c);

// int main()
// {
//     int a,b,c;

//     printf("Enter three numbers whose average you want : ");
//     scanf(" %d %d %d",&a ,&b ,&c);

//     printf("Average of %d,%d & %d is %0.2f", a,b,c,average(a,b,c));
    
// return 0;
// }

// float average(int a, int b, int c)
// {
//     float result = (float)(a+b+c)/3;  
//     Here we typecast the integer result (a+b+c)/3 into float to get correct answer in decimals. As the result of int 
//     divide by int is also an (int). Wihtout typecasting use values(1,2,5).

//     return result;
// }


// Convert Degree Celsius to Degree Fahernheit.

// #include<stdio.h>

// float TempConvert(float t);  // here you do mistake that you didn't mention that 
//                              // value of which data type will this function return.  

// int main()
// {
//     float T;

//     printf("Enter your temperature in degree celsius : ");
//     scanf("%f",&T);

//     printf("Your temperature in degree Fahernheit is : %f",TempConvert(T));
    
// return 0;
// }

// float TempConvert(float t)    // here you do mistake that you didn't mention that 
//                               // value of which data type will this function return.  
// {
//    float Fahrenheit = (t*9)/5+32;
//    return Fahrenheit;
// }


// Calculate force due to gravitational pull (g=9.8)

// #include<stdio.h>
// #include<conio.h>

// float force(float mass);

// int main()
// {
//     float m;

//     printf("Enter the value of mass in kg : ");
//     scanf("%f",&m);
    
//     printf("The value of Force is %.2f Newton",force(m));  // here the (.2) we use in between % and f
//                                                            // helps to limit values upto two decimals
// return 0;
// }

// float force(float mass)
// {
//    float result = mass * 9.8;
//    return result;
// }

// Fibonacci Series using Recursion (Fibonacci Series : 0,1,1,2,3,5,8,13,21,34,....) <---- Keep trying to understand
// Fibonacci Series : fib(n-1) + fib(n-2)
// Base Condition : fib(1) = 0, Fib(2) = 1
// 0 1 1 2 3 5 8 13 21 34 55 89......
// #include<stdio.h>
// int fib(int n);
// int main()
// {
//     int n = 0;
//     printf("How many elements you want in Fibonacci series : ");
//     scanf("%d",&n);
//     printf("Your desired fibonacci series is : \n");
//     for(int i=1; i<=n; i++)
//     {
//         printf("%d\n",fib(i));
//     }
//     return 0;
// }

// int fib(int n)
// {
//     if(n==1)
//     {
//         return 0;
//     }

//     else if(n==2)
//     {
//         return 1;
//     }

//     else
//     {
//         return fib(n-1)+fib(n-2);
//     }
// }

// Sum of first (n) Natural number using Recursive function
// Hint : sum of first (n) natural number = sum of first (n-1) natural number + (nth) natural number

// #include<stdio.h>
// #include<conio.h>

// int Natural_sum(int n);


// int main()
// {
//   int n;

//   printf("Enter number till which you want sum of Natural number : ");
//   scanf("%d",&n);

//   printf("Sum of first %d Natural number is %d",n,Natural_sum(n));    
// return 0;
// }

// int Natural_sum(int n)
// {
//     if(n == 1)
//     {
//         return 1;
//     }

//     else if(n == 0)
//     {
        
//         printf("Is 0 a Natural number ???");  
//         return 0;
         
//     }

//     else if(n > 1)
//     {
//        int result = n + Natural_sum(n-1);
//        return result; 
//     }
// }

// Print following pattern for n-lines using Recursion   <---- DOUBT
// *
// * * *
// * * * * * 

// #include<stdio.h>
// #include<conio.h>

// void star_pattern(int n);  // <----- this function will return nothing DON'T MAKE SUCH MISTAKE AGAIN 

// int main()
// {
//   int n;  
//   printf("For how many lines you want to print the pattern : ");
//   scanf("%d",&n); 

//   star_pattern(n);
    
// return 0;
// }

// void star_pattern(int n)
// {
//   if(n == 1)
//   {
//     printf("*\n");
//     return;
//   }

//   star_pattern(n-1);
//   for (int i = 0 ; i < (2*n-1) ; i++)
//   {
//     printf("*");
//   }
//   printf("\n");  
// }


// Print following pattern for n-lines using Iteration (for loop)
// *
// * * *
// * * * * * 

// #include<stdio.h>
// int main()
// {
//     int n;
//     printf("How many pattern lines you want to print : ");
//     scanf("%d",&n);
//     for(int i=1; i<=n; i++)
//     {
//         for(int j=1; j<=2*i-1; j++)
//         {
//             printf("*");
//         }
//         printf("\n");
//     }
//     return 0;
// }