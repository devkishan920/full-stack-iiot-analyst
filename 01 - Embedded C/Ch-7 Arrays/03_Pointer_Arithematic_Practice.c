#include<stdio.h>
#include<conio.h>
int main()
{
    int i=34;
    int *num;
    num = &i;
    printf("Value of num is %u\n",num);
    num++;
    printf("Value of num is %u\n",num);

    printf("\n");

    float f=34.85;
    float *point;
    point = &f;
    printf("Value of point is %u\n",point);
    point--;
    printf("Value of point is %u\n",point);

    printf("\n");    

    int c=45;
    int d=56;
    int *sym;
    int *sym1;
    sym = &c;
    sym1 = &d;
    printf("Value of sym is %u\n",sym);
    printf("Value of sym1 is %u\n",sym1);

    printf("\n");

    // In C, it is an illegal operation to perform add, sub, mul, div on Pointers 
    // printf("Addition of sym & sym1 is %u\n",sym+sym1); 

    return 0;
}