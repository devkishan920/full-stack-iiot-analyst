#include<stdio.h>
int main()
{
    char Name[20];

    printf("Enter your name : ");
    scanf("%s",Name);    // But with this Scanf, we can't accept blank spaces as input in Stings. 

    printf("Your Name is %s",Name);

    return 0;
}