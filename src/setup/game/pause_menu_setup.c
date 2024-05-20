/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** pause_menu_setup
*/

#include "my.h"

int pause_menu_setup(game_t *game, sfRenderWindow *window)
{
    game->pause->background = sfRectangleShape_create();
    sfRectangleShape_setSize(game->pause->background,
        (sfVector2f){960.0, 695.0});
    sfRectangleShape_setFillColor(game->pause->background,
        sfColor_fromRGBA(0, 0, 0, 100));
    return OK;
}
