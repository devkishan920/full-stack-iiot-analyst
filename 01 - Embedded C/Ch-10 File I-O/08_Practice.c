// Reading 3 integers from file

// #include<stdio.h>
// int main()
// {
//     FILE *ptr;
//     ptr = fopen("practice.txt","r");

//     int a, b, c;
//     fscanf(ptr, "%d %d %d",&a, &b, &c); // readinf the file
//     printf("Values are %d %d %d",a, b, c);
//     fclose(ptr);
//     return 0;
// }

// Write a table in file for number entered by user

// #include<stdio.h>
// int main()
// {
//     FILE *ptr;
//     ptr = fopen("table.txt","w");

//     int num;
//     printf("Which table you want : ");
//     scanf("%d",&num);

//     for(int i=0; i<10; i++)
//     {
//         fprintf(ptr, "%d * %d = %d\n",num, (i+1), (num*(i+1))); // writing the file
//     }

//     fclose(ptr);
//     return 0;
// }

// Copy content of file twice
// #include<stdio.h>
// int main()
// {
//     FILE *ptr, *ptr2;
//     ptr = fopen("fgetc.txt","r");
//     ptr2 = fopen("trial.txt","w");

//     char c;
//     c = fgetc(ptr);

//     while(c!=EOF)
//     {
//         fputc(c,ptr2);
//         fputc(c,ptr2);
//         c = fgetc(ptr);
//     }

//     return 0;
// }

// // Take name and salary of two employees, write it in text file as (name1,salary1)...

// #include<stdio.h>
// #include<string.h>

// struct employee
// {
//     char name[10];
//     int salary;
// };

// int main()
// {
//     struct employee e1, e2;

//     printf("Employee 1 Name : ");
//     scanf("%s",e1.name);
//     printf("Employee 1 Salary : ");
//     scanf("%d",&e1.salary);

//     printf("Employee 2 Name : ");
//     scanf("%s",e2.name);
//     printf("Employee 2 Salary : ");
//     scanf("%d",&e2.salary);

//     FILE *ptr;
//     ptr = fopen("Emp.txt","w");

//     fputs(e1.name, ptr);
//     fprintf(ptr, "\t%d\n", e1.salary);
//     fputs(e2.name, ptr);
//     fprintf(ptr, "\t%d", e2.salary);

//     fclose(ptr);

//     return 0;
// }

#include <stdio.h>
int main()
{
    FILE *ptr;
    char buff[100];

    ptr = fopen("test.txt", "r");

    fscanf(ptr, "%s", buff);
    printf("1 : %s\n", buff);

    fgets(buff, 255, ptr);
    printf("2: %s\n", buff);

    fgets(buff, 255, ptr);
    printf("3: %s\n", buff);
    fclose(ptr);

    return 0;
}