/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** background_menu_manager
*/

#include "my.h"

static void bg_animation(menu_t *menu)
{
    sfIntRect rect = {0, 0, 0, 0};

    if (!menu)
        return;
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(menu->bg_anim_clock)) > 100) {
        rect = sfSprite_getTextureRect(menu->background_sprite);
        rect.left += 560;
        if (rect.left >= 2800) {
            rect.left = 0;
            rect.top += 272;
        }
        if (rect.left >= 1680 && rect.top >= 272) {
            rect.left = 0;
            rect.top = 0;
        }
        sfSprite_setTextureRect(menu->background_sprite, rect);
        sfClock_restart(menu->bg_anim_clock);
    }
}

void background_menu_manager(menu_t *menu)
{
    bg_animation(menu);
}
