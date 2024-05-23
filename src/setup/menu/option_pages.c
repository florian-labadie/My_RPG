/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** option_pages.c
*/

#include "my.h"


void display_page_1(sfRenderWindow *wiw, menu_t *menu)
{
    if (menu->settings->arrow_bool_l == sfFalse) {
        sfRenderWindow_drawText(wiw, menu->settings->title[2], NULL);
        sfRenderWindow_drawText(wiw, menu->settings->title[3], NULL);
        sfRenderWindow_drawSprite(wiw, menu->settings->intern_sp[2], NULL);
        sfRenderWindow_drawSprite(wiw, menu->settings->intern_sp[3], NULL);
        for (int i = 0; i < 2; i++) {
            sfRenderWindow_drawSprite(wiw, menu->settings->reso_sp[i], NULL);
            sfRenderWindow_drawText(wiw, menu->settings->reso[i], NULL);
        }
    }
}

void display_page_2(sfRenderWindow *wiw, menu_t *menu)
{
    if (menu->settings->arrow_bool_r == sfFalse) {
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
    return;
}

void handle_events_page_2(rpg_t *rpg, sfEvent event)
{
    music_sound(rpg, event);
}
