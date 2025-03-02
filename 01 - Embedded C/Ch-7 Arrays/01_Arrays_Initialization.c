// Arrays : Collection of elements of SAME DATA TYPE. It is a continous block of memory location.

// In c language (generally), array indexing starts from (0) onwards to (n-1)

// #include<stdio.h>
// int main()
// {
//     int a[] = {45,56,67};
//     char c[] = {'q','b','v','t'};

//     printf("The value of a[0] is %d\n",a[0]);
//     printf("The value of a[1] is %d\n",a[1]);
//     printf("The value of a[2] is %d\n",a[2]);

//     printf("Character c[0] is %c\n",c[0]);
//     printf("Character c[1] is %c\n",c[1]);
//     printf("Character c[2] is %c\n",c[2]);
//     printf("Character c[3] is %c\n",c[3]); 
 
//     return 0;
// }

// #include<stdio.h>
// int main()
// {
//  int marks[3]; // here we declared an integer array MARKS which can store 4 values of same data type ,i.e, INTEGER
 
//  printf("Enter the value of marks for student 1 : ");
//  scanf("%d",&marks[0]);

//  printf("Enter the value of marks for student 2 : ");
//  scanf("%d",&marks[1]);

//  printf("Enter the value of marks for student 3 : ");
//  scanf("%d",&marks[2]);

//  printf("Enter the value of marks for student 4 : ");
//  scanf("%d",&marks[3]);

//  printf("Marks entered by you are\n %d\n %d\n %d\n %d\n",marks[0],marks[1],marks[2],marks[3]);

//  return 0;
// }

#include<stdio.h>
int main()
{

    int n, i;
    printf("For how many students you want to store the marks : ");
    scanf("%d",&n); 

    int marks[n];  

    for(i=0 ; i<n ; i++)
    {
        printf("Enter the value of marks for student %d : ",i+1);
        scanf("%d\n",&marks[i]);  
    }

    for(i=0 ; i<n ; i++)
    {
        printf("The value of marks for student %d is : %d\n",i+1,marks[i]); 
    }

    return 0;
}




