/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** inventory_menu_event
*/

#include "my.h"

int inventory_menu_event(rpg_t *rpg, sfEvent event)
{
    if (event.key.code == sfKeyTab && event.key.type == sfEvtKeyPressed)
        rpg->game->screen = PLAYING;
    if (event.key.code == sfKeyPause && event.key.type == sfEvtKeyPressed)
        rpg->game->screen = PAUSE;
    return OK;
}
