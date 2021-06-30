#include <stdio.h>
#include <string.h>

char secret_word[20];
char word_guessed[26];
int rounds = 0;

void greetings() {
    printf("**************************************\n");
    printf("  *  Welcome to the hangman game!  *  \n");
    printf("**************************************\n");
}

void new_guess() {
    char guess;
    printf("Choose a lether:");
    scanf(" %c", &guess);

    word_guessed[rounds] = guess;
    rounds++;
}

int check_guess(char letter) {
    int finded = 0;
    for (int j=0; j < rounds; j++) {
        if (word_guessed[j] == letter) {
            finded = 1;
            break;
        }
    } 
    return finded; 
} 

void hangman() {
    for (int i = 0; i < strlen(secret_word); i++) {           
        int finded = check_guess(secret_word[i]);
        if (finded) {
            printf("%c ", secret_word[i]);
        } else {
            printf("_ ");
        }      
    }
}

void choose_secret_word() {
    sprintf(secret_word, "banana");
}

int hanged() {
    int cont_wrong_guesses = 0; 

    for(int i = 0; i < rounds; i++) {
        int right_guess = 0;

        for(int j = 0; j < strlen(secret_word); j++) {

            if (word_guessed[i] == secret_word[j]) {
                right_guess = 1;
                break;
            } 
            
        }
        if (!right_guess) cont_wrong_guesses++;         
    }
    return  cont_wrong_guesses >= 5;
}

int main() {

    int right_answer = 0;
    
    choose_secret_word();
    greetings();

    
    do { 
        hangman();
        printf("\n");
        new_guess(word_guessed);
        } while (!hanged() && !right_answer);  
    
}