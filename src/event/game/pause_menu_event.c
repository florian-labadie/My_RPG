/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** pause_menu_event
*/

#include "my.h"

int pause_menu_event(rpg_t *rpg, sfEvent event)
{
    if (event.key.code == sfKeyEscape && event.key.type == sfEvtKeyPressed)
        rpg->game->screen = LOAD_GAME;
    return OK;
}
