//2-d Array - Like a table, i.e., Rows and Column

// #include <stdio.h>
// int main()
// {
//     int n_Students = 4;
//     int n_Subject = 3;

//     int marks[n_Students][n_Subject]; // here we created an 2-D Array, i.e., Rows and Column

//     for (int i=0; i<n_Students; i++)
//     {
//         for (int j=0; j<n_Subject; j++)
//         {
//             printf("Enter the marks of student %d for subject %d : \n", i + 1, j + 1);
//             scanf("%d", &marks[i][j]);
//         }
//     }

//     for (int i=0; i<n_Students; i++)
//     {
//         for (int j=0; j<n_Subject; j++)
//         {
//             printf("The marks of student %d for subject %d is : %d\n", i + 1, j + 1, marks[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }

// 3-D Array

#include <stdio.h>
int main()
{
    int n_school = 4;
    int n_student = 3;
    int n_subject = 5;
    int marks[4][3][5];

    for(int i=0 ; i<4; i++)
    {
        for(int j=0; j<3; j++)
        {
            for (int k=0 ; k<5; k++)
            {
                printf("Enter the marks for student %d of School %d for subject %d :\n",j+1,i+1,k+1);
                scanf("%d",&marks[i][j][k]);
            }
            
        }
    }

        
    for(int i=0 ; i<4; i++)
    {
        for(int j=0; j<3; j++)
        {
            for (int k=0 ; k<5; k++)
            {
                printf("The marks for student %d of School %d for subject %d is %d\n",j+1,i+1,k+1,marks[i][j][k]);
            }
            
        }
    }
    return 0;
}

// Quick Quiz

// #include<stdio.h>

// void display(int arr[], int n, int o);

// int main()
// {
//     int state =2;
//     int price = 2;
//     int bill[2][2];

//     for (int i=0; i<2 ; i++)
//     {
//         for (int j=0; j<2; j++)
//         {
//             printf("Enter the dal price %d for state %d : \n",j+1,i+1);
//             scanf("%d",&bill[i][j]);
//         }
        
//     }
    
//     display(bill,state,price);

//     return 0;
// }

// void display(int arr[], int n, int o)
// {
//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<o ; j++)
//         {
//             printf("%d\t",arr[i]);
//         }
        
//     }    
// }