/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** background_player_manager
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

static void bg_animation_human(menu_t *menu)
{
    sfIntRect rect = {0, 0, 0, 0};

    if (!menu)
        return;
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(menu->human_anim_clock)) > 100) {
        player_mouvement(menu->human_sprites);
        rect = sfSprite_getTextureRect(menu->human_sprites);
        rect.left += 52;
        if (rect.left >= 416)
            rect.left = 208;
        sfSprite_setTextureRect(menu->human_sprites, rect);
        sfClock_restart(menu->human_anim_clock);
    }
}

static void bg_animation_elf(menu_t *menu)
{
    sfIntRect rect = {0, 0, 0, 0};

    if (!menu)
        return;
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(menu->elf_anim_clock)) > 100) {
        player_mouvement(menu->elf_sprites);
        rect = sfSprite_getTextureRect(menu->elf_sprites);
        rect.left += 52;
        if (rect.left >= 416)
            rect.left = 212;
        sfSprite_setTextureRect(menu->elf_sprites, rect);
        sfClock_restart(menu->elf_anim_clock);
    }
}

static void bg_animation_dwarf(menu_t *menu)
{
    sfIntRect rect = {0, 0, 0, 0};

    if (!menu)
        return;
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(menu->dwarf_anim_clock)) > 100) {
        player_mouvement(menu->dwarf_sprites);
        rect = sfSprite_getTextureRect(menu->dwarf_sprites);
        rect.left += 52;
        if (rect.left >= 416)
            rect.left = 156;
        sfSprite_setTextureRect(menu->dwarf_sprites, rect);
        sfClock_restart(menu->dwarf_anim_clock);
    }
}

void background_player_manager(menu_t *menu)
{
    bg_animation_dwarf(menu);
    bg_animation_elf(menu);
    bg_animation_human(menu);
}