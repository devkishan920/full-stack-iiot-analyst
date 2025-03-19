// Q-1

// #include<stdio.h>
// #include<conio.h>
// int main()
// {
//     int arr[10];
// //    int *ptr = &arr[0]; //---|
//     int *ptr = arr;    //-----|We can use any one to point to first element of array.
    
//     ptr = ptr+2;

//     if (ptr == &arr[3])
//     {
//         printf("Points to the same location\n");
//     }

//     else
//     {
//         printf("Not points to the same location\n");
//     }
    
//     return 0;
// }

// Q-2 + Q-3

// #include<stdio.h>
// #include<conio.h>
// int main()
// {
//     int table[10] , n;

//     printf("Whose multipliction table you want to store : ");
//     scanf("%d",&n);

//     for (int i=0 ; i<10 ; i++)
//     {
//         table[i] = n*(i+1);
//     }

//     printf("Your table is \n");

//     for(int i=0 ; i<10 ; i++)
//     {
//         printf("%d X %d = %d\n",n,(i+1),table[i]) ;
//     }

//     return 0;
// }

// Q-5 Reversing the Array

// Method-1

// #include<stdio.h>
// #include<conio.h>
// int main()
// {
//     int n;
//     int arr[n]; 
    
//     printf("How many numbers you want to put in array : ");
//     scanf("%d",&n);

//     printf("Enter %d values : \n",n);

//     for(int i=0; i<n ;i++)
//     {
//         scanf("%d",&arr[i]);
//     }

//     printf("Array in reverse order is : \n");

//     for(int i=n-1; i>=0 ; i--)
//     {
//         printf("%d\t",arr[i]);
//     }

//     return 0;
// }

// Method-2

// #include<stdio.h>
// #include<conio.h>

// void reverse (int *arr , int n);

// int main()
// {
//     int arr[] = {1,2,3,4,5,6,7};
//     reverse(arr,7);

//     for(int i=0 ; i<7 ; i++)
//     {
//         printf("Value of %d element is : %d\n",i,arr[i]);
//     }

//     return 0;
// }

// void reverse (int *arr , int n)
// {
//     int temp;

//     for (int i=0 ; i<(n/2) ; i++)
//     {
//         temp = arr[i];
//         arr[i] = arr[n-i-1];
//         arr[n-i-1] = temp;    
//     }
    
// }

// Q-6

// #include<stdio.h>
// #include<conio.h>

// void positive(int *arr , int n);

// int main()
// {
//     int n;
//     int numbers[n]; // = {34,78,-65,89,-90,54,78,-34,-21,23,83};
    
//     printf("How many elements you want to enter : ");
//     scanf("%d",&n);

//     printf("Enter your %d elements : \n",n);
//     for (int i=0 ; i<n ; i++)
//     {
//         scanf("%d",&numbers[i]);
//     }
    
//     positive(numbers , n);
//     return 0;
// }

// void positive(int *arr , int n)
// {
//     int plus = 0;

//     for(int i=0 ; i<n ; i++)
//     {
//         if(arr[i]>0)
//         {
//             plus++;
//         }

//         else
//         {
//             int negative = 0;
//             negative++;
//         }
//     }
//     printf("Array consists of %d positive integers",plus);  
// }

// Q-7

// Method 1

// #include<stdio.h>
// #include<conio.h>
// int main()
// {
//     int mulTable[3][10];

//     for(int i=0 ; i<10 ; i++)
//     {
//         mulTable[0][i] = 2*(i+1);
//     }

//     for(int i=0 ; i<10 ; i++)
//     {
//         printf("2*%d = %d\n",(i+1),mulTable[0][i]);   
//     }

//     printf("\n");
        
//     for(int i=0 ; i<10 ; i++)
//     {
//         mulTable[0][i] = 7*(i+1);
//     }

//     for(int i=0 ; i<10 ; i++)
//     {
//         printf("7*%d = %d\n",(i+1),mulTable[0][i]);   
//     }

//     printf("\n");
    
//     for(int i=0 ; i<10 ; i++)
//     {
//         mulTable[0][i] = 9*(i+1);
//     }

//     for(int i=0 ; i<10 ; i++)
//     {
//         printf("9*%d = %d\n",(i+1),mulTable[0][i]);   
//     }    

//     printf("\n");
//     return 0;
// }

// Method 2

// #include<stdio.h>
// #include<conio.h>

// void printTable(int *arr, int num, int n);

// int main()
// {
//     int mulTable[3][10];

//     printTable(mulTable[0], 2, 10);
//     printTable(mulTable[1], 7, 10);
//     printTable(mulTable[2], 9, 10);
    
//     return 0;
// }

// void printTable(int *arr, int num, int n)
// {
//     printf("Table for %d is : \n",num);
    
//     for(int i=0 ; i<n ; i++)
//     {
//         arr[i] = num*(i+1);
//     }

//     for (int i=0; i<n ; i++)
//     {
//         printf("%d*%d = %d\n",num,(i+1),arr[i]);
//     }

//     printf("**************************************\n\n");
    
// }



// Q-9

#include<stdio.h>
#include<conio.h>
int main()
{
    int arr[2][3][4];

    for(int i=0 ; i<2 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            for(int k=0 ; k<4 ; k++)
            {
                printf("Address of arr[%d][%d][%d] is %u\n",i,j,k,&arr[i][j][k]);
            }
        }
    }
    return 0;
}

