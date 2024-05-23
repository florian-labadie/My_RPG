/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** destroy
*/

#include "my.h"

static void destroy_setting(stock_setting_t *setting)
{
    free(setting->language);
    free(setting);
}

void destroy_rpg(rpg_t *rpg)
{
    destroy_game(rpg->game);
    destroy_menu(rpg->menu);
    sfRenderWindow_destroy(rpg->window);
    destroy_setting(rpg->setting);
    if (!rpg)
        return;
}
