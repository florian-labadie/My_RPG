/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Launch
*/

#include "my.h"

static int rpg_setup(rpg_t *rpg, char const *user)
{
    rpg->screen = MAIN_MENU;
    rpg->window_size = sfRenderWindow_getSize(rpg->window);
    if (menu_setup(rpg, user) == KO)
        return KO;
    return OK;
}

int launch_rpg(char const *user)
{
    rpg_t rpg = {};
    sfVideoMode videoMode = {1920, 1080, 60};

    rpg.window = sfRenderWindow_create(videoMode,
        "World_of_Sylveria", sfClose | sfResize, NULL);
    if (rpg_setup(&rpg, user) == KO)
        return KO;
    return rpg_loop(&rpg);
}
