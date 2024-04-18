/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** setup_menu
*/

#include "my.h"

static int setup_main_menu(menu_t *menu)
{
    if (menu_button_setup(&menu->main_menu->buttons) == KO)
        return KO;
    return OK;
}

int menu_setup(rpg_t *rpg, char const *user)
{
    rpg->menu = malloc(sizeof(menu_t));
    if (!rpg || !rpg->menu || !user)
        return KO;
    rpg->menu->main_menu = malloc(sizeof(main_menu_t));
    rpg->menu->help = malloc(sizeof(help_t));
    rpg->menu->settings = malloc(sizeof(settings_t));
    rpg->menu->screen = MAIN;
    rpg->menu->menu_sound = sfMusic_createFromFile(MUSIC_MENU);
    sfMusic_setLoop(rpg->menu->menu_sound, true);
    sfMusic_setVolume(rpg->menu->menu_sound, 50.0);
    if (!rpg->menu->main_menu || !rpg->menu->help || !rpg->menu->settings)
        return KO;
    if (background_menu_setup(rpg->menu, rpg->window_size) == KO ||
        setup_main_menu(rpg->menu) == KO)
        return KO;
    return OK;
}
