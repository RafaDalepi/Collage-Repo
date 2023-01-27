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

   while( token != NULL ) {
        // printf( " %s\n", token ); 
        token = strtok(NULL, " ");
        if (token == "the"){
            aparitions++;
        }else{
            rest++;       
        }
        printf("%s\n %d - %d\n", token, aparitions, rest);
    }
}
    
