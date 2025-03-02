// Check wheter a file exists or not, before opening it.

#include<stdio.h>
int main()
{
    FILE *ptr;
    ptr = fopen("sample1.txt","r");

    if(ptr==NULL)
    {
        printf("File does not exists");
    }

    else
    {
        int num, num2;

        fscanf(ptr,"%d",&num);
        printf("Value of num is : %d\n",num);

        fscanf(ptr,"%d",&num2);
        printf("Value of num2 is : %d",num2);

        fclose(ptr); 
    }

    return 0;
}