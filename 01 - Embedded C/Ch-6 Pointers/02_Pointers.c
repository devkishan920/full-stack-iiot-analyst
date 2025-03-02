#include<stdio.h>
#include<conio.h>
int main()
{
    int i = 34; 
    int *j;     // <---- Here we declare (j) as a Integer pointer
    j = &i;  // <---- this (j) Integer pointer will store the address of integer (i)

    // here (&) is a "Address of" operator. Used to obtain the address of given variable.

    printf("the value of i is %d\n",i);
    printf("the value of i is %d\n",*j);  // <---- Here (*j) is a "Value at Address" operator,i.e, it provides value from an address
    printf("the value of i is %d\n",*(&i));

    // "*" is "Value at Address" operator

    printf("\n"); 

    printf("the address of i is %u\n",&i);
    printf("the address of i is %u\n",j);

    printf("\n"); 

    printf("the value of j is %d\n",*(&j));
    printf("the address of j is %u\n",&j);

    printf("\n"); 

    return 0;
}

// #include<stdio.h>
// int main()
// {
//     int i=45;
//     int *j; // here a integer pointer (j) is ready to store integer variable address
//     j = &i; // now (j) is storing the address of integer (i)

//     printf("Value of (i) is %d\n",i);
//     printf("Value of (i) is %d\n",*j);

//     printf("\n");

//     printf("Address of (i) is %u\n",&i);
//     printf("Address of (i) is %u\n",j);
    
//     printf("\n");

//     printf("Address of (j) is %u\n",&j);
//     printf("Value of (j) is %d\n",*(&j));
    
//     return 0;
// }
