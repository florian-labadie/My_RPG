/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** game_setup
*/

#include "my.h"

int game_setup(rpg_t *rpg)
{
    rpg->game->player_move = (sfVector2f) {0.0, 0.0};
    rpg->game->map = malloc(sizeof(map_t));
    rpg->game->player = malloc(sizeof(player_t));
    rpg->game->select = malloc(sizeof(select_t));
    if (!rpg->game->player || !rpg->game->map || !rpg->game->select)
        return KO;
    if (setup_map(rpg->game->map, rpg->window) == KO ||
        player_setup(rpg->window, rpg->game->player) == KO ||
        select_charac(rpg->game, rpg->window) == KO)
        return KO;
    return OK;
}
