/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

    #include "rpg.h"

typedef struct map_s {
    sfRenderTexture *map;
    sfTexture *texture;
    sfSprite *sprite;
} map_t;

#endif /* !MAP_H_ */
