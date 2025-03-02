// fgetc : reads the file character by charcter

// fputc : writes the file character by charcter

#include<stdio.h>
int main()
{
    FILE *ptr;
    ptr = fopen("fgetc.txt","r");

    // reading the file character by character
    printf("Value of my character is : %c\n",fgetc(ptr));
    printf("Value of my character is : %c\n",fgetc(ptr));
    printf("Value of my character is : %c\n",fgetc(ptr));
    printf("Value of my character is : %c\n",fgetc(ptr));
    printf("Value of my character is : %c\n",fgetc(ptr));
    fclose(ptr);

    // writing the file, character by character
    ptr = fopen("fputc.txt","w");
    putc('n',ptr);
    putc('1',ptr);

    fclose(ptr);

    return 0;
}