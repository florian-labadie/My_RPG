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
        {OPEN_BOOK_R, TURN_PAGE_R, TURN_PAGE_R, CLOSE_BOOK_R};

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
    if (!settings->extern_sp[0] || !settings->extern_sp[1])
        return KO;
    return OK;
}

int setup_volume_text(settings_t *settings, const char *font_path)
{
    settings->font = sfFont_createFromFile(GAMERIA_FONT);
    if (!settings->font)
        return KO;
    settings->volume_text = sfText_create();
    if (!settings->volume_text) {
        sfFont_destroy(settings->font);
        return KO;
    }
    sfText_setFont(settings->volume_text, settings->font);
    sfText_setCharacterSize(settings->volume_text, 24);
    sfText_setPosition(settings->volume_text, (sfVector2f){100, 50});
    return OK;
}

static int setup_internal(settings_t *settings)
{
    char *path[4] = {PLUS_SIGN_P, MINUS_SIGN_P, D_ARROW_P, D_ZQSD_P};

    for (int i = 0; i < 4; i++) {
        settings->intern_text[i] = sfTexture_createFromFile(path[i], NULL);
        if (!settings->intern_text[i])
            return KO;
    }
    settings->intern_sp[0] = create_button(settings->intern_text[0],
        (sfVector2f) {0.75, 0.75}, (sfVector2f) {200, 500});
    settings->intern_sp[1] = create_button(settings->intern_text[1],
        (sfVector2f) {0.75, 0.75}, (sfVector2f) {530, 500});
    settings->intern_sp[2] = create_button(settings->intern_text[2],
        (sfVector2f) {0.75, 0.75}, (sfVector2f) {530, 500});
    settings->intern_sp[3] = create_button(settings->intern_text[3],
        (sfVector2f) {0.75, 0.75}, (sfVector2f) {200, 500});
    if (!settings->intern_sp[0] || !settings->intern_sp[1] ||
        !settings->intern_sp[2] || !settings->intern_sp[3] ||
        setup_volume_text(settings, GAMERIA_FONT) != OK)
        return KO;
    return OK;
}

static int setup_title(settings_t *settings)
{
    sfFont *font = sfFont_createFromFile(GAMERIA_FONT);
    const char *titles[4] = {"Son", "     FPS", "Touches", "Resolution"};

    if (!font)
        return KO;
    for (int i = 0; i < 4; i++) {
        settings->title[i] = create_text(font, titles[i], 50,
        (sfVector2f) {(i % 2) ? 1300 : 385, 340});
    }
    return OK;
}

static int setup_reso(settings_t *settings)
{
    char *path[2] = {FULL_SREEN_P, SPLIT_SCREEN_P};
    sfFont *reso = sfFont_createFromFile(GAMERIA_FONT);
    const char *titles[2] = {"  1920 x 1080", "  960 x 540"};

    if (!reso)
        return KO;
    for (int i = 0; i < 2; i++) {
        settings->reso_text[i] = sfTexture_createFromFile(path[i], NULL);
        settings->reso_sp[i] = create_button(settings->reso_text[i],
            (sfVector2f) {1, 1}, (sfVector2f) {1200 + i * 250, 500});
        settings->reso[i] = create_text(reso, titles[i], 30,
            (sfVector2f) {1220 + i * 250, 550});
        if (!settings->reso_sp[i] || !settings->reso[i]
            || !settings->reso_text[i])
            return KO;
    }
    return OK;
}

static int setup_fps(settings_t *settings)
{
    char *path[3] = {FPS_30_P, FPS_45_P, FPS_60_P};
    sfFont *fps = sfFont_createFromFile(GAMERIA_FONT);
    const char *titles[3] = {"30 FPS", "45 FPS", "60 FPS"};

    if (!fps)
        return KO;
    for (int i = 0; i < 3; i++) {
        settings->fps_text[i] = sfTexture_createFromFile(path[i], NULL);
        settings->fps_sp[i] = create_button(settings->fps_text[i],
            (sfVector2f) {0.35, 0.35}, (sfVector2f) {1225 + i * 150, 500});
        settings->fps[i] = create_text(fps, titles[i], 30,
            (sfVector2f) {1245 + i * 150, 550});
        if (!settings->fps_sp[i] || !settings->fps[i]
            || !settings->fps_text[i])
            return KO;
    }
    return OK;
}

int setup_option_menu(settings_t *settings, sfRenderWindow *window)
{
    (void)window;
    settings->book_sp = malloc(sizeof(sfSprite *) * (4 + 1));
    settings->book_text = malloc(sizeof(sfTexture *) * (4 + 1));
    settings->extern_text = malloc(sizeof(sfTexture *) * (3 + 1));
    settings->extern_sp = malloc(sizeof(sfSprite *) * (3 + 1));
    settings->intern_text = malloc(sizeof(sfTexture *) * (4 + 1));
    settings->intern_sp = malloc(sizeof(sfSprite *) * (4 + 1));
    settings->fps_sp = malloc(sizeof(sfSprite *) * (3 + 1));
    settings->fps_text = malloc(sizeof(sfSprite *) * (3 + 1));
    settings->reso_sp = malloc(sizeof(sfSprite *) * (2 + 1));
    settings->reso_text = malloc(sizeof(sfSprite *) * (2 + 1));
    settings->arrowl = false;
    settings->arrowr = false;
    settings->current_page = 1;
    if (setup_book(settings) == KO || setup_external(settings) == KO
        || setup_internal(settings) == KO || setup_title(settings) == KO
        || setup_fps(settings) == KO || setup_reso(settings) == KO)
        return KO;
    return OK;
}
