// #include<stdio.h>
// #include<conio.h>
// int main()
// {
//   printf("5 when divded by 2 leaves a remainder of %d\n",5%2);   //  
//   printf("-5 when divded by 2 leaves a remainder of %d\n",-5%2); // Because the sign of answer is similiar to the sign of Numerator. 
//   printf("5 when divded by -2 leaves a remainder of %d\n",5%-2); //
//   return 0;
// }


// Before running this program try to find the output by yourself.

#include<stdio.h>
#include<conio.h>
int main()
{
    int a=3;
    printf("%d %d %d",a,++a,a++);

    /*You will think that it will give output = 3,4,4
    but it will give other output. Run and check it. */
    return 0;
}

// Reason is that printf function takes argument from right to left (it depends on behaviour of compiler designed  
// by different manufacturer) ,i.e, (a++,++a,a) and returns in order (a,++a,a++). So, 

// ---- firstly, value (3) will be assigned to a++. Here it prints value of (a = 3) 
//      becomes (4) due to a++.

// ---- secondly, value (a = 4) will be assigned to ++a. Here (a) becomes (5) and 
//      prints value of (a = 5). 

// ---- finally,  value (a = 5) will be assigned to a. It simply prints value of (a = 5). 
// ---- And prints the values in given order.


// No operator is assumed to be PRESENT.


// In C language most of the compilers treat the decimal number as a DOUBLE datatype. For ex -
// float c = 78.9;  // hover the cursor over the number, it will represent DOUBLE.
// Because DOUBLE datatype is more Precise than FLOAT datatype.
     
// Type Conversion
// Any Arithematic operation between :
    // int and int returns int
    // int and float returns float
    // float and float returns float
    // for example

// #include<stdio.h>
// int main()
// {
//     int k = 3.0/9;
//     printf("result is %d\n",k);
//     printf("result is %f\n",k);

//     printf("\n");

//     float n = 3.0/9;
//     printf("result is %d\n",n);
//     printf("result is %f\n",n);

//     return 0;
// }

// Any Non-zero number is considered as TRUE.

// #include<stdio.h>
// void printpattern(int n);
// int main()
// {
//     int n;
//     printf("How many pattern lines you want to print : ");
//     scanf("%d",&n);
//     printpattern(n);
//     return 0;
// }

// void printpattern(int n)
// {
//     for(int i=1; i<=n; i++)
//     {
//         for(int j=0;j<(2*i-1);j++)  // important was the termination count
//         {
//             printf("*");
//         }
//         printf("\n");
//     }
// }

// Doubt

// #include<stdio.h>
// int main()
// {
//     int i,n,marks[i]; 
    
//     printf("How many student's marks you want to enter : ");
//     scanf("%d",&n);

//     for(i=0; i<n; i++)
//     {
//         printf("Enter the marks for student %d : ",i+1);
//         scanf("%d",&marks[i]);
//     }

//     for(i=0; i<n; i++)
//     {
//         printf("Marks for student %d : %d\n",i+1,marks[i]);
//     }
//     return 0;
// }