//-----------------CALL BY REFERENCE-----------------//
// In this, instead of passing the arguments, we pass the address as argument. Hence value of variables (of main) can also be changed

#include<stdio.h>

// void wrong_swap(int a, int b);
void swap(int *a, int *b);

int main()
{
    int x=3 ,y=4;

    printf("The value of x and y before swap is %d and %d\n",x,y);

    // wrong_swap(x,y);

    swap(&x,&y); // This function works as it is Call by Refernce 
    printf("The value of x and y after swap is %d and %d\n",x,y);

    return 0;
}

// void wrong_swap(int a , int b)
// {
//   int temp;

//   temp = a;  
//   a = b;
//   b = temp;
// }

void swap(int *a , int*b)
{
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}