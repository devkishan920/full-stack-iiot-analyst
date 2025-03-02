#include<stdio.h>
int main()
{
    int marks[4], i, *ptr;

    //ptr = &marks[0];   ----|
    ptr = marks;      // ----| Both performs same function., i.e, by-default holds address of first element of array
    // ptr = &marks; //  but this is illegal

    for(i=0; i<4; i++)
    {
    printf("Enter the marks for student %d : ",i+1);
    scanf("%d",ptr); // since (scanf) requires address so we passed (ptr) as it contains the address
    ptr++;
    }

    printf("\n");

    for(i=0 ; i<4 ; i++)
    {
    printf("Marks for student %d is %d\n",i+1,marks[i]);
    }
    return 0;
}



// #include<stdio.h>
// int main()
// {
//     int i, *ptr;
//     ptr = &i;

//     printf("Address of i is %u\n",&i);
//     printf("Address of i is %u\n",ptr);   
//     return 0;
// }