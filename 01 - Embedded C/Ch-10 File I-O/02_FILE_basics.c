#include<stdio.h>
int main()
{
    FILE *ptr;
    ptr = fopen("sample.txt","r");
    //ptr = fopen("sample.txt","w");
    fclose(ptr); // Closing the file
    return 0;
}