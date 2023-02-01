#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int wordsQtde = 15 ;

int main(){
    char* repetitions, letters[wordsQtde];    
    int aparitions = 0 , rest = 0 ;

    printf("Your text:\n");
    fgets(letters, sizeof(letters), stdin);

    char * token = strtok(letters, " ");

    if (token == "the"){
        aparitions++;
        printf("AHOY");
    }else{
        rest++;       
    }

    printf("String:%s\nApparitions: %d\nRest: %d\n", token, aparitions, rest);
}

    
