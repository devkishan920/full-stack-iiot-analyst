// WAP to store the details of 3 employees from user defined data.

#include<stdio.h>
#include<string.h>

struct employee
{
    char name[10];
    int id;
    float salary;
};

int main()
{
    // struct employee e1;
    // struct employee e2;
    // struct employee e3;
    //  OR
    struct employee e1, e2, e3; // ab kitna e1, e2, e3... type karenge. Hence, we go for Array of Structure

    printf("Enter name of e1 : ");
    scanf("%s",e1.name);
    printf("Enter id of e1 : ");
    scanf("%d",&e1.id);
    printf("Enter salary of e1 : ");
    scanf("%f",&e1.salary);

    printf("\n");

    printf("Enter name of e2 : ");
    scanf("%s",e2.name);
    printf("Enter id of e2 : ");
    scanf("%d",&e2.id);
    printf("Enter salary of e2 : ");
    scanf("%f",&e2.salary);

    printf("\n");

    printf("Enter name of e3 : ");
    scanf("%s",e3.name);
    printf("Enter id of e3 : ");
    scanf("%d",&e3.id);
    printf("Enter salary of e3 : ");
    scanf("%f",&e3.salary);

    return 0;
}

