/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Launch
*/

#include "my.h"

static void set_video_mode(rpg_t *rpg)
{
    sfVideoMode FullScreenMode = {1920, 1080, 32};
    sfVideoMode videoMode = {0, 0, 0};

    videoMode.width = rpg->setting->size_screen.x;
    videoMode.height = rpg->setting->size_screen.y;
    videoMode.bitsPerPixel = rpg->setting->fps;
    if (rpg->setting->screen_mode == true) {
        rpg->window = sfRenderWindow_create(FullScreenMode,
            "World_of_Sylveria", sfFullscreen, NULL);
    } else {
        rpg->window = sfRenderWindow_create(videoMode,
            "World_of_Sylveria", sfClose | sfResize, NULL);
    }
}

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

    if (settings_game(&rpg) == KO)
        return KO;
    set_video_mode(&rpg);
    if (rpg_setup(&rpg, user) == KO)
        return KO;
    set_volume_music(&rpg);
    return rpg_loop(&rpg);
}
