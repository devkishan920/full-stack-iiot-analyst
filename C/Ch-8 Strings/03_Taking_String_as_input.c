#include<stdio.h>
int main()
{
    char Name[20];

    printf("Enter your name : ");
    scanf("%s",Name); // Since we need the address of First position, "Name" is itself an Array so no need to use (&) before Name in scanf

    // Scanf automatically enters the Null Character at end of string when ENTER key is pressed.
    
    // But with this Scanf, we can't accept blank spaces as input in Stings. 

    printf("Your Name is %s",Name);

    return 0;
}