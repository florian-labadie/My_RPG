/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** background_player_setup
*/

#include "my.h"

static int setup_human_bg(menu_t *menu)
{
    menu->human_texture = sfTexture_createFromFile(PLAYER, NULL);
    menu->human_sprites = create_button(menu->human_texture,
        (sfVector2f) {1, 1}, (sfVector2f) {-20, 962});
    menu->human_anim_clock = sfClock_create();
    if (!menu->human_texture || !menu->human_sprites ||
        !menu->human_anim_clock)
        return KO;
    sfSprite_setTextureRect(menu->human_sprites, HUMAN_RECT);
    return OK;
}

static int setup_elf_bg(menu_t *menu)
{
    menu->elf_texture = sfTexture_createFromFile(PLAYER, NULL);
    menu->elf_sprites = create_button(menu->elf_texture,
        (sfVector2f) {1, 1}, (sfVector2f) {-100, 956});
    menu->elf_anim_clock = sfClock_create();
    if (!menu->elf_texture || !menu->elf_sprites || !menu->elf_anim_clock)
        return KO;
    sfSprite_setTextureRect(menu->elf_sprites, ELF_RECT);
    return OK;
}

static int setup_dwarf_bg(menu_t *menu)
{
    menu->dwarf_texture = sfTexture_createFromFile(PLAYER, NULL);
    menu->dwarf_sprites = create_button(menu->dwarf_texture,
        (sfVector2f) {0.9, 0.9}, (sfVector2f) {-180, 965});
    menu->dwarf_anim_clock = sfClock_create();
    if (!menu->dwarf_texture || !menu->dwarf_sprites ||
        !menu->dwarf_anim_clock)
        return KO;
    sfSprite_setTextureRect(menu->dwarf_sprites, DWARF_RECT);
    return OK;
}

int background_player_setup(menu_t *menu)
{
    if (setup_dwarf_bg(menu) == KO || setup_elf_bg(menu) == KO ||
        setup_human_bg(menu) == KO)
        return KO;
    return OK;
}
