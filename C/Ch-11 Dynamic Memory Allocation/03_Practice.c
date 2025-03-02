// WAP to create dynamic memory of 5 floats using malloc()

#include<stdio.h>
#include<stdlib.h>

int main()
{

    int n;
    float *ptr;

    printf("How many floating element you want to enter : ");
    scanf("%d",&n);

    ptr = (float *)malloc (n * sizeof(float));

    for(int i=0; i<n; i++)
    {
        printf("Enter value of element %d : ",i+1);
        scanf("%f",&ptr[i]);
    }

    for(int i=0; i<n; i++)
    {
        printf("Element %d is : %0.3f\n",i+1, ptr[i]);
    }
    return 0;
}