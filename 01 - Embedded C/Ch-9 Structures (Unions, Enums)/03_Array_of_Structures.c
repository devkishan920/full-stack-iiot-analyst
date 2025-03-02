#include<stdio.h>
#include<string.h>

struct employee 
{
    int code;
    float salary;
    char name[10];
};

int main()
{
    struct employee facebook[100]; // Array of Structure named "facebook"

    facebook[0].code = 100;
    facebook[0].salary = 10.90;
    strcpy(facebook[0].name,"Hello");

    facebook[1].code = 200;
    facebook[1].salary = 17.90;
    strcpy(facebook[1].name,"Hello1");

    facebook[2].code = 140;
    facebook[2].salary = 210.90;
    strcpy(facebook[2].name,"Hello2");

    return 0;
}