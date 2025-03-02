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
    struct employee e1 = {123, 34.56,"Dev"}; 
    printf("%d\n",e1.code);
    printf("%0.2f\n",e1.salary);
    printf("%s\n",e1.name);

    // Initialise all values from zero
    // struct employee e1 = {0}; // DOUBT
    struct employee e2 = {0}; 
    printf("%d\n",e2.code);
    printf("%0.2f\n",e2.salary);
    printf("%s\n",e2.name);

    return 0;
}