// Ch-4 : Loop Control Instruction

// Our loop counter can be a Integer or Float also
// WHILE LOOP
// This first checks the condition and then execute the loop

#include<stdio.h>
#include<conio.h>
int main()
{
    int a = 0;    // Initialization & Declaration

    while(a<10)    // Condition
    {
        printf("%d\n",a);   // Command to be executed
        a++;       // Increament or Decreament     
    }
return 0;
}

//  Ch-4 While Loop Quiz

#include<stdio.h>
#include<conio.h>
int main()
{
    int i = 0;

    while(i<=20)
    {
        if(i>=10)
        {
            printf("%d\n",i);
        }
       i++;  
    }

return 0;
}

// Increament & Decreament Operator

#include<stdio.h>
#include<conio.h>
void main()
{
    int i = 5;
    printf("The vlaue of i is %d\n",i++); // --> this first prints the vlaue and then increase or decrease the value

    i = 5;
    printf("The value of i is %d\n",++i); // --> this first increase or decrease the value and then prints the vlaue

}

// Compound Assignment Operator
// a+=10 --> a = a+10;
// a-=10 --> a = a-10;
// a*=10 --> a = a*10;
// a/=10 --> a = a/10;

// DO WHILE LOOP
// This loop first executes the code, irrespective of condition and then CHECK the CONDITION, i.e this loop is executed atleast ONCE

#include<stdio.h>
#include<conio.h>
int main()
{
    int a = 0;              // Initialization & Declaration
    do
    {
        printf("%d\n",a);   // Code to be Executed
        a++;                // Increament or Decreament 
    }while (a<10); // <------- this semi-colon is necressary.   Condition

return 0;
}   

// do while loop is used in desiginig menus of games

// Ch-4 Do-While Loop Quiz

#include<stdio.h>
#include<conio.h>
void main()
{
    int a = 1,n;

    printf("How many nautral numbers you want to print : ");
    scanf("%d",&n);

    do
    {
        printf("%d\n",a);
        a++;
    }while (a<=n);
}


// Printing numbers in reverse order using For loop

#include<stdio.h>
#include<conio.h>
void main()
{
    int n,i;

    printf("From which number you want the reverse order : ");
    scanf("%d",&n);

    printf("Your required reverse order is\n");

    //  initialize ; condition ; inc/dec
    for (i=n;i;i--) // here the at condition block only (i) is written. And the here i want to stop loop when condition becomes false.
                    // And any false is repersented as 0.    
                    // Any non-zero number is TRUE.
    {
        printf("%d\n",i);
    }
}

// BREAK STATEMENT 
// This statement is used to EXIT the loop irrespective of CONDITION. 

#include<stdio.h>
#include<conio.h>
int main()
{
    int i=0;

    while(i<10)
    {
        printf("%d\n",i+1);
        i++;
        
        if(i==5)
        {
            break;
        }
    }
    return 0;
}

// CONTINUE STATMENT    <--- Need More Practice
// This ignores what is written below (continue) makes the loop to restart.
// ,i.e, skips the particular iteration of the loop

#include<stdio.h>
#include<conio.h>
int main()
{
    int skip = 5; // Don't get CONFUSE by Variable NAMES
    int i=0;

    while(i<10)
    {
        i++;

        if(i!=skip)
        {
            continue;  // -----> this CONTINUE statement makes a particular iteration repeat again & again acc. to condition
        }

        else
        {
            printf("%d\n",i);
        }
    }
return 0;
}
