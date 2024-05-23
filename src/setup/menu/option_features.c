/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** option_features.c
*/

#include "my.h"

void set_fps(rpg_t *rpg, stock_setting_t *setting)
{
    if (setting->fps == 30 || setting->fps == 45 || setting->fps == 60) {
        sfRenderWindow_setFramerateLimit(rpg->window, setting->fps);
    } else {
        my_putstr("Erreur : FPS non pris en charge.\n");
    }
}

void set_window_size(rpg_t *wiw, unsigned int width, unsigned int height)
{
    sfRenderWindow_setSize(wiw->window, (sfVector2u){width, height});
}

void update_volume_text(rpg_t *rpg, float volume)
{
    char volume_str[10];

    snprintf(volume_str, sizeof(volume_str), "%.0f", volume);
    sfText_setString(rpg->menu->setting->volume_text, volume_str);
}


void set_keybindings(keyboard_t *key)
{
    return;
}
