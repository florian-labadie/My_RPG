/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** game_manager
*/

#include "my.h"

void inventory_manager(game_t *game)
{
    sfText_setString(game->inventory->stats_text[0],
        int_to_str((int)game->player->stats.health));
    sfText_setString(game->inventory->stats_text[1],
        int_to_str((int)game->player->stats.mana));
    sfText_setString(game->inventory->stats_text[2],
        int_to_str((int)game->player->stats.defense));
    sfText_setString(game->inventory->stats_text[3],
        int_to_str((int)game->player->stats.attack));
    sfText_setString(game->inventory->stats_text[4],
        int_to_str((int)game->player->stats.magic_attack));
    for (int i = 0; game->inventory->stats_text[i]; i++)
        set_text_mid_origin(game->inventory->stats_text[i]);
}

void life_manager(game_t *game, sfRenderWindow *window, float value)
{
    if (value > 100.0)
        value = 100.0;
    if (value < 0.0)
        value = 0.0;
    sfRectangleShape_setSize(game->player->life->rects[1],
        get_resize(window, LIFE_RECT_SIZE.x * value / 100, LIFE_RECT_SIZE.y));
}

void level_manager(game_t *game, sfRenderWindow *window)
{
    if (game->player->stats.xp >= 100 * game->player->stats.level) {
        game->player->stats.xp = 0;
        game->player->stats.level += 1;
        sfText_setString(game->player->stats.level_text,
        int_to_str(game->player->stats.level));
        set_text_mid_origin(game->player->stats.level_text);
    }
}
