// User defined data type. Used for better memory management.

// Similiar to Structures, i.e, holds various data types. 

// Only DIFFERENCE being, in STRUCTURE EACH MEMBER has its own storage location, while UNION USES SINGLE SHARED memory location. Hence "ONLY ONE ELEMENT IS ACCESSED AT A TIME."

// Total size of STRUCTURE is sum of size of individual element, whereas in case of UNION it is the maximum of all elements present

// Here also, (.) is a "MEMBER Operator", used to access the member of Union

// Method 1

// #include<stdio.h>
// #include<string.h>

// // Syntax
// union employee // union <structure name>
// {
//     int code;
//     float salary;
//     char name[10];
// };

// int main()
// {
//     union employee e1; // Object creation of union "employee"
//     printf("%d\n",sizeof(e1));

//     // Initialising Array
//     e1.salary = 34.54;
//     //e1.name = "Dev"; // Wont.t work, as it a character array, not character pointer
//     strcpy(e1.name, "Dev");
//     e1.code = 100;

//     /*
//     Here (.) is a "MEMBER Operator". Use to access the member of union
//     For ex - e1.code = 100, means set code value of (e1) to 100
//     */

//    printf("%d\n",e1.code);
//    printf("%s\n",e1.name);
//    printf("%0.2f\n",e1.salary);

//    // in Union if we try to access all elements at a time, the LAST INTIALISED elements is correctly accessed, while rest get corrupted.

//     return 0;
// }

//    OR

#include<stdio.h>
#include<string.h>

// Syntax
union employee 
{
    int code;
    float salary;
    char name[10];
}e1;    // Object Creation

int main()
{
    e1.code = 100;
    e1.salary = 34.54;
    strcpy(e1.name, "User");

   printf("%d\n",e1.code);
   printf("%0.2f\n",e1.salary);
   printf("%s\n",e1.name);

    return 0;
}


