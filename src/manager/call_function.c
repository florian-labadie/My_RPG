/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** call_function
*/

#include "my.h"

void call_life_lev(rpg_t *rpg)
{
    life_manager(rpg->game, rpg->window, rpg->game->player->stats.health);
    level_manager(rpg->game);
}
