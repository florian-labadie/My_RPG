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
        settings->book_textures[i] = sfTexture_createFromFile(path[i], NULL);
        if (!settings->book_textures[i])
            return KO;
        settings->book_sprites[i] = create_button(settings->book_textures[i],
            (sfVector2f) {7.5, 3.75}, (sfVector2f) {25.0, -120.0});
        sfSprite_setTextureRect(settings->book_sprites[i], rect[i]);
        if (!settings->book_sprites[i])
            return KO;
    }
    settings->book_clock = sfClock_create();
    return OK;
}

static int setup_arrows(settings_t *settings)
{
    char *path[2] = {RIGHT_ARROW_P, LEFT_ARROW_P};
    sfIntRect rect[2] = {RIGHT_ARROW_RECT, LEFT_ARROW_RECT};

    for (int i = 0; i < 2; i++) {
        settings->arrows_text[i] = sfTexture_createFromFile(path[i], NULL);
        if (!settings->arrows_text[i])
            return KO;
    }
    settings->arrows_sprites[0] = create_button(settings->arrows_text[0],
        (sfVector2f) {1, 1}, (sfVector2f) {0, 0});
    settings->arrows_sprites[1] = create_button(settings->arrows_text[1],
        (sfVector2f) {1, 1}, (sfVector2f) {100, 0});
    sfSprite_setTextureRect(settings->arrows_sprites[0], rect[0]);
    sfSprite_setTextureRect(settings->arrows_sprites[1], rect[1]);
    if (!settings->arrows_sprites[0] || !settings->arrows_sprites[1])
        return KO;
    return OK;
}

int setup_option_menu(settings_t *settings, sfRenderWindow *window)
{
    settings->book_sprites = malloc(sizeof(sfSprite *) * (4 + 1));
    settings->book_textures = malloc(sizeof(sfTexture *) * (4 + 1));
    settings->arrows_text = malloc(sizeof(sfTexture *) * (2 + 1));
    settings->arrows_sprites = malloc(sizeof(sfSprite *) * (2 + 1));
    if (setup_book(settings) == KO || setup_arrows(settings) == KO)
        return KO;
    return OK;
}
