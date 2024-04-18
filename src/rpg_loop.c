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

static void draw_menu_buttons(sfRenderWindow *window,
    main_menu_buttons_t *main_menu_buttons)
{
    for (int i = 0; main_menu_buttons->sprites[i] != NULL; i++) {
        sfRenderWindow_drawSprite(window,
            main_menu_buttons->sprites[i], NULL);
        sfRenderWindow_drawText(window, main_menu_buttons->text[i], NULL);
    }
}

static void draw_menu_background(sfRenderWindow *window,
    background_menu_t *background)
{
    sfRenderWindow_drawSprite(window, background->background_sprite, NULL);
    for (int i = 0; background->characters[i] != NULL; i++)
        sfRenderWindow_drawSprite(window, background->characters[i], NULL);
}

static void draw_menu(rpg_t *rpg)
{
    draw_menu_background(rpg->window, rpg->menu->background);
    draw_menu_buttons(rpg->window, rpg->menu->main_menu->buttons);
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
