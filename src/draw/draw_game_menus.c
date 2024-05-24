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

static void draw_item_inventory(sfRenderWindow *window, game_t *game)
{
    for (int i = 0; i < 4; i += 1) {
        sfRenderWindow_drawSprite(window,
            game->inventory->item->health_pot[i], NULL);
        sfRenderWindow_drawSprite(window,
            game->inventory->item->mana_pot[i], NULL);
    }
    for (int i = 0; i < 4; i += 1)
        if (i < game->inventory->nbr_health_pot) {
            sfSprite_setColor(game->inventory->item->health_pot[i], sfWhite);
        } else
            sfSprite_setColor(game->inventory->item->health_pot[i], sfColor_fromRGB(100, 100, 100));
    for (int i = 0; i < 4; i += 1)
        if (i < game->inventory->nbr_mana_pot) {
            sfSprite_setColor(game->inventory->item->mana_pot[i], sfWhite);
        } else
            sfSprite_setColor(game->inventory->item->mana_pot[i], sfColor_fromRGB(100, 100, 100));
    for (int i = 0; i < 3; i += 1) {
        sfRenderWindow_drawSprite(window,
            game->inventory->item->weapons[game->player->race][i], NULL);
    }
}

void draw_inventory(sfRenderWindow *window, game_t *game)
{
    if (game->map->choice_map == VILLAGE)
        sfRenderWindow_setView(window, game->original_view);
    sfRenderWindow_drawRectangleShape(window, game->inventory->background,
        NULL);
    for (int i = 0; game->inventory->sprites[i]; i++)
        sfRenderWindow_drawSprite(window, game->inventory->sprites[i], NULL);
    for (int i = 0; game->inventory->text[i]; i++)
        sfRenderWindow_drawText(window, game->inventory->text[i], NULL);
    draw_item_inventory(window, game);
    for (int i = 0; game->inventory->stats_text[i]; i++)
        sfRenderWindow_drawText(window, game->inventory->stats_text[i], NULL);
    if (game->map->choice_map == VILLAGE)
        sfRenderWindow_setView(window, game->map->view);
}
