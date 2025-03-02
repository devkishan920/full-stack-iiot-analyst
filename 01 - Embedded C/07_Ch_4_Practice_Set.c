// Q-1

// #include<stdio.h>
// #include<conio.h>
// int main()
// {
//   int n,i,c,sum=0;

//   do
//   {
//   printf("Whose multiplication table you want : ");
//   scanf("%d",&n);

//   printf("Your required table for %d is\n",n);

//   for(i=1 ; i<=10; i++)
//   {
//    printf("%d * %d = %d\n",n,i,n*i);  
//   }


//   printf("Wanna Retry 1/0 ?? : ");
//   scanf("%d",&c);
  
//   } while (c == 1);
  
    
// return 0;
// }


// Q-7 

// #include<stdio.h>
// int main()
// {
//     int n, i=0, sum=0;
//     printf("Enter number whose sum fo multiplication you want : ");
//     scanf("%d",&n);

//     while(i<=10)
//     {
//         printf("%d*%d = %d\n",n,i,n*i);
//         sum = sum + n*i;
//         i++;
//     }

//     printf("Sum of Multiplication is %d",sum);
//     return 0;
// }

// Q-9 Factorial by While Loops

// #include<stdio.h>
// #include<conio.h>
// void main()
// {
//   int i=1,n,fact=1;

//   printf("Enter no whose factorial you want : ");
//   scanf("%d",&n);

//   while(i<=n)
//   {
//     fact*=i;
//     i++;
//   }

//   printf("Your rquired factorial for %d is %d",n,fact);
// 
// }

// Q-10 Check whether a given number is prime or not, using loops

// #include<stdio.h>
// #include<conio.h>
// int main()
// {
//   int n,i,prime=1;

//   printf("Enter number whose prime check you want : ");
//   scanf("%d",&n);

//   for  (i = 2; i < n; i++)
//   {
//     if (n%i == 0 && n!=2) //----> we use n!=2 as our loops starts from 2 ,
//                          //it will give remainder  of 0 and say 2 is not a prime.
//     {
//       prime = 0;
//       break;
//     }
    
//   }

//   if(prime == 0)
//   {
//     printf("%d is not Prime",n);
//   }
  
//   else
//   {
//     printf("%d is Prime",n);
//   }
// return 0;
// }