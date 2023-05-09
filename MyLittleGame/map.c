#include <stdio.h>
#include <stdlib.h>
#include <player.h>
#include "map.h"

void map_loader(MAP *map){
    FILE *map_file = fopen("map.txt", "r");
    if(map_file == NULL){
        printf("Error: map.txt not found or corruped\n");
        exit(1);
    }

    char c;
    while((c = fgetc(map_file)) != EOF){
        printf("%c", c);

        int i = 0;
        int j = 0;
        for(;i < map->y; i++){
            for(;j < map->x; j++){
                fscanf(map_file, "%c", &map->map_tiles[i][j]);

                if (map->map_tiles[i][j] == player_body){
                    player_position[0] = i;
                    player_position[1] = j;
                }
            }
            j = 0;
        }
    }

    fclose(map_file);

}

