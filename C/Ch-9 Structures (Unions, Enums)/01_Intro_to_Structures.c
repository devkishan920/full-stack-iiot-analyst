// User defined data type

// Structures holds various data types

// Stored in contiguos memory location, i.e, elements of srtructure are stored adjacent to each other

// Method 1

#include<stdio.h>
#include<string.h>

// Syntax
struct employee // struct <structure name>
{
    int code;
    float salary;
    char name[10];
};

int main()
{
    struct employee e1; // Object creation of structure "employee"

    // Initialising Array
    e1.code = 100;
    e1.salary = 34.54;
    //e1.name = "Dev"; // Wont.t work, as it a character array, not character pointer
    strcpy(e1.name, "Dev");

    /*
    Here (.) is a "MEMBER Operator". Use to access the member of structure
    For ex - e1.code = 100, means set code value of (e1) to 100
    */

   printf("%d\n",e1.code);
   printf("%0.2f\n",e1.salary);
   printf("%s\n",e1.name);

    return 0;
}

//    OR

// #include<stdio.h>
// #include<string.h>

// // Syntax
// struct employee 
// {
//     int code;
//     float salary;
//     char name[10];
// }e1;    // Object Creation

// int main()
// {
//     e1.code = 100;
//     e1.salary = 34.54;
//     strcpy(e1.name, "Dev");

//    printf("%d\n",e1.code);
//    printf("%0.2f\n",e1.salary);
//    printf("%s\n",e1.name);

//     return 0;
// }


