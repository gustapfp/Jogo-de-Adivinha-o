#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "hangman.h"

char secret_word[WORD_SIZE];
char word_guessed[26];
int rounds = 0;

int letter_exist(char letter) {

    for(int j = 0; j < strlen(secret_word); j++) {
        if(letter == secret_word[j]) {
            return 1;
        }
    }
    return 0;
}

int mistakes() {
    int cont_wrong_guesses = 0; 

    for(int i = 0; i < rounds; i++) {

        if(!letter_exist(word_guessed[i])) {
            cont_wrong_guesses++;
        }
    }
    return cont_wrong_guesses;
}

int hanged() {
    
    return  mistakes() >= 5;
}

int win() {
    for(int i = 0; i < strlen(secret_word); i++) {
        if(!check_guess(secret_word[i])) {
            return 0;
        }
    }
    return 1;
}

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
    int mistake = mistakes();
    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (mistake>=1?'(':' '), (mistake>=1?'_':' '), (mistake>=1?')':' '));
    printf(" |      %c%c%c  \n", (mistake>=3?'\\':' '), (mistake>=2?'|':' '), (mistake>=3?'/': ' '));
    printf(" |       %c     \n", (mistake>=2?'|':' '));
    printf(" |      %c %c   \n", (mistake>=4?'/':' '), (mistake>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    for (int i = 0; i < strlen(secret_word); i++) {           
        if (check_guess(secret_word[i])) {
            printf("%c ", secret_word[i]);
        } else {
            printf("_ ");
        }      
    }
    printf("\n");
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

void add_new_word() {
    char want;
    printf("You want to add a new word on our base [Y/N]?\n");
    scanf(" %c",&want);

    if (want == 'y' || want == 'Y') {
        char new_word[WORD_SIZE];
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


int main() {
    


    choose_secret_word();
    greetings();

    
    do { 
        printf("%s\n", secret_word);        
        
        hangman();
        printf("\n");
        new_guess(word_guessed);
        } while (!win() && !hanged());  

    if (win()){
        printf("\nCongratulation, you won!:o\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");
     
    }

    else {
        printf("\nYou were hanged! :(\n");
        printf("The word was: **%s**\n\n", secret_word);

        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }    
    add_new_word();
    
}