// Ch-3 : Conditional Statement

// // Q2

// #include<stdio.h>
// #include<conio.h>
// int main()
// {
//     int P,C,M,sum;
//     float totalPer;
//     printf("Enter marks of Physics\n");
//     scanf("%d",&P);

//     printf("Enter marks of Chemistry\n");
//     scanf("%d",&C);

//     printf("Enter marks of Maths\n");
//     scanf("%d",&M);

//     sum = P+C+M;
//     totalPer = (sum)*100/300;

//     if((totalPer<40) || (P<33) || (C<33) || (M<33))
//     {
//         printf("Your total percentage is %f\n",totalPer);
//         printf("You are fail");
//     }

//     else
//     {
//         printf("Your total percentage is %f\n",totalPer);
//         printf("You are pass");
//     }

// return 0;
// }

// // Q3

// #include<stdio.h>
// #include<conio.h>
// int main()
// {
//     int income, tax=0;

//     printf("Enter your income");
//     scanf("%d",&income);

//     if(income<250000)
//     {
//         printf("You need not to pay tax\n");
//     }

//     if((income>=250000) && (income<=500000))
//     {
//        tax = (income-250000) *5/100;
//     }

//     if((income>500000) && (income<=1000000))
//     {
//        tax = (income-250000) *20/100;
//     }

//     if(income>1000000)
//     {
//        tax = (income-250000)*30/100;
//     }

//      printf("you need to pay %d tax",tax);

//    return 0  ;
// }

// // Q4    Important

// #include <stdio.h>
// #include <conio.h>
// int main()
// {
//    int year;

//    printf("Enter your year : ");
//    scanf("%d", &year);

//    if ((year%4 == 0) && (year%100 == 0) && (year%400 == 0))
//    {
//       printf("year %d is a leap year\n", year);
//    }

//    else
//    {
//       printf("year %d is not a leap year\n", year);
//    }

//    // if (year % 4 == 0)
//    // {
//    //    if (year % 100 == 0)
//    //    {
//    //       if (year % 400 == 0)
//    //       {
//    //          printf("year %d is a leap year\n", year);
//    //       }
//    //    }
//    // }

//    // else
//    // {
//    //    if (year % 400 == 0)
//    //    {
//    //       printf("year %d is not a leap year\n", year);
//    //    }
//    // }

//    return 0;
// }

// ASCII (American Standard Code for Information Interchange) Code
// 65 - 90 --> A-Z
// 97 - 122 --> a-z

// Q-5 

#include<stdio.h>
#include<conio.h>
int main()
{
    char word;
    printf("Enter a character : ");
    scanf("%c",&word);

    if (word >= 97 && word <= 122)
    {
        printf("It is a Lowercase");
    }

    else
    {
        printf("It is a Uppercase");
    }
    return 0;
}