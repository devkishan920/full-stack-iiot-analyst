// 2D Vector using Structure
// #include<stdio.h>

// struct vector
// {
//     int x, y;
// };

// int main()
// {
//     struct vector v1, v2;
//     v1.x = 34;  v2.x = 45;
//     v1.y = 4;  v2.y = 5;

//     printf("For V1, X dim is %d & Y dim is %d\n",v1.x, v1.y);
//     printf("For V2, X dim is %d & Y dim is %d\n",v2.x, v2.y);
//     return 0;
// }

// Pass above two vectors to function and return theri sum (DOUBT)

// #include<stdio.h>

// struct vector
// {
//     int x, y;
// };

// int sum(int, int);

// int sum(int a, int b)
// {
//     return (a+b);
// }

// int main()
// {
//     struct vector v1, v2;
//     v1.x = 34;  v2.x = 45;
//     v1.y = 4;  v2.y = 5;

//     printf("Sum : %d",sum(v1.x, v1.y));
//     return 0;
// }

// WAP using Arrow Operator

// #include<stdio.h>
// #include<string.h>

// struct employee 
// {
//     int id;
//     char name[20];
//     float salary;
// };

// int main()
// {
//     struct employee e1;
//     struct employee *ptr;
//     ptr = &e1;

//     e1.id = 234;
//     strcpy(e1.name,"New");
//     e1.salary = 23.74;

//     printf("ID : %d\n",e1.id);
//     printf("ID : %d\n",(*ptr).id);
//     printf("ID : %d\n",ptr->id);

//     printf("Name : %s\n",e1.name);
//     printf("Name : %s\n",(*ptr).name);
//     printf("Name : %s\n",ptr->name);

//     printf("Salary : %f\n",e1.salary);
//     printf("Salary : %f\n",(*ptr).salary);
//     printf("Salary : %f\n",ptr->salary);

//     return 0;
// }

 