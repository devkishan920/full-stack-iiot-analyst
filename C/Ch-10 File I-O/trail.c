#include<stdio.h>
int main()
{
    FILE *ptr, *ptr2;
    ptr = fopen("fgetc.txt","r");
    ptr2 = fopen("trial.txt","w");
    
    int count = 0;

    char c;
    c = fgetc(ptr);

    while(c!=EOF)
    {
        fputc(c,ptr2);
        c = fgetc(ptr);
    }
    
    return 0;
}