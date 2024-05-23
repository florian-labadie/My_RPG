/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** menu_manager
*/

#include "my.h"

static void menu_music(rpg_t *rpg)
{
    if (sfMusic_getStatus(rpg->menu->menu_sound) == sfStopped ||
        sfMusic_getStatus(rpg->menu->menu_sound) == sfPaused)
        sfMusic_play(rpg->menu->menu_sound);
    if (sfTime_asSeconds(sfMusic_getPlayingOffset(rpg->menu->menu_sound))
        >= 21.5)
        sfMusic_setPlayingOffset(rpg->menu->menu_sound, sfSeconds(1));
}

void move_parallax(parallax_t *parallax, int move)
{
    int y_pos = 0;

    for (int i = 0; i < NB_PARALLAX; i++) {
        y_pos = sfSprite_getPosition(parallax->sprites[i]).y;
        if (sfSprite_getPosition(parallax->sprites[i]).x < 1920) {
            sfSprite_move(parallax->sprites[i], (sfVector2f)
            {parallax->speeds[i] * move, 0});
        } else {
            sfSprite_setPosition(parallax->sprites[i], (sfVector2f){0, y_pos});
        }
    }
}

void menu_manager(rpg_t *rpg)
{
    int move = 1;

    menu_music(rpg);
    if (rpg->menu->screen == PARALLAX)
        move_parallax(rpg->menu->parallax, move);
    background_menu_manager(rpg->menu);
    return;
}
