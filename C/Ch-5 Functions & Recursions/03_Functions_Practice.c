// Ch-5 Quick Quiz

// Ex - 1

// #include<stdio.h>
// #include<conio.h>

// void Morning();
// void Afternoon();
// void Evening();

// void main()
// {
//     printf("Hello this is practice of Functions\n");
    
//     Morning();
//     Afternoon();
//     Evening();

//     printf("Thanks Function for making the task easier\n");

// 
// }

// void Morning()
// {
//     printf("Good Morning !!\n");
// }

// void Afternoon()
// {
//     printf("Good Afternoon !!\n");
// }

// void Evening()
// {
//     printf("Good Evening !!\n");
// }


// Ex - 2 (Function inside Function)

// We can call the function indirectly also OR by function inside function call


// #include<stdio.h>
// #include<conio.h>

// void Morning();
// void Afternoon();
// void Evening();

// int main()
// {
//     printf("Hello this is practice of Functions\n");
    
//     Morning();
    

//     printf("Thanks Function for making the task easier\n");

// return 0;
// }

// void Morning()
// {
//     printf("Good Morning !!\n");
//     Afternoon();
    
// }

// void Afternoon()
// {
//     printf("Good Afternoon !!\n");
//     Evening();
// }

// void Evening()
// {
//     printf("Good Evening !!\n");
// }


// Ex - 3

#include<stdio.h>
#include<math.h>

int sq_area(int side);

int main()
{
    int side;
    printf("Enter the value of side : ");
    scanf("%d",&side);
    printf("Area is %d",sq_area(side));
    return 0;
}

int sq_area(int side)
{
    return pow(side,2); // (pow) retuns a double type value
}


