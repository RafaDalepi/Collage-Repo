#include <stdio.h>
#include <stdlib.h>

int main(){
    char awnser = 'y';
    int num, randnum;
    randnum = rand() % 10 + 1;
    while (awnser == 'y'){
        printf("Choose your number: ");
        scanf("%d", &num);

        
        if (num == randnum){
            printf("You win!");
        } else {
            printf("You lose!\nThe number was %d\n", randnum);        
        }
        
        printf("Do you want to play again?(y/n): ");
        scanf("%s", &awnser);
    }
}