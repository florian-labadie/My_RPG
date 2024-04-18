/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** menu_manager
*/

#include "my.h"

void menu_manager(rpg_t *rpg)
{
    background_menu_manager(rpg->menu);
    background_player_manager(rpg->menu);
    return;
}
