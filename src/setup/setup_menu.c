/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** setup_menu
*/

#include "my.h"

int setup_menu(rpg_t *rpg)
{
    rpg->menu = malloc(sizeof(menu_t));
    rpg->menu->button = malloc(sizeof(button_t));
    rpg->menu->screen = MAIN;
    if (rpg->menu == NULL)
        return KO;
    if (setup_background_menu(rpg->menu) == KO ||
        setup_background_player(rpg->menu) == KO)
        return KO;
    if (menu_button(rpg->menu->button) == KO)
        return KO;
    return OK;
}
