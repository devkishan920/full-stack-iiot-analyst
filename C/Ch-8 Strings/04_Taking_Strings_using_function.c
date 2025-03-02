// Functions for taking inputs and printing outputs effectively ,i.e, along with Blank Spaces 

#include<stdio.h>
#include<conio.h>
int main()
{
    char Name[34];
    printf("Enter your Name : ");
    gets(Name);  // reads a multi-word string

    puts(Name); // Instead of using printf, we can use "puts()" function to print a string.
    
    // puts() also places the cursor at Next line.

    printf("Your Name is %s",Name);
    return 0;
}