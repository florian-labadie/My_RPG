/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** setup_menu
*/

#include "my.h"

int menu_setup(rpg_t *rpg, char const *user)
{
    if (!rpg || !user)
        return KO;
    rpg->menu = malloc(sizeof(menu_t));
    rpg->menu->screen = MAIN;
    if (rpg->menu == NULL)
        return KO;
    if (background_menu_setup(rpg->menu) == KO ||
        background_player_setup(rpg->menu) == KO ||
        menu_button_setup(rpg->menu->button) == KO)
        return KO;
    return OK;
}
