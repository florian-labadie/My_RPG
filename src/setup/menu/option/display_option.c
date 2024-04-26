/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** display_option.c
*/

#include "my.h"

int display_book(settings_t *settings)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(settings->book_clock)) > 0.1 && settings->rect.left < 2709) {
        settings->rect.left += 252;
        sfSprite_setTextureRect(settings->open_book_spr, settings->rect);
        sfClock_restart(settings->book_clock);
    }
    return OK;
}

