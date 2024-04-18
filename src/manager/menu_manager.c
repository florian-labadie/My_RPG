/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** menu_manager
*/

#include "my.h"

void menu_music(rpg_t *rpg)
{
    if (sfMusic_getStatus(rpg->menu->menu_sound) == sfStopped ||
        sfMusic_getStatus(rpg->menu->menu_sound) == sfPaused)
        sfMusic_play(rpg->menu->menu_sound);
    if (sfTime_asSeconds(sfMusic_getPlayingOffset(rpg->menu->menu_sound))
        >= 21.5)
        sfMusic_setPlayingOffset(rpg->menu->menu_sound, sfSeconds(1));
}

void menu_manager(rpg_t *rpg)
{
    menu_music(rpg);
    background_menu_manager(rpg->menu);
    background_player_manager(rpg->menu);
    return;
}
