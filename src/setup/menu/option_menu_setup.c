/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** book_setup.c
*/

#include "my.h"


static int setup_book(settings_t *settings)
{
    char *path[4] = {OPEN_BOOK_P, NEXT_PAGE_P, PREVIOUS_PAGE_P, CLOSE_BOOK_P};
    sfIntRect rect[4] =
        {OPEN_BOOK_RECT, TURN_PAGE_RECT, TURN_PAGE_RECT, CLOSE_BOOK_RECT};

    for (int i = 0; i < 4; i++) {
        settings->book_text[i] = sfTexture_createFromFile(path[i], NULL);
        if (!settings->book_text[i])
            return KO;
        settings->book_sp[i] = create_button(settings->book_text[i],
            (sfVector2f) {7.5, 3.75}, (sfVector2f) {25.0, -120.0});
        sfSprite_setTextureRect(settings->book_sp[i], rect[i]);
        if (!settings->book_sp[i])
            return KO;
    }
    settings->b_clock = sfClock_create();
    return OK;
}

static int setup_external(settings_t *settings)
{
    char *path[3] = {RIGHT_ARROW_P, LEFT_ARROW_P, HOME_SIGN_P};
    sfIntRect rect[3] = {RIGHT_ARROW_RECT, LEFT_ARROW_RECT, HOME_SIGN_RECT};

    for (int i = 0; i < 3; i++) {
        settings->extern_text[i] = sfTexture_createFromFile(path[i], NULL);
        if (!settings->extern_text[i])
            return KO;
    }
    settings->extern_sp[0] = create_button(settings->extern_text[0],
        (sfVector2f) {1, 1}, (sfVector2f) {1550, 110});
    settings->extern_sp[1] = create_button(settings->extern_text[1],
        (sfVector2f) {1, 1}, (sfVector2f) {200, 110});
    settings->extern_sp[2] = create_button(settings->extern_text[2],
        (sfVector2f) {0.60, 0.60}, (sfVector2f) {1700, 25});
    sfSprite_setTextureRect(settings->extern_sp[0], rect[0]);
    sfSprite_setTextureRect(settings->extern_sp[1], rect[1]);
    if (!settings->extern_sp[0] || !settings->extern_sp[1])
        return KO;
    return OK;
}

int setup_option_menu(settings_t *settings, sfRenderWindow *window)
{
    settings->book_sp = malloc(sizeof(sfSprite *) * (4 + 1));
    settings->book_text = malloc(sizeof(sfTexture *) * (4 + 1));
    settings->extern_text = malloc(sizeof(sfTexture *) * (3 + 1));
    settings->extern_sp = malloc(sizeof(sfSprite *) * (3 + 1));
    if (setup_book(settings) == KO || setup_external(settings) == KO)
        return KO;
    return OK;
}
