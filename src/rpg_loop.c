/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** rpgLoop
*/

#include "my.h"

static void draw_map(rpg_t *rpg)
{
    if (rpg->screen == MAIN_MENU)
        return;
    sfRenderWindow_drawSprite(rpg->window, rpg->map->sprite,
    NULL);
    sfRenderTexture_display(rpg->map->map);
}

int rpg_loop(rpg_t *rpg)
{
    sfWindow_setMouseCursorVisible((sfWindow *) rpg->window, sfFalse);
    while (sfRenderWindow_isOpen(rpg->window)) {
        sfRenderWindow_clear(rpg->window, sfWhite);
        event_manager(rpg);
        draw_texture(rpg);
        draw_toolbar(rpg);
        draw_help(rpg);
        draw_scrolls(rpg);
        draw_cursor(rpg);
        sfRenderWindow_display(rpg->window);
    }
    sfRenderWindow_close(rpg->window);
    destroy_resources(rpg);
    return 0;
}
