/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** background_menu
*/

#include "my.h"

static int setup_background_characters(background_menu_t **background,
    sfVector2u window_size)
{
    sfVector2f scales[3] = {{1, 1}, {0.9, 0.9}, {1, 1}};
    sfVector2f pos[3] = {{-20, (window_size.y * (1080 - 117)) / 1080}, {-100, (window_size.y * (1080 - 115)) / 1080}, {-180, (window_size.y * (1080 - 125)) / 1080}};
    sfIntRect rects[3] = {HUMAN_RECT, DWARF_RECT, ELF_RECT};

    printf("x : %d et y : %d\n", window_size.x, window_size.y);
    (*background)->characters = malloc(sizeof(sfSprite *) * 4);
    (*background)->characters[3] = NULL;
    (*background)->characters_texture = sfTexture_createFromFile(PLAYER, NULL);
    for (int i = 0; i < 3; i++) {
        (*background)->characters[i] = create_button
            ((*background)->characters_texture, scales[i], pos[i]);
        sfSprite_setTextureRect((*background)->characters[i], rects[i]);
        if (!(*background)->characters[i])
            return KO;
    }
    return OK;
}

int background_menu_setup(menu_t *menu, sfVector2u window_size)
{
    menu->background = malloc(sizeof(background_menu_t));
    menu->background->background_texture =
        sfTexture_createFromFile(BACKGROUND, NULL);
    menu->background->background_sprite =
        create_button(menu->background->background_texture, (sfVector2f)
        {window_size.x / 560.0, window_size.y / 272.0}, (sfVector2f){0, 0});
    menu->background->bg_anim_clock = sfClock_create();
    if (!menu->background->background_texture ||
        !menu->background->background_sprite)
        return KO;
    sfSprite_setTextureRect(menu->background->background_sprite, BG_RECT);
    if (setup_background_characters(&menu->background, window_size) == KO)
        return KO;
    return OK;
}
