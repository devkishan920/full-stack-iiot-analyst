// Crate an array of size (n) using calloc, where (n) is an integer entered by user

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, n, *ptr;

    printf("How many elements you want to enter : ");
    scanf("%d",&n);

    ptr = (int *)calloc(n, sizeof(int));

    for(i=0; i<n; i++)
    {
        printf("Enter value of element %d : ",i+1);
        scanf("%d",&ptr[i]);
    }

    for(i=0; i<n; i++)
    {
        printf("Element %d is : %d\n",i+1, ptr[i]);
    }

    return 0;
}