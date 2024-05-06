/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** display_option.c
*/

#include "my.h"


int turn_book(sfSprite *sprite, sfClock *clock)
{
    sfIntRect rect = {0, 0, 0, 0};

    rect = sfSprite_getTextureRect(sprite);
    sfSprite_setTextureRect(sprite, rect);
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.1 &&
        rect.left < 1244) {
        rect.left += 252;
        sfSprite_setTextureRect(sprite, rect);
        sfClock_restart(clock);
    }
    return OK;
}

int open_close_book(sfSprite *sprite, sfClock *clock)
{
    sfIntRect rect = {0, 0, 0, 0};

    rect = sfSprite_getTextureRect(sprite);
    sfSprite_setTextureRect(sprite, rect);
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.1 &&
        rect.left < 2709) {
        rect.left += 252;
        sfSprite_setTextureRect(sprite, rect);
        sfClock_restart(clock);
    }
    return OK;
}
