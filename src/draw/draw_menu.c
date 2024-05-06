/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** draw_menu
*/

#include "my.h"

static void draw_help_menu(sfRenderWindow *window, menu_t *menu)
{
    return;
}

static void draw_option_menu(sfRenderWindow *window, menu_t *menu)
{
    return;
}

static void draw_main_menu(sfRenderWindow *window,
    menu_t *menu)
{
    for (int i = 0; menu->main_menu->buttons->sprites[i] != NULL; i++) {
        sfRenderWindow_drawSprite(window,
            menu->main_menu->buttons->sprites[i], NULL);
        sfRenderWindow_drawText(window,
            menu->main_menu->buttons->text[i], NULL);
    }
    sfRenderWindow_drawSprite(window,
        menu->main_menu->buttons->help_back_spr, NULL);
    sfRenderWindow_drawSprite(window,
        menu->main_menu->buttons->help_book_spr, NULL);
}

static void draw_menu_background(sfRenderWindow *window,
    background_menu_t *background)
{
    sfRenderWindow_drawSprite(window, background->background_sprite, NULL);
    for (int i = 0; background->characters[i] != NULL; i++)
        sfRenderWindow_drawSprite(window, background->characters[i], NULL);
}

void draw_menu(rpg_t *rpg)
{
    void (*draw_menu_fct[])(sfRenderWindow *, menu_t *) =
        {draw_main_menu, draw_help_menu, draw_option_menu};

    draw_menu_background(rpg->window, rpg->menu->background);
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->main_menu->wos_sprite,
    NULL);
    sfRenderWindow_drawText(rpg->window, rpg->menu->main_menu->wos, NULL);
    draw_menu_fct[rpg->menu->screen](rpg->window, rpg->menu);
}
