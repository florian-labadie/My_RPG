/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** game_setup
*/

#include "my.h"

int game_setup(rpg_t *rpg)
{
    if (set_up_map(rpg->map, rpg->window) == KO)
        return KO;
    return OK;
}
