// (=) is a Assignment Operator.

#include<stdio.h>
#include<conio.h>
#include<math.h>


int main()    
{
    int side;
    
    printf("Enter the side of square : ");
    scanf("%d",&side);

    printf("Area of square is %f", pow(side,2));
    
    return 0;  
}