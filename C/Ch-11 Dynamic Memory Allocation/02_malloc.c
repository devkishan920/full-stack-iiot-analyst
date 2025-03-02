// malloc() - stands for MEMORY ALLOCATION
//          - alloctes size (in bytes) & returns a Void pointer to allocated memory.
//          - returns a NULL pointer if memory allocations fails
//          - syntax : void *malloc(size_t size);
//          - ex : (int *) malloc(30*sizeof(int));

#include<stdio.h>
#include<stdlib.h>

int main()
{
    
    printf("Size of (int) in my pc is %d bytes.\n",sizeof(int));
    printf("Size of (float) in my pc is %d bytes.\n",sizeof(float));
    printf("Size of (char) in my pc is %d bytes.\n",sizeof(char));

    int *ptr;   //integer type pointer 
    int n = 4;  // number of elements

    ptr = (int *)malloc(n * sizeof(int));

    // can be simply used as Array. With only differnce that memory is dynamically allocated

    for(int i=0; i<6; i++)
    {
        printf("Enter Element %d : ",i+1);
        scanf("%d",&ptr[i]);
    }

    printf("\n");

    for(int i=0; i<6; i++)
    {
        printf("Value of %d element is : %d\n",i+1, ptr[i]);
    }

    return 0;
}