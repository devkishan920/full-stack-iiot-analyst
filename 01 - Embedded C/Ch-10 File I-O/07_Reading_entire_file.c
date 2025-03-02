/**EOF : End of FIle**/
//  detects End of File  
// (fgetc) retruns EOF when all characters of file have been read.

#include<stdio.h>
int main()
{
    FILE *ptr;
    ptr = fopen("fgetc.txt","r");

    char c;
    int count = 0;
    c = fgetc(ptr);
    while(c!=EOF)
    {
        printf("%c",c);
        c = fgetc(ptr);
        count++;
    }

    printf("%d",count);

    return 0;
}