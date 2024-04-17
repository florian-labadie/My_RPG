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
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->elf_sprites, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->dwarf_sprites, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->human_sprites, NULL);
}

int rpg_loop(rpg_t *rpg)
{
    sfEvent event = {};

    while (sfRenderWindow_isOpen(rpg->window)) {
        background_player_manager(rpg->menu);
        sfRenderWindow_clear(rpg->window, sfWhite);
        background_menu_manager(rpg->menu);
        event_manager(rpg);
        draw_menu(rpg);
        sfRenderWindow_display(rpg->window);
    }
    sfRenderWindow_close(rpg->window);
    destroy_resources(rpg);
    return 0;
}
