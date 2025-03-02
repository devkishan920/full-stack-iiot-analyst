// There are two types of funtions:
// (i) Library Functions  
// (ii) User Defined Functions

// First write the basic structure of C structure

#include<stdio.h>

void display();   // <----   Function Prototype OR Function Declaration.  

void display()                     // ----|
{                                  //     | <----    Function Defination  
    printf("Hello I am Display");  //     |          we can define function at any place
}                                  // ----|

// Before making a function call at least either of Function defination or Function prototype
// must be present. Else it produces "Implicit Declaration Error"
int main()
{
    int a;

    display();    // <----    Function Call
    
    return 0;
}

// Control : This refers to code segment or code line which is being executed