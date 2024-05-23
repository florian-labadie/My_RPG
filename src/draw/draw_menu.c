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
    sfRenderWindow_drawSprite(window, menu->settings->book_sp[0], NULL);
    open_close_book(menu->settings->book_sp[0], menu->settings->b_clock);
    sfRenderWindow_drawSprite(window, menu->settings->extern_sp[0], NULL);
    sfRenderWindow_drawSprite(window, menu->settings->extern_sp[1], NULL);
    sfRenderWindow_drawSprite(window, menu->settings->extern_sp[2], NULL);
    if (sfSprite_getTextureRect(menu->settings->book_sp[0]).left >= 2709) {
        if (menu->settings->current_page == 0) {
            display_page_1(window, menu);
        }
        if (menu->settings->current_page == 1) {
            display_page_2(window, menu);
        }
    }
    if(menu->settings->arrow_bool_r == sfTrue) {
        sfRenderWindow_drawSprite(window, menu->settings->book_sp[2], NULL);
        turn_book
        (menu->settings, menu->settings->book_sp[2], menu->settings->b_clock);
    }
    if (menu->settings->arrow_bool_l == sfTrue) {
        sfRenderWindow_drawSprite(window, menu->settings->book_sp[1], NULL);
        turn_book
        (menu->settings, menu->settings->book_sp[1], menu->settings->b_clock);
    }
}

static void draw_main_menu(sfRenderWindow *window, menu_t *menu)
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

static void draw_parallax(sfRenderWindow *window, menu_t *menu)
{
    sfRenderWindow_drawSprite(window, menu->parallax->background_sprite, NULL);
    for (int i = 0; i < NB_PARALLAX; i++) {
        sfRenderWindow_drawSprite(window, menu->parallax->sprites[i], NULL);
        sfSprite_move(menu->parallax->sprites[i], (sfVector2f){-1920, 0});
        sfRenderWindow_drawSprite(window, menu->parallax->sprites[i], NULL);
        sfSprite_move(menu->parallax->sprites[i], (sfVector2f){1920, 0});
    }
    sfRenderWindow_drawText(window, menu->parallax->parallax_text, NULL);
}

void draw_menu(rpg_t *rpg)
{
    void (*draw_menu_fct[])(sfRenderWindow *, menu_t *) =
        {draw_parallax, draw_main_menu, draw_help_menu, draw_option_menu,
        draw_help_menu};

    if (rpg->menu->screen != PARALLAX) {
        draw_menu_background(rpg->window, rpg->menu->background);
        sfRenderWindow_drawSprite(rpg->window,
        rpg->menu->main_menu->wos_sprite,
            NULL);
        sfRenderWindow_drawText(rpg->window, rpg->menu->main_menu->wos, NULL);
    }
    draw_menu_fct[rpg->menu->screen](rpg->window, rpg->menu);
}
