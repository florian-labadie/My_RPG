/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** background_menu_manager
*/

#include "my.h"

static void player_mouvement(sfSprite *sprite)
{
    int y_pos = sfSprite_getPosition(sprite).y;

    if (sfSprite_getPosition(sprite).x < 2000) {
        sfSprite_move(sprite, (sfVector2f){8, 0});
    } else {
        sfSprite_setPosition(sprite, (sfVector2f){-60, y_pos});
    }
}

static void bg_animation_human(background_menu_t *background, int i)
{
    sfIntRect rect = {0, 0, 0, 0};

    player_mouvement(background->characters[i]);
    rect = sfSprite_getTextureRect(background->characters[i]);
    rect.left += 52;
    if (rect.left >= 416)
        rect.left = 210;
    sfSprite_setTextureRect(background->characters[i], rect);
}

static void bg_animation_dwarf(background_menu_t *background, int i)
{
    sfIntRect rect = {0, 0, 0, 0};

    player_mouvement(background->characters[i]);
    rect = sfSprite_getTextureRect(background->characters[i]);
    rect.left += 52;
    if (rect.left >= 416)
        rect.left = 156;
    sfSprite_setTextureRect(background->characters[i], rect);
}

static void bg_animation_elf(background_menu_t *background, int i)
{
    sfIntRect rect = {0, 0, 0, 0};

    player_mouvement(background->characters[i]);
    rect = sfSprite_getTextureRect(background->characters[i]);
    rect.left += 52;
    if (rect.left >= 416)
        rect.left = 212;
    sfSprite_setTextureRect(background->characters[i], rect);
}

static void bg_animation(background_menu_t *background)
{
    sfIntRect rect = {0, 0, 0, 0};

    rect = sfSprite_getTextureRect(background->background_sprite);
    rect.left += 560;
    if (rect.left >= 2800) {
        rect.left = 0;
        rect.top += 272;
    }
    if (rect.left >= 1680 && rect.top >= 272) {
        rect.left = 0;
        rect.top = 0;
    }
    sfSprite_setTextureRect(background->background_sprite, rect);
}

void background_menu_manager(menu_t *menu)
{
    if (!menu)
        return;
    if (sfTime_asMilliseconds(sfClock_getElapsedTime
        (menu->background->bg_anim_clock)) > 100) {
        bg_animation(menu->background);
        bg_animation_human(menu->background, 0);
        bg_animation_dwarf(menu->background, 1);
        bg_animation_elf(menu->background, 2);
        sfClock_restart(menu->background->bg_anim_clock);
    }
}
