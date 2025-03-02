// // Conditional Operator (?:) --> It is a short form of if-else conditional operator. 
// // Also called Ternary Operator. 

// #include<stdio.h>
// #include<conio.h>

// int main()
// {
//     int a;
//     printf("Enter the value of a\n");
//     scanf("%d",&a);
  
//    //Syntax : (Condition) ? (result when condition is true) : (result when condition is false )
//    // It is a One Liner if-else conditonal operator
//    (a<5) ? printf("a is less than 5") : printf("a is more than 5");   
//    return 0;
// }

// // SWITCH Case Control Instruction

// #include<stdio.h>
// #include<conio.h>
// int main()
// {
//     int rating;
//     printf("Enter your rating b/w 1-5 : ");
//     scanf("%d",&rating);

//     switch (rating) // it only takes Integer,Character expression
//     {
//         case 1:
//         printf("Your Rating is 1");
//         break; 
//         // if we don't use break then it would execute all cases

//         case 2:
//         printf("Your Rating is 2");
//         break;

//         case 3:
//         printf("Your Rating is 3");
//         break;

//         case 4:
//         printf("Your Rating is 4");
//         break;    

//         case 5:
//         printf("Your Rating is 5");
//         break;
    
//         default:
//         printf("Invalid Rating");
//         break;
//     }

//     return 0;
// }

// // WAP to find the grade of student based on following marking system. 

// // 90 - 100 --> A
// // 80 - 90 --> B
// // 70 - 80 --> C
// // 60 - 70 --> D
// // Less than 60 --> F

#include<stdio.h>
#include<conio.h>
int main()
{ 
    int marks;
    printf("Enter your Marks : ");
    scanf("%d",&marks);

    switch (marks)
    {
        case 50:
        printf("Your got D Grade");
        break;

        case 70:
        printf("Your got C Grade");
        break;

        case 80:
        printf("Your got B Grade");
        break;

        case 90:
        printf("Your got A Grade");
        break;

        default:
        printf("Your got F Grade");
        break;
    }
    return 0;
}
