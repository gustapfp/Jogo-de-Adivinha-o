#include <stdio.h>
#include <string.h>
int main() {

    char secret_word[20];
    sprintf(secret_word, "gustavo");
    // printf("%s", secret_word);
    
    int hanged = 0;
    int right_answer = 0;
    do {
        char guess;
        printf("Choose a lether\n");
        scanf("%c", &guess);
        for (int i = 0; i < strlen(secret_word); i++) {
            if (secret_word[i] == guess) {
                printf("you suggested a right letter! You chosse the lether %c there was in the %d in the secret world. :o \n", guess, i);
            }
        }

    } while (!hanged && !right_answer);
    
    
    /*
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