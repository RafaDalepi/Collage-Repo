#ifndef PLAYER_H
#define PLAYER_H

#define player_body '0'
#define initialHP 10
#define initialXP 10

typedef struct player_character{
    char Name[100];
    int HP;
    int xp_points;
    int strength;
}player_character;

int player_position[2];


#endif
