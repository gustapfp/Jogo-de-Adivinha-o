#include <stdio.h>
#include <string.h>

void greetings() {
    printf("**************************************\n");
    printf("  *  Welcome to the hangman game!  *  \n");
    printf("**************************************\n");
}

void new_guess(char word[26], int round) {
    char guess;
    printf("Choose a lether:");
    scanf(" %c", &guess);
    word[round] = guess;
}
int main() {

    greetings();

    char secret_word[20];
    sprintf(secret_word, "banana");
    
    // printf("%s", secret_word);
    
    int hanged = 0;
    int right_answer = 0;
    
    char word_guessed[26];
    int rounds = 0;

    do {

        for (int i = 0; i < strlen(secret_word); i++) {
            int finded = 0;

            for (int j=0; j < rounds; j++) {
                if (word_guessed[j] == secret_word[i]) {
                    finded = 1;
                    break;
                }
            }

            if (finded) {
                printf("%c ", secret_word[i]);
            } else {
                printf("_ ");
                }          
            }
        printf("\n");
        new_guess(word_guessed, rounds);
        rounds++;
        }while (!hanged && !right_answer);
    
    
    /*
    printf("You suggested a right letter! The lether %c are in the %d position of the secret world. :o \n", guess, i+1);
    secret_word[0] = "g";
    secret_word[1] = "u";
    secret_word[2] = "s";
    secret_word[3] = "t";
    secret_word[4] = "a";
    secret_word[5] = "v";
    secret_word[6] = "o";
    secret_word[7] = "\0";

    */

    
    
}