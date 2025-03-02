// realloc() - reallocates more memory in previously dynamically allocated memory. Simply saying, allocates memory of new size using previous pointer and size
//          - initialises every memory block with a default value of (0)
//          - alloctes size (in bytes) & returns a Void pointer to allocated memory.
//          - returns a NULL pointer if memory allocations fails
//          - syntax : void realloc(void *ptr, size_t size);
//          - ex : realloc(ptr, n*sizeof(int));

#include<stdio.h>
#include<stdlib.h>

int main()
{

    int *ptr;    
    int n = 4;  

    ptr = (int *)malloc(n * sizeof(int));

    for(int i=0; i<4; i++)
    {
        printf("Enter Element %d : ",i+1);
        scanf("%d",&ptr[i]);
    }

    for(int i=0; i<4; i++)
    {
        printf("Value of %d element is : %d\n",i+1, ptr[i]);
    }

    //Reallocation of ptr
    ptr = realloc(ptr, 10*sizeof(int));

    for(int i=4; i<10; i++)
    {
        printf("Enter Element %d : ",i+1);
        scanf("%d",&ptr[i]);
    }

    for(int i=0; i<10; i++)
    {
        printf("Value of %d element is : %d\n",i+1, ptr[i]);
    }

    return 0;
} 