/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** rpgLoop
*/

#include "my.h"

    // if (rpg->map->rect.left + 450 >= get_resize(rpg->window, 1000, 0).x) {
    //     if (rpg->map->rect.top + 250 < get_resize(rpg->window, 745, 0).x) {
    //         rpg->map->rect.top += 1;
    //         rpg->map->view = sfView_createFromRect(rpg->map->rect);
    //         sfRenderWindow_setView(rpg->window, rpg->map->view);
    //     }
    // if (rpg->map->rect.left <= 0) {
    //     if (rpg->map->rect.top > 0) {
    //         rpg->map->rect.top -= 1;
        //     rpg->map->view = sfView_createFromRect(rpg->map->rect);
        //     sfRenderWindow_setView(rpg->window, rpg->map->view);
        // }
        // return;
    // }
    // rpg->map->rect.left -= 1;
static void draw_game(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window, rpg->map->sprite, NULL);
    sfRenderWindow_setView(rpg->window, rpg->map->view);
    rpg->map->view = sfView_createFromRect(rpg->map->rect);
    sfRenderWindow_setView(rpg->window, rpg->map->view);
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
    sfRenderWindow_drawSprite(window, main_menu_buttons->help_back_spr, NULL);
    sfRenderWindow_drawSprite(window, main_menu_buttons->help_book_spr, NULL);
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
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->main_menu->wos_sprite,
    NULL);
    sfRenderWindow_drawText(rpg->window, rpg->menu->main_menu->wos, NULL);
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
