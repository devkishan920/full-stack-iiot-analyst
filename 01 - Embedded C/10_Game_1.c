// #include <stdio.h>
// #include <conio.h>
// #include <stdlib.h>
// #include <time.h>

// int main()
// {
//    int number, guess, nguesses = 1;
//    srand(time(0));
//    number = rand() % 100 + 1;
//    // printf("The random number is %d\n",number);

//    do
//    {
//       printf("Guess a number : \n");
//       scanf("%d", &guess);

//       if (guess > number)
//       {
//          printf("your guess is big\n");
//       }

//       else if (guess < number)
//       {
//          printf("your guess is small\n");
//       }

//       else
//       {
//          printf("You guessed in %d attempts\n", nguesses);
//       }

//       nguesses++;

//    } while (guess != number); //  <---- this condition helps in terminating the game loop

//    return 0;
// }


// // Below which i practised using Function

// #include<stdio.h>
// #include<stdlib.h>
// #include<time.h>

// int randnum();
// int randnum()
// {
//     srand(time(0));
//     int num = rand();
//     //printf("Your random number is %d\n",num);

//     num = num%100;
//     //printf("Your random number is %d\n",num);

//     num = num+1;
//     //printf("Your random number is %d\n",num);

//     return num;
// }

// int main()
// {
//     int guess=0, num=randnum(), chances=0;
//  // printf("Random number is %d",num);

//     do
//     {
//         printf("Guess the number : ");
//         scanf("%d",&guess);
//         //printf("%d",num);
//         if(guess < num)
//         {
//             printf("Your guess is less than original number\n");
//             //chances = chances + 1;
//         }

//         else if(guess > num)
//         {
//             printf("Your guess is more than original number\n");
//             //chances = chances + 1;
//         }

//         else
//         {
//             printf("You got it right in %d guesses",chances);
//         }
//         chances++;
//     } while (guess != num);
    
        

//     return 0;
// }
