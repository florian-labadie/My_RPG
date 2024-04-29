/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** draw_game
*/

#include "my.h"

void draw_game(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window,
        rpg->game->map->sprite_ground, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->game->map->sprite_obj, NULL);
    change_view(rpg);
    return;
}
