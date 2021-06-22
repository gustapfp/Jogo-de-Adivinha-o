#include <stdio.h>

int main() {
    printf("****************************\n");
    printf("Welcome to the Guessing Game\n");
    printf("****************************\n");

    int secret_number = 27;

    printf("The secret number is: %d\n", secret_number);

    int guess; 
    int right_answer = (guess == secret_number);
    int high_right_answer = (guess < secret_number);
   
    
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

   for (int i=1; i<=3; i++)
    {
        printf("Guess the secret number:\n");
        scanf("%d", &guess); // %d to int's
        printf("Your guessed: %d \n ", guess);

        if (right_answer) {
        printf("Congratulations, you hit the secret number!\n");
        printf("Try again!\n");
        }
        else if(high_right_answer) {
            printf("What a drag, you choose a number higher than the secret number!\n");
            printf("Try again!\n");
        }
        else
        {
            printf("What a drag, you choose a number lesser than the secret number!\n"); 
            printf("Try again!\n");
        }
      
    }
    
}
    