// #include<stdio.h>
// #include<conio.h>
// #include<math.h>    // to perform any mathematical operation we need to include the following library
// void main()
// {
//     // pow(a,b) returns a double number i.e, a real number, so we use %f format specifer
   
//    printf("5 raised to 4 is %f\n", pow(5,4)); // (\n) is a Escape Sequence Character

// }

//WAP to check whether given number is divisible by 97 or not
// (%) is Modular Division Operator, i.e, returns remainder

#include<stdio.h>
#include<conio.h>
int main()
{
    int a;
    printf("Enter your number\n");
    scanf("%d",&a);

    printf("The Divisibility test returns remainder to be %d", a%97);
return 0;
}