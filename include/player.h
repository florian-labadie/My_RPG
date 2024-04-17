/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

    #include "rpg.h"

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>

typedef struct stats_s {
    float health;
    float mana;
    float attack;
    float magic_attack;
    float defense;
} stats_t;

typedef struct player_s {
    char *name;

    sfVector2f position;

    stats_t stats;
} player_t;

#endif /* !PLAYER_H_ */
