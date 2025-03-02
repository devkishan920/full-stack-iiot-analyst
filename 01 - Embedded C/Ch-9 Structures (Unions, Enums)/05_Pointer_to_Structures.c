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
    struct employee e1; // creates a employee named e1
    struct employee *ptr; // create a pointer which POINTS the variable of (struct employee) type

    ptr = &e1;

    (*ptr).code = 101; // first (*ptr) is converted to (e1), then (e1.code) is assigned 101
    printf("%d\n",e1.code);

    // OR

    ptr->code = 103; // (->) is a Arrow operator, use to access structure properties. This makes the expression equivalent to above expression
    printf("%d",e1.code);

    strcpy(ptr->name,"Hello"),
    printf("%s",e1.name);
    
    return 0;
}