/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** display_option.c
*/

#include "my.h"

int anim_open_book(settings_t *settings)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(settings->anim->book_clock))
        > 0.1 && settings->react->rect.left < 2709) {
        settings->react->rect.left += 252;
        sfSprite_setTextureRect(settings->anim->open_book_spr,
            settings->react->rect);
        sfClock_restart(settings->anim->book_clock);
    }
    return OK;
}

int anim_next_page(settings_t *settings)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(settings->anim->book_clock))
        > 0.1 && settings->react->ract.left < 1244) {
        settings->react->ract.left += 252;
        sfSprite_setTextureRect(settings->anim->next_page_spr,
            settings->react->ract);
        sfClock_restart(settings->anim->book_clock);
    }
    return OK;
}

int anim_previous_page(settings_t *settings)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(settings->anim->book_clock))
        > 0.1 && settings->react->ruct.left < 1244) {
        settings->react->ruct.left += 252;
        sfSprite_setTextureRect(settings->anim->previous_page_spr,
            settings->react->ruct);
        sfClock_restart(settings->anim->book_clock);
    }
    return OK;
}

int anim_close_book(settings_t *settings)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(settings->anim->book_clock))
            > 0.1 && settings->react->rict.left < 2709) {
        settings->react->rict.left += 252;
        sfSprite_setTextureRect(settings->anim->close_book_spr,
            settings->react->rict);
        sfClock_restart(settings->anim->book_clock);
    }
    return OK;
}
