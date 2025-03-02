// Method 1

// #include<stdio.h>
// int main()
// {
//     // Ways of Initialising the String
//     char S[] = {'D','E','V','I','L','\0'};
//     char R[] = "Devil"; // In this case Null character is automatically added 

//     char *ptr1 = S; // ptr1 points to FIRST character element of string
    
//     char *ptr2 = R; // ptr2 points to FIRST character element of string

//     while(*ptr1 != '\0') // prints the string character by character.
//     {
//         printf("%c : ",*ptr1);
//         printf("%u\n",ptr1);
//         ptr1++;    
//     }  

//     printf("\n");

//     while(*ptr2 != '\0') 
//     {
//         printf("%c : ",*ptr2);
//         printf("%u\n",ptr2);
//         ptr2++;    
//     }

//     return 0;
// }

// Method 2

#include<stdio.h>
int main()
{
    char *string = "Welcome to C World"; // Here the compiler automatically converts the shown string into something like - {'D','E','V','I','L','\0'}, i.e, into single characters along with Null character.
    printf("%s\n",string);

    char s[] = "My name is Dev.";
    string = s;
    printf("%s\n",string);

    char r[] = "Living.";
    printf("%s",r);

    return 0;
}
