/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** help_menu_event
*/

#include "my.h"

int help_menu_event(rpg_t *rpg, sfEvent event)
{
    if (sfEvtMouseButtonReleased == event.type)
        rpg->menu->screen = MAIN;
    return KO;
}
