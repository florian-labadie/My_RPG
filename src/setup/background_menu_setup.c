/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** background_menu
*/

#include "my.h"

int setup_background_menu(menu_t *menu)
{
    menu->background_texture = sfTexture_createFromFile(BACKGROUND, NULL);
    menu->background_sprite = create_button(menu->background_texture,
        (sfVector2f){1920.0 / 560.0, 1080.0 / 272.0}, (sfVector2f){0, 0});
    menu->bg_anim_clock = sfClock_create();
    if (!menu->background_texture || !menu->background_sprite)
        return KO;
    sfSprite_setTextureRect(menu->background_sprite, BG_RECT);
    return OK;
}
