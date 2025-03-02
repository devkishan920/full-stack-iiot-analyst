// Pointers : Special variables to hold the address of another variable stored in memory.

// ex - (j) points to (i), means (j) holds the address of (i).

// &
//  -   (Address of) operator
//  -   obtains address of given variable
//  -   (%u) format specifier is used to print address

//  *
//  -   (value at address) operator OR Dereferencing operator

#include<stdio.h>
int main()
{
    int a;
    printf("%u\n",&a); // (%u) is format spcifier which is used to obtain the address of variable (a) in Decimal format
    
    printf("%x",&a); // (%x) is format spcifier which is used to obtain the address of variable (a) in Hexa-Decimal format
    return 0;
}
