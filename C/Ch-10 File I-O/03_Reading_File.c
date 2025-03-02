#include<stdio.h>
int main()
{
    FILE *ptr;
    ptr = fopen("sample.txt","r");

    int num, num2;

    fscanf(ptr,"%d",&num);
    printf("Value of num is : %d\n",num);

    fscanf(ptr,"%d",&num2);
    printf("Value of num2 is : %d",num2);

    fclose(ptr); // Closing a file is a good pratice
    
    return 0;
}