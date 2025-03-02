//-----------------CALL BY REFERENCE-----------------//
// In this, instead of passing the arguments, we pass the address as argument. Hence value of variables (of main) can also be changed

#include<stdio.h>

// void wrong_swap(int a, int b);
void swap(int *a, int *b);

int main()
{
    int x=3 ,y=4;

    printf("The value of x and y before swap is %d and %d\n",x,y);

    // wrong_swap(x,y); // This function does not works, as it is Call by Value and hence only a copy is being used in the function not the orginal ones.

    swap(&x,&y); // This function works as it is Call by Refernce and since address of original value is being used in the function and hence the orginal values can also be manipulated.

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