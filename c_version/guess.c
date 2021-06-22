#include <stdio.h>
#define NUMBER_OF_CHANCES 3 // number of the chances the user have to guess the righ number

int main() {
    printf("****************************\n");
    printf("Welcome to the Guessing Game\n");
    printf("****************************\n");

    int guess; 
    int lost_points;
    
    int secret_number = 27;
    int attempts = NUMBER_OF_CHANCES;  // number of chances the user still have
    int points = 1000;

    printf("The secret number is: %d\n", secret_number);
   
    
    // and the secret number was: %d\n ", guess, secret_number);
    /* while loop version:
    int counter = 0;
    while (counter < 3)
    {
        printf("Guess the secret number:\n");
        scanf("%d", &guess); // %d to int's
        printf("Your guessed: %d \n ", guess);

        if (right_answer) {
        printf("Congratulations, you hit the secret number!\n");
        printf("Try again!\n");
        break;
        }
        else if(high_right_answer) {
            printf("What a drag, you choose a number higher than the secret number!\n"); //  The Correct Number was:%d \n", secret_number);
            printf("Try again!\n");
        }
        else
        {
            printf("What a drag, you choose a number lesser than the secret number!\n"); //  The Correct Number was:%d \n", secret_number);
            printf("Try again!\n");
        }
        counter = counter + 1;
        
    }
    */
   // for version

   for (int i=1; i<= NUMBER_OF_CHANCES; i++)
    {
        printf("Guess the secret number: \n");
        printf("You still have %d chances and %d points left \n", attempts, points)/
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
            printf("You won the game with %d chances left and %d points! ;)\n", attempts, points);
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
        attempts -= 1;
        lost_points = (guess - right_answer) / 2;
        points = points - lost_points;
      
    }
    int lose_game = (attempts==0); 

    if (lose_game) {
        points = 0;
        printf("You lost! You don't have more chances and you finished the game with %d points! :(\n", points);
        printf("The Correct Number was:%d \n", secret_number);
    }
    
}
    