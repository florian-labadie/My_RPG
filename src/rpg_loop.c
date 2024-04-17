/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** rpgLoop
*/

#include "my.h"

static void draw_menu(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->background_sprite, NULL);
    for (int i = 0; rpg->menu->button->play_sprite[i] != NULL; i += 1) {
        sfRenderWindow_drawSprite(rpg->window,
        rpg->menu->button->play_sprite[i], NULL);
        sfRenderWindow_drawText(rpg->window, rpg->menu->button->text[i], NULL);
    }
}

int rpg_loop(rpg_t *rpg)
{
    sfEvent event = {};

    while (sfRenderWindow_isOpen(rpg->window)) {
        background_menu_manager(rpg->menu);
        sfRenderWindow_clear(rpg->window, sfWhite);
        draw_menu(rpg);
        sfRenderWindow_display(rpg->window);
    }
    sfRenderWindow_close(rpg->window);
    destroy_resources(rpg);
    return 0;
}
