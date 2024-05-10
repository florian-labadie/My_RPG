/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** set_volume_music
*/

#include "my.h"

static void set_volume_game(game_t *game, stock_setting_t *setting)
{
    if (game->map && game->map->game_sound)
        sfMusic_setVolume(game->map->game_sound, setting->sound_game);
}

static void set_volume_menu(menu_t *menu, stock_setting_t *setting)
{
    if (menu->click_button_sound)
        sfSound_setVolume(menu->click_button_sound, setting->sound_game * 2);
    if (menu->menu_sound)
        sfMusic_setVolume(menu->menu_sound, setting->sound_game);
}

void set_volume_music(rpg_t *rpg)
{
    if (rpg->menu)
        set_volume_menu(rpg->menu, rpg->setting);
    if (rpg->game)
        set_volume_game(rpg->game, rpg->setting);
}
