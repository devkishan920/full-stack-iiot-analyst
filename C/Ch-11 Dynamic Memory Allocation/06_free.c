// free() - de-alloctes the allocated memory (either by malloc() or calloc()).
//          - syntax : void *free(void *ptr);
//          - ex : free(ptr);

#include<stdio.h>
#include<stdlib.h>

int main()
{

    int *ptr; 

    for(int i=0; i<600; i++)
    {
        ptr = (int *)malloc(6000 * sizeof(int));
        printf("Enter Element %d : ",i+1);
        scanf("%d",&ptr[i]);
        free(ptr);
    }

    return 0;
}