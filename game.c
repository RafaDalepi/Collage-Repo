#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void clrscreen(){
    system("clear");
}

int numgen(int param){
    int num = rand() % param + 1;
    return num;
}

int skelly(int live, int attack, int multiplier){
    live = 2 * multiplier;
    attack = 1 * multiplier; 
}

int main(){
    clrscreen();
    int lives = 3, score = 0, attack = 10, killedBoss = 0, escaped = 0;
    int multiplier, action;
    float level = 0;
    char name[10];
    
    printf("Enter your name: ");
    fgets(name, 20, stdin);
    
    for (int round = 0; lives > 0; round++){
        printf("Welcome to this little rpg game, %s", name);
        printf("\nName: %s 🆜 Lives: %d 🆜 Level: %.2f 🆜 Attack: %d 🆜 Score: %d 🆜 Round: %d", name, lives, level, attack, score, round);

        if(round == 0 || killedBoss == 1 || escaped == 1){
            printf("What dungeon do you wish to go in?\n 1.Easy\n 2.Medium\n 3.Hard \n");
            scanf("%d", &multiplier);
        }

        while (killedBoss == 0 || escaped == 0){
            printf("\nYou have entered the dungeon!\nWhat do you wish to do?\n 1.Attack\n 2.Walk\n 3.Escape\n");
            scanf("%d", &action);

            if(action == 1 && round == 0 ){
                printf("You haven't walked yet!\n");
            }else if(action == 2 && numgen(3) == 1){
                printf("You have encountered a monster!\n");
            }
        }
        lives==0;
        // clrscreen();
    }

    printf("\n___Game Over___\nYour score is: %d\n", score);

}

//  int input;
//         scanf("%d", &input);

//         if(input == 1){
//             lives--;
//         }