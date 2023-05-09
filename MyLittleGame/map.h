#ifndef MAP_H
#define MAP_H

#define wall '#'

typedef struct map{
    char** map_tiles;
    int x;
    int y;
}MAP;

void map_loader(MAP *map);

#endif 



