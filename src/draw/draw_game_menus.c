/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** draw_game_menus
*/

#include "my.h"

void draw_pause_menu(sfRenderWindow *window, game_t *game)
{
    if (game->map->choice_map == VILLAGE)
        sfRenderWindow_setView(window, game->original_view);
    sfRenderWindow_drawRectangleShape(window, game->pause->background, NULL);
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawSprite(window, game->pause->sprites[i], NULL);
        sfRenderWindow_drawText(window, game->pause->text[i], NULL);
    }
    if (game->map->choice_map == VILLAGE)
        sfRenderWindow_setView(window, game->map->view);
}

void draw_inventory(sfRenderWindow *window, game_t *game)
{
    if (game->map->choice_map == VILLAGE)
        sfRenderWindow_setView(window, game->original_view);
    sfRenderWindow_drawRectangleShape(window, game->inventory->background,
        NULL);
    for (int i = 0; game->inventory->sprites[i]; i++)
        sfRenderWindow_drawSprite(window, game->inventory->sprites[i], NULL);
    sfRenderWindow_drawText(window, game->inventory->text, NULL);
    if (game->map->choice_map == VILLAGE)
        sfRenderWindow_setView(window, game->map->view);
}
