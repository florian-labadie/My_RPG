/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** rpgLoop
*/

#include "my.h"

static void draw_game(rpg_t *rpg)
{
    return;
}

static void draw_menu(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->background_sprite, NULL);
    for (int i = 0; rpg->menu->button->play_sprite[i] != NULL; i += 1) {
        sfRenderWindow_drawSprite(rpg->window,
        rpg->menu->button->play_sprite[i], NULL);
        sfRenderWindow_drawText(rpg->window, rpg->menu->button->text[i], NULL);
    }
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->elf_sprites, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->dwarf_sprites, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->human_sprites, NULL);
}

int rpg_loop(rpg_t *rpg)
{
    void (*draw_fct[])(rpg_t *rpg) = {draw_menu, draw_game};
    void (*mangager_fct[])(rpg_t *rpg) = {menu_manager, game_manager};

    while (sfRenderWindow_isOpen(rpg->window)) {
        sfRenderWindow_clear(rpg->window, sfWhite);
        mangager_fct[rpg->screen](rpg);
        event_manager(rpg);
        draw_fct[rpg->screen](rpg);
        sfRenderWindow_display(rpg->window);
    }
    sfRenderWindow_close(rpg->window);
    destroy_resources(rpg);
    return 0;
}
