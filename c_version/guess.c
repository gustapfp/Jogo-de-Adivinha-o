#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//  #define NUMBER_OF_CHANCES 3 // number of the chances the user have to guess the righ number

int main() {
    printf("****************************\n");
    printf("Welcome to the Guessing Game\n");
    printf("****************************\n");

    int guess; 
    double lost_points;

    int seed_rand = time(0);
    srand(seed_rand);
    
    int secret_number = rand() % 100;
    double points = 1000.0;
    
    int difficult;
    printf("Choose the difficult of your game:\n");
    printf("Press: (1) Eazy |  (2) Medium | (3) Hard | (4) challenge:\n");
    scanf("%d", &difficult);
    
    // Select the difficult and the number of chances will have to guess the right number

    int attempts;

    switch (difficult)
    {
    case 1:
        attempts = 7; // eazy
        break;
    case 2:
        attempts = 5; // medium
        break;
    case 3: 
        attempts = 3; // hard
        break;
    case 4:
        attempts = 1; // challenge
        break;
    }    
    
    printf("The secret number is: %d\n", secret_number);
    int chances = attempts;
   for (int i=1; i<= attempts; i++)
    {
        printf("Guess the secret number: \n");
        printf("You still have %d chances and %.2f points left \n", chances, points)/
        scanf("%d", &guess); // %d to int's
        printf("You guessed: %d \n ", guess);

        int right_answer = (guess == secret_number);
        int bigger = (guess > secret_number);

        if (guess < 0) {
            printf("You can't guess a negative number.\n");
            i--; // To the for loop not count this interation
            continue;
        }

        if (right_answer) {
            printf("Congratulations, you guessed the secret number! :o\n");
            printf("You won the game with %d chances left and %.2f points! ;)\n", chances, points);
            break;
        }
        else if(bigger) {
            printf("What a drag, you choose a number higher than the secret number!\n");
            printf("Try again!\n");
            
        }
        else
        {
            printf("What a drag, you choose a number lesser than the secret number!\n"); 
            printf("Try again!\n");
            
        }
        chances -= 1;
        lost_points = ((double)guess - (double)right_answer) / 2.0;
        points = points - abs(lost_points);
      
    }
    int lose_game = (chances==0); 

    if (lose_game) {
        points = 0;
        printf("You lost! You don't have more chances and you finished the game with %.2f points! :(\n", points);
        printf("The Correct Number was:%d \n", secret_number);
    }
    
}
    