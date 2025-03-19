// Project : Number Guessing Game

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int check();

int original_n, chances = 4, flag, guess = 0, i, choice;

int main() {
    
    srand(time(0));
    original_n = (rand() % (500 - 1 + 1)) + 1; // (upper - lower + 1)) + lower
   
    printf("%d",original_n);
   
    do // loop continues for (chance+1) times
    {
        flag = check();
        
        if(flag==1)
        {
            printf("\nYou guessed it Right in %d turns !!!\n",i+1);
        }
        
        else
        {
            printf("\nYou exceeded the number of turns\n");
        }
        
        printf("\nWanna try again\n1 - Try again\n0 - Quit\n\n");
        scanf("%d",&choice);

        if(choice==1)
        {
            srand(time(0));
            original_n = (rand() % (500 - 1 + 1)) + 1; // (upper - lower + 1)) + lower
        }
        
    }while(choice == 1);
    
    if(choice==0)
    {
        if(flag==0)
        {
            printf("Correct number was %d\n",original_n);
        }

        printf("****Thanks for playing****");
    }
    
    return 0;
}

int check()
{
    printf("\nMakes a guess between 1 to 500  : ");
    scanf("%d",&guess);

    for(i=0; i<=chances; i++)
    {
        if ((guess==original_n) && (i<=chances))
        {
            return 1;
        }
        
        else if(guess>original_n)
        {
            printf("\nMake a small guess\n");
        }
        
        else
        {
            printf("\nMake a large guess\n");
        }
        
        while(i==chances)
        {
            return 0;
        }

        scanf("%d",&guess);
    }
}