/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** game_manager
*/

#include "my.h"

static void game_music(rpg_t *rpg)
{
    if (sfMusic_getStatus(rpg->game->map->game_sound) == sfStopped ||
        sfMusic_getStatus(rpg->game->map->game_sound) == sfPaused)
        sfMusic_play(rpg->game->map->game_sound);
}

void game_manager(rpg_t *rpg)
{
    game_music(rpg);
    return;
}
