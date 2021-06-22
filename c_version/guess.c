#include <stdio.h>

int main() {
    printf("****************************\n");
    printf("Welcome to the Guessing Game\n");
    printf("****************************\n");

    int secret_number = 27;

    printf("The secret number is: %d\n", secret_number);

    int guess; 
    printf("Guess the secret number:\n");
    scanf("%d", &guess); // %d to int's
    printf("Your guess is: %d and the secret number was: %d\n ", guess, secret_number);
    if (guess == secret_number) {
        printf("Congratulations, you hit the secret number!\n");
        printf("Try again!\n");
    }
    else if(guess > secret_number) {
        printf("What a bag you choose a number higher than the secret number!\n"); //  The Correct Number was:%d \n", secret_number);
        printf("Try again!\n");
    }
    else if (guess < secret_number)
    {
        printf("What a bag you choose a number lesser than the secret number!\n"); //  The Correct Number was:%d \n", secret_number);
        printf("Try again!\n");
    }
    
    
    
    
    
}
    