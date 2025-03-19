// #include<stdio.h>
// #include<conio.h>
// int main()
// {
//     char *ptr1 = "Hello world";
//     char ptr2[] = "Welcome";

//     printf("%s ",ptr1);
//     puts(ptr2);

//     return 0;
// }

// Differnce b/w above both ways to declare the String.

#include<stdio.h>
#include<conio.h>
int main()
{
    char *ptr1 = "Hellow world";
    char  ptr2[] = "Welcome";

    ptr1 = "New wrold"; // string declared using Pointer (*ptr1) can be Reinitialised.
//  ptr2[] = "New user"; > It shows error, means string declared using Array (ptr2[]) can't be reinitialised 

    printf("%s ",ptr1);
    puts(ptr2);

    return 0;
}
