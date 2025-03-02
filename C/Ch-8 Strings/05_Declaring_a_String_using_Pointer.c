// #include<stdio.h>
// #include<conio.h>
// int main()
// {
//     char *ptr1 = "Devil is Dangerous Beast";
//     char ptr2[] = "And don't let him dominate me.";

//     printf("%s ",ptr1);
//     puts(ptr2);

//     return 0;
// }

// Differnce b/w above both ways to declare the String.

#include<stdio.h>
#include<conio.h>
int main()
{
    char *ptr1 = "Devil is Awesome";
    char  ptr2[] = "And don't let him dominate me.";

    ptr1 = "If it domintes it will not be good for you."; // string declared using Pointer (*ptr1) can be Reinitialised.
//  ptr2[] = "It will destroy everything and send everyone to HELL."; > It shows error, means string declared using Array (ptr2[]) can't be reinitialised 

    printf("%s ",ptr1);
    puts(ptr2);

    return 0;
}
