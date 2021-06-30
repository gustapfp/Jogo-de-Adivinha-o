#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "hangman.h"

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

// void cant_open_file(f) {
//     if (f==0) {
//         printf("Sorry, appears we are having some problems trying to open the file\n\n");
//         exit(1);
//     }
// }
void add_new_word() {
    char want;
    printf("You want to add a new word on our base [Y/N]?\n");
    scanf(" %c",&want);

    if (want == 'y' || want == 'Y') {
        char new_word[20];
        printf("Write the new word: ");
        scanf("%s", new_word);

        FILE* f;
        f = fopen("words_list.txt", "r+");
        if (f==0) {
        printf("Sorry, appears we are having some problems trying to open the file\n\n");
        exit(1);
        }
        
        int number_of_words;
        fscanf(f, "%d", &number_of_words);
        number_of_words++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", number_of_words);


        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", new_word);

        fclose(f);

    }
}
void choose_secret_word() {
    FILE* f;
    f = fopen("words_list.txt", "r");
    if (f==0) {
        printf("Sorry, appears we are having some problems trying to open the file\n\n");
        exit(1);
    }

    int number_of_words;
    fscanf(f, "%d", &number_of_words);
    
    srand(time(0));
    
    int random = rand() % number_of_words;

    for(int i = 0; i <= random; i++) {
        fscanf(f, "%s", secret_word);
    }
    fclose(f);
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

int win() {
    for(int i = 0; strlen(secret_word); i++) {
        if(!check_guess(secret_word[i])) {
            return 0;}
    }
    return 1;
}

int main() {

    choose_secret_word();
    greetings();

    
    do { 
        hangman();
        printf("\n");
        new_guess(word_guessed);
        } while (!hanged() && !win());  
    
    add_new_word();
    
}