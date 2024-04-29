/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** book_setup.c
*/

#include "my.h"

static int book_setup(settings_t *settings)
{
    settings->rect.left = -50;
    settings->rect.top = 0;
    settings->rect.width = 252;
    settings->rect.height = 297;
    settings->open_book = sfTexture_createFromFile(OPEN_BOOK_P, NULL);
    if (!settings->open_book)
        return KO;
    settings->open_book_spr = create_button(settings->open_book,
        (sfVector2f){7.5, 3.75}, (sfVector2f) {25.0, -120.0});
    sfSprite_setTextureRect(settings->open_book_spr, settings->rect);
    settings->book_clock = sfClock_create();
    return OK;
}

int setup_option_menu(settings_t *settings, sfRenderWindow *window)
{
    if (book_setup(settings) == KO)
        return KO;
    return OK;
}
