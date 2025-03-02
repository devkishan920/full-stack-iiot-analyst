// Create an array of Multiplicaton table of 7 (upto 7*10 = 70). Using realloc make it to store till (7*15 = 105)

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr, i;

    ptr = (int *)malloc(10 * sizeof(int));

    for(i=0; i<10; i++)
    {
        ptr[i] = 7*(i+1);
        printf("7*%d = %d\n",i+1,ptr[i]);
    }

    printf("\nAllocationg more space for 5 more elements\n");
    ptr = realloc(ptr, 15*sizeof(int));

    for(i=10; i<15; i++)
    {
        ptr[i] = 7*(i+1);
        printf("7*%d = %d\n",i+1,ptr[i]);
    }

    return 0;
}