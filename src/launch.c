/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Launch
*/

#include "my.h"

static int rpg_setup(rpg_t *rpg, char const *filepath, char const *user)
{
    
}

int launch(char const *filepath, char const *user)
{
    rpg_t rpg = {};
    sfVideoMode videoMode = {1920, 1080, 60};

    if (filepath && check_file(filepath) == KO)
        return KO;
    rpg.window = sfRenderWindow_create(videoMode,
    "rpg", sfClose | sfResize, NULL);
    if (rpg_setup(&rpg, filepath, user) == KO ||
        setup_cursor(&rpg) == KO)
        return KO;
    return rpg_loop(&rpg);
}
