/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** background_menu
*/

#include "my.h"

static int setup_background_characters(background_menu_t **background,
    sfRenderWindow *window)
{
    sfVector2f scales[3] = {get_resize(window, 1, 1),
        get_resize(window, 0.9, 0.9), get_resize(window, 1, 1)};
    sfVector2f pos[3] = {get_resize(window, -20.0, 1019.0),
    get_resize(window, -100.0, 1019.0), get_resize(window, -180.0, 1017.0)};
    sfIntRect rects[3] = {HUMAN_RECT, DWARF_RECT, ELF_RECT};
    sfVector2f origins[3] = {{0, HUMAN_RECT.height}, {0, DWARF_RECT.height},
        {0, ELF_RECT.height}};

    (*background)->characters = malloc(sizeof(sfSprite *) * 4);
    (*background)->characters[3] = NULL;
    (*background)->characters_texture = sfTexture_createFromFile(PLAYER, NULL);
    for (int i = 0; i < 3; i++) {
        (*background)->characters[i] = create_button
            ((*background)->characters_texture, scales[i], pos[i]);
        sfSprite_setTextureRect((*background)->characters[i], rects[i]);
        sfSprite_setOrigin((*background)->characters[i], origins[i]);
        if (!(*background)->characters[i])
            return KO;
    }
    return OK;
}

int background_menu_setup(menu_t *menu, sfRenderWindow *window)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);

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
    if (setup_background_characters(&menu->background, window) == KO)
        return KO;
    return OK;
}
