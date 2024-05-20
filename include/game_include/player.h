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

typedef struct player_stats_s {
    float health;
    float mana;
    float attack;
    float magic_attack;
    float defense;
} player_stats_t;

typedef struct player_sprites_s {
    sfTexture *player_text;
    sfSprite *player;

    sfIntRect player_rect;
    sfClock *player_clock;
} player_sprites_t;

typedef struct player_s {
    char *name;
    player_race_t race;

    sfVector2f position;

    player_sprites_t *sprites;
    player_stats_t stats;
} player_t;

#endif /* !PLAYER_H_ */
