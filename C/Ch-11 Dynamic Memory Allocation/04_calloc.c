// calloc() - stands for CONTINUOUS ALLOCATION
//          - initialises every memory block with a default value of (0)
//          - alloctes size (in bytes) & returns a Void pointer to allocated memory.
//          - returns a NULL pointer if memory allocations fails
//          - syntax : void *calloc(nmemb, size_t size);
//          - ex : (int *) calloc(30, sizeof(int));

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr;
    ptr = (int *)calloc(5,sizeof(int));

    for(int i=0; i<5; i++)
    {
        printf("Value of Element %d : %d\n",i+1,ptr[i]);
    }
    
    return 0;
}