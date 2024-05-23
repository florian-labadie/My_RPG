/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** option_pages.c
*/

#include "my.h"

void draw_arrows_and_turn_pages(sfRenderWindow *window, menu_t *menu)
{
    if (menu->settings->arrowr == sfTrue) {
        sfRenderWindow_drawSprite(window, menu->settings->book_sp[2], NULL);
        turn_book
        (menu->settings, menu->settings->book_sp[2], menu->settings->b_clock);
    }
    if (menu->settings->arrowl == sfTrue) {
        sfRenderWindow_drawSprite(window, menu->settings->book_sp[1], NULL);
        turn_book
        (menu->settings, menu->settings->book_sp[1], menu->settings->b_clock);
    }
}

void display_page_1(sfRenderWindow *wiw, menu_t *menu)
{
    if (menu->settings->arrowl == sfFalse) {
        sfRenderWindow_drawText(wiw, menu->settings->title[2], NULL);
        sfRenderWindow_drawText(wiw, menu->settings->title[3], NULL);
        sfRenderWindow_drawSprite(wiw, menu->settings->intern_sp[2], NULL);
        for (int i = 0; i < 2; i++) {
            sfRenderWindow_drawSprite(wiw, menu->settings->reso_sp[i], NULL);
            sfRenderWindow_drawText(wiw, menu->settings->reso[i], NULL);
        }
    }
}

void display_page_2(sfRenderWindow *wiw, menu_t *menu)
{
    if (menu->settings->arrowr == sfFalse) {
        sfRenderWindow_drawSprite(wiw, menu->settings->intern_sp[0], NULL);
        sfRenderWindow_drawSprite(wiw, menu->settings->intern_sp[1], NULL);
        sfRenderWindow_drawText(wiw, menu->settings->title[0], NULL);
        sfRenderWindow_drawText(wiw, menu->settings->title[1], NULL);
        sfRenderWindow_drawText(wiw, menu->settings->volume_text, NULL);
        for (int i = 0; i < 3; i++) {
            sfRenderWindow_drawSprite(wiw, menu->settings->fps_sp[i], NULL);
            sfRenderWindow_drawText(wiw, menu->settings->fps[i], NULL);
        }
    }
}

void handle_events_page_1(rpg_t *rpg, sfEvent event)
{
    set_window_size(rpg, event);
}

void handle_events_page_2(rpg_t *rpg, sfEvent event)
{
    music_sound(rpg, event);
}
