#include <stdio.h>
int main()
{
    int *ptr = NULL;
    printf("The value of ptr is : %x\n", ptr);
    return 0;
}

// #include <stdio.h>
// int main()
// {
//     char str[45];
//     int len, i;

//     printf("\nEnter a string : ");

//     // following takes and prints till blank sapce
//     scanf(" %s", str);
//     printf("%s\n", str);

//     // following takes and prints including blank sapce
//     gets(str);
//     puts(str);

//     i = 0;
//     while (str[i])
//     {
//         ++len;
//         i++;
//     }

//     printf("String of length is %d", len);
//     return 0;
// }

// // Return array from function

// #include <stdio.h>
// /* function to generate and return random numbers */
// int *getRandom()
// {
//     static int r[10]; // C does not advocate to return the address of a local variable to outside  of  the function  so  you  would  have  to  define the  local  variable as static variable.
//     int i;

//     srand((unsigned)time(NULL)); /* set the seed */
//     for (i = 0; i < 10; ++i)
//     {
//         r[i] = rand();
//         printf("r[%d] = %d\n", i, r[i]);
//     }
//     return r;
// }

// int main()
// {
//     int *p; /* a pointer to an int */
//     int i;

//     p = getRandom();
//     for (i = 0; i < 10; i++)
//     {
//         printf("*(p + %d) : %d\n", i, *(p + i));
//     }
//     return 0;
// }

// #include <stdio.h>
// int main()
// {
//     short age[4];
//     int i;
//     0 [age] = 23;
//     1 [age] = 34;
//     2 [age] = 65;
//     3 [age] = 74;
//     for (i = 0; i < 4; i++)
//         printf("%d\n", i[age]);

//     return 0;
// }

// #include <stdio.h>
// int main()
// {
//     // int a[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
//     int a[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

//     for(int i=0; i<3; i++)
//     {
//         for(int j=0; j<4; j++)
//         {
//             printf("%3d",a[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }

// #include <stdio.h>
// int main()
// {
//     char name[5] = {'G', 'o', 'p', 's'};
//     char address[20] = "visakhapatnam";
//     char phoneno[] = "999999999";
//     /*accesing by charector by charector*/
//     printf("name= %c%c%c%c",name[0],name[1],name[2],name[3]);
//     printf("\naddress= %s",address);
//     printf("\nphoneno= %s",phoneno);
// }

// /* function definition to swap the values */
// void swap(int *x, int *y)
// {
//     int temp;
//     temp = *x; /* save the value at address x */
//     *x = *y;   /* put y into x */
//     *y = temp; /* put x into y */
//     return;
// }

// #include <stdio.h>
// /* function declaration */
// void swap(int *x, int *y);
// int main()
// {
//     /* local variable
//    definition */
//     int a = 100;
//     int b = 200;
//     printf("Before swap, value of a : %d\n", a);
//     printf("Before swap, value of b : %d\n", b);
//     /* calling a function to swap the values.
//     *&a indicates pointer to a ie. address of variable a
//    and &b indicates pointer to b ie. address of
//    variable b.
//     */
//     swap(&a, &b);
//     printf("After swap, value of a : %d\n", a);
//     printf("After swap, value of b : %d\n", b);
//     return 0;
// }
