/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** draw_villagers.c
*/

#include "my.h"


void draw_villager(game_t *game, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, game->villager->v_sp[0], NULL);
    sfRenderWindow_drawSprite(window, game->villager->v_sp[1], NULL);
    sfRenderWindow_drawSprite(window, game->villager->v_sp[2], NULL);
    sfRenderWindow_drawSprite(window, game->villager->v_sp[3], NULL);
}
