// // -------------------------------------------------------------------------------
// Way - 1 Formal parameters as a pointer 

// void myFunction(int *param)
// {
// }

// Way - 2 Formal parameters as a sized array 

// void myFunction(int param[10])
// {
// }

// Way - 3 Formal parameters as an unsized array 

// void myFunction(int param[])
// {
// }
// // ---------------------------------------------------------------------------------

// AGAIN TAKE A CLOSE LOOK. IT IS A VERY GOOD PROGRAM

// Method 1

// #include<stdio.h>

// void printArray(int *ptr , int n);

// int main()
// {
//   int array[] = {23,34,45,56,67,78,89,90};
//   printArray(array , 8);
//   return 0;
// }

// void printArray(int *ptr , int n)
// {
//   for(int i=0 ; i<n ; i++)
//   {
//     printf("Value of element %d is %d\n",i+1,*(ptr+i));  // *(ptr+i) esliye so that with every iteration, our pointer should point to next location.

//     // Agar sirf (*ptr), to next line mein ptr++ karte;
//   }
// }

// Method 2

#include <stdio.h>

void printArray(int ptr[], int n);

int main()
{
  int array[] = {23, 34, 45, 56, 67, 78, 89, 90};
  printArray(array, 8); // here we called the (printArray) function and passed the array and it'size

  for (int i = 0; i < 8; i++)
  {
    printf("the %d element of array is %d\n", i + 1, array[i]);
  }
  return 0;
}

void printArray(int ptr[], int n) // the information passed in above is accepted here. The array is accepted by the ptr, inturn accesses the address of each element of array.  BUT HOW ??? !!!!
{
  for (int i = 0; i < n; i++)
  {
    printf("Value of element %d is %d\n", i + 1, ptr[i]);
  }
  ptr[2] = 5555; // this will change the third element of array with 5555 in main function also
}


// double getAverage(int arr[], int size)
// {
//   int i;
//   double avg;
//   double sum;
//   for (i = 0; i < size; ++i)
//   {
//     sum += arr[i];
//   }
//   avg = sum / size;
//   return avg;
// }

// #include <stdio.h>
// /* function declaration */
// double getAverage(int arr[], int size);
// int main()
// {
//   /* an int array with 5 elements */
//   int balance[5] = {1000, 2, 3, 17, 50};
//   double avg;
//   /* pass pointer to the array as an
//  argument */
//   avg = getAverage(balance, 5);
//   /* output the returned value */
//   printf("Average value is: %f ", avg);
//   return 0;
// }