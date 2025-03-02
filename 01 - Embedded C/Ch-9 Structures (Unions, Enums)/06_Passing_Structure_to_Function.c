#include<stdio.h>
#include<string.h>

struct employee
{
    int id;
    char name[20];
    float salary;
};

void show(struct employee e)
{
    printf("Id : %d\n",e.id);
    printf("Name : %s\n",e.name);
    printf("Salary : %0.2f\n",e.salary);
}

int main()
{
    struct employee e1;
    struct employee *ptr;
    ptr = &e1;
    
    ptr->id = 101;
    ptr->salary = 19.01;
    strcpy(ptr->name,"Legend");

    show(e1);

    struct employee e2 = {234, "Leon", 34.45};
    show(e2);

    return 0;
}
