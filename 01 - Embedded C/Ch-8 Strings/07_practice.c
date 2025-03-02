#include<stdio.h>

void greeting1();
void greeting2();
void greeting3();

int main()
{
    printf("Example of function\n");
    greeting1();
    greeting2();
    greeting3();
    return 0;
}

void greeting1()
{
    printf("Good Morning\n");
}

void greeting2()
{
    printf("Good Afternoon\n");
}

void greeting3()
{
    printf("Good Night");
}