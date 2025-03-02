// Pointer to Pointer : Variable or Pointer which stores the address of pointer

// int *    :   pointer to a integer
// int **   :   pointer to a pointer to a intger

#include<stdio.h>
int main()
{
    int i = 37;
    int *j;     j = &i;     //  j = 87998
    int **k;    k = &j;     //  k = 88004

    printf("Value of i is %d\n",i);
    printf("Value of i is %d\n",*j);
    printf("Value of i is %d\n",*(&i));

    printf("\n");

    printf("Address of i is %u\n",&i);
    // printf("Address of i is %d\n",j); // bhai jab bhi address print karna ho, bhale hi kisi bhi (int) datatype variable mein store ho (%u) Format specifier is used
    printf("Address of i is %u\n",j);
    printf("Address of i is %u\n",*(&j));

    printf("\n");

    printf("Value of j is %d\n",j);
    printf("Value of j is %d\n",*k);
    printf("Value of j is %d\n",*(&j));

    printf("\n");

    printf("Address of j is %u\n",&j);
    printf("Address of j is %d\n",k);
    printf("Address of j is %d\n",*(&j));

    printf("\n");

    printf("Value of k is %d\n",k);
    printf("Value of k is %d\n",*(&j));

    printf("\n");

    printf("Address of k is %u\n",&k);

    return 0;
}