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

void printStats(char *name, int health, float level, int attack, int score){
    printf("Name: %sHealth: %d 🆜 Level: %.2f 🆜 Attack: %d 🆜 Score: %d 🆜 Round: %d\n", name, health, level, attack, score);
}

typedef struct{
    char name[10];
    int health, score, attack, *action, deffense;
    float level;
}entity;

void combatSystem(int *playerHP, int enemyHp, int playerAttack, int enemyAttack, int playerDeffense, int enemyDeffense,  int *playerAction, int enemyAction){
    int round;

    for(round = 0; *playerHP > 0 && enemyHp > 0; round++){
        clrscreen();

        printStats("help", *playerHP, 0, playerAttack, 0);
        printStats("Enemy", enemyHp, 0, enemyAttack, 0);

        printf("what do you want to do? \n 1.Attack \n 2.Deffend \n 3.Heal \n");
        while (getchar() != '\n');
        scanf("%d", playerAction);

        int enemyAction = numgen(3);

        if(*playerAction == 1 && enemyAction == 2){
            enemyHp -= playerAttack;
            printf("You attacked the enemy for %d damage\n", playerAttack - enemyDeffense);
        }else if(playerAction == 1 && enemyAction != 2){
            printf("The enemy attacked you for %d damage\n", enemyAttack);
        }else if(playerAction == 2){
            printf("You have braced yourself\n");
        }else if(playerAction == 3){
            playerHP += 2;
            printf("You healed yourself for 2 health\n");
        }else{
            printf("Invalid input\n");
        }

        if(enemyAction == 1 && playerAction == 2){
            printf("The enemy attacked you for %d damage\n", enemyAttack - playerDeffense);
            playerHP -= enemyAttack;
        }else if(enemyAction == 1 && playerAction != 2){
            printf("The enemy attacked you for %d damage\n", enemyAttack);
        }else if(enemyAction == 2){
            printf("The enemy braced itself\n");
        }else if(enemyAction == 3){
            printf("The enemy healed itself for 2 health\n");
            enemyHp += 2;
        }
    }
}   

int main(){
    clrscreen();
    int multiplier, action;
    char name[10];

    entity player = {name[10], 100, 0, 50, 0, 45};
    entity skelly = {"Skeleton", 100, 0, 50, 0, 45};

    player.level = 0;
    player.health = 100;

    printf("Enter your name: ");
    fgets(player.name, 20, stdin);
    
    for (int round = 0; player.health > 0; round++){
        clrscreen();
        
        printStats(player.name, player.health, player.level, player.attack, player.score);

        combatSystem(player.health, skelly.health, player.attack, skelly.attack, player.deffense, skelly.deffense, player.action, skelly.action);

        int input;
        scanf("%d", &input);
        
    }
}




















//  int input;
//         scanf("%d", &input);

//         if(input == 1){
//             lives--;
//         }