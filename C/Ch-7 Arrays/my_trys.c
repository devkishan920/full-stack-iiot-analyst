// #include<stdio.h>

// void show(int arr[][], int row, int column);

// int main()
// {
//     int row=2, column=4, i, j, arr[row][column];

//     for(i=0; i<row; i++)
//     {
//        for(j=0; j<row; j++) 
//        {
//             printf("Enter element for row %d column %d",i+1,j+1);
//             scanf("%d",&arr[i][j]);
//        }
//     }

//     show(arr, row, column);
//     return 0;
// }

// void show(int arr[][], int row, int column)
// {
//     for(int i=0; i<row; i++)
//     {
//        for(int j=0; j<row; j++) 
//        {
//             printf("Enter element for row %d column %d : %d",i+1,j+1,arr[i][j]);
//        }
//     }
// }

#include <stdio.h>

void show(int arr[][4], int row, int column);

int main()
{
    int row = 2, column = 4, i, j, arr[2][4];

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            printf("Enter element for row %d column %d: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }

    show(arr, row, column);
    return 0;
}

void show(int arr[][4], int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            // printf("Element at row %d column %d: %d\n", i + 1, j + 1, arr[i][j]);
            printf("%3d",arr[i][j]);
        }
        printf("\n");
    }
}
