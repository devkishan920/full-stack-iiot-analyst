// #include<stdio.h>
// #include<conio.h>
// #include<string.h>

// int main()
// {
//     char *str = "Hello world";
//     int a = strlen(str); // Counts the no. of character in String, EXCLUDING the Null Character
//     printf("Length of string is %d",a);
//     return 0;
// }

// Creating our own Strlen() Function.

#include<stdio.h>
#include<conio.h>

int String_len(char *str);

int main()
{
    int a;
    char str[50];
    
    printf("Enter your string : ");
    gets(str);

    printf("Length of String is %d",String_len(str));

    return 0;
}

int String_len(char *str)
{
    int a=0;

    while(*str != '\0')
    {
        a++;
        str++;
    }
    return a;
}
