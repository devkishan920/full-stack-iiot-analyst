#include<stdio.h>
int main()
{
    FILE *ptr;
    ptr = fopen("sample.txt","w");

    int num = 46;
    fprintf(ptr,"Written number is %d\n",num);
    fprintf(ptr,"Thanks for usinf fprintf");

    fclose(ptr);

    return 0;
}