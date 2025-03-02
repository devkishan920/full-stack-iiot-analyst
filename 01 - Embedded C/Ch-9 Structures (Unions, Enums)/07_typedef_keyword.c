//  Used to create an alias for datatypes in c
//  commonly used with structures

#include<stdio.h>
#include<string.h>

typedef struct employee
{
    int id;
    char name[20];
    float salary;
} emp;

int main()
{
    emp e1;
    emp *ptr;
    ptr = &e1;
    
    ptr->id = 101;
    ptr->salary = 19.01;
    strcpy(ptr->name,"Legend");

    printf("Id : %d\n",ptr->id);
    printf("Salary : %0.2f\n",ptr->salary);
    printf("Name : %s\n",ptr->name);
    
    return 0;
}