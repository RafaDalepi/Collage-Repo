#include <stdio.h>
#include "player.h"
#include "map.c"

void interface(player_character *player){
    printf("Name: %s # HP: %d # XP: %d \n", player->Name, player->HP, player->xp_points);
}


