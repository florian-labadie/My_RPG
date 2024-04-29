/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** book_setup.c
*/

#include "my.h"

static int setup_open_book(settings_t *settings)
{
    settings->react->rect.left = -50;
    settings->react->rect.top = 0;
    settings->react->rect.width = 252;
    settings->react->rect.height = 297;
    settings->anim->open_book = sfTexture_createFromFile(OPEN_BOOK_P, NULL);
    if (!settings->anim->open_book)
        return KO;
    settings->anim->open_book_spr = create_button(settings->anim->open_book,
        (sfVector2f) {7.5, 3.75}, (sfVector2f) {25.0, -120.0});
    sfSprite_setTextureRect(settings->anim->open_book_spr,
        settings->react->rect);
    settings->anim->book_clock = sfClock_create();
    return OK;
}

static int setup_next_page(settings_t *settings)
{
    settings->react->ract.left = -9;
    settings->react->ract.top = 0;
    settings->react->ract.width = 248;
    settings->react->ract.height = 297;
    settings->anim->next_page = sfTexture_createFromFile(NEXT_PAGE_P, NULL);
    if (!settings->anim->next_page)
        return KO;
    settings->anim->next_page_spr = create_button(settings->anim->next_page,
        (sfVector2f) {7.5, 3.75}, (sfVector2f) {25.0, -120.0});
    sfSprite_setTextureRect(settings->anim->next_page_spr,
        settings->react->ract);
    settings->anim->book_clock = sfClock_create();
    return OK;
}

static int setup_previous_page(settings_t *settings)
{
    settings->react->ruct.left = -9;
    settings->react->ruct.top = 0;
    settings->react->ruct.width = 248;
    settings->react->ruct.height = 297;
    settings->anim->previous_page = sfTexture_createFromFile(PREVIOUS_PAGE_P,
        NULL);
    if (!settings->anim->previous_page)
        return KO;
    settings->anim->previous_page_spr =
        create_button(settings->anim->previous_page, (sfVector2f) {7.5, 3.75},
            (sfVector2f) {25.0, -120.0});
    sfSprite_setTextureRect(settings->anim->previous_page_spr,
        settings->react->ruct);
    settings->anim->book_clock = sfClock_create();
    return OK;
}

static int setup_close_book(settings_t *settings)
{
    settings->react->rict.left = -9;
    settings->react->rict.top = 0;
    settings->react->rict.width = 252;
    settings->react->rict.height = 297;
    settings->anim->close_book = sfTexture_createFromFile(CLOSE_BOOK_P, NULL);
    if (!settings->anim->close_book)
        return KO;
    settings->anim->close_book_spr = create_button(settings->anim->close_book,
        (sfVector2f) {7.5, 3.75}, (sfVector2f) {25.0, -120.0});
    sfSprite_setTextureRect(settings->anim->close_book_spr,
        settings->react->rict);
    settings->anim->book_clock = sfClock_create();
    return OK;
}

int setup_option_menu(settings_t *settings, sfRenderWindow *window)
{
    settings->anim = malloc(sizeof(anim_t));
    if (setup_open_book(settings) == KO ||
        setup_next_page(settings) == KO ||
        setup_previous_page(settings) == KO ||
        setup_close_book(settings) == KO)
        return KO;
    return OK;
}
