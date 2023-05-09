#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "Ui.c"
#include "map.c"
#include "map.h"

player_character *player_stats(player_character *character){
    
    printf("Enter your name: ");
    fgets(character->Name, 100, stdin);

    character->HP = initialHP;
    character->xp_points = initialXP;

}

// void player_movement(MAP *map, int player_position[2]){
//     //todo
// }

void allocates_memory(player_character *character, MAP *map){
    character = malloc(sizeof(player_character));
    map = malloc(sizeof(MAP));
}
void frees_memory(player_character *character, MAP *map){
    free(character);
    free(map);
}


int main(){
    player_character *player_main_character;
    MAP *map;

    allocates_memory(player_main_character, map);

    player_stats(player_main_character);

    frees_memory(player_main_character, map);

}

