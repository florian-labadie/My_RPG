/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** game_manager
*/

#include "my.h"

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
