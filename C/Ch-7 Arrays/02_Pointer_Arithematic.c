#include<stdio.h>
int main()
{
    int i=30; // int takes memory space of 4 bit.
    int *ptr;
    ptr = &i;

    char c='a'; // char takes memory space of 1 bit.
    char *sym;
    sym = &c;

    printf("The address of i is %u\n",&i); 
    printf("The address of i is %u\n",ptr);
    printf("The value of ptr is %u\n",ptr);
    ptr++; // since (ptr) is a integer type POINTER. So,this will increase the value of ADDRESS of integer by (i.e. 4 bit) in prviously stored value. 
    
    // ptr--;
    printf("\n");

    //printf("The value of ptr is %d\n",ptr);  // this is wrong. It will not print the value inside ptr. We NEED to use (%u) as value inside ptr is an address

    printf("The value of ptr is %u\n",ptr);
    printf("The address of i is %u\n",ptr); 
    printf("\n");

    printf("Value of sym is %u\n",sym);
    sym++;
    printf("Value of sym is %u\n",sym);

    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    // ptr = &arr; // gives some warning
    ptr = arr; // this holds the address of FIRST element of array
    printf("Value of ptr is %u\n",ptr);

    printf("\nAddress of first element of array is : %u\n",&arr);
    printf("Value of first element is %d\n",arr[0]);

    ptr++; // now, (ptr) pointing to next integer element
    printf("Value of second element is %d\n",*ptr);

    return 0;
}