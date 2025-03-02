// Now we want to generate random number between 1 and 100


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>   
#include<time.h>     

int main()
{
    int number;
    srand(time(0));

    // number = rand()%100;   <--- helps in generating random number between 0 and 100
    // But we want ramdon number between 1 & 100 so we add 1 to above

     number = rand()%100+1;


    printf("The random number is %d",number);     
return 0;
}

// Entire logic for random number generator

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    srand(time(0));
    int num = rand();
    printf("Your random number is %d\n",num);

    num = num%100;
    printf("Your random number is %d\n",num);

    num = num+1;
    printf("Your random number is %d",num);
    return 0;
}