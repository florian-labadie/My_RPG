/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** menu
*/

#ifndef MENU_H_
    #define MENU_H_

    #include "help.h"
    #include "settings.h"

    #include <SFML/Audio.h>

    #define BACKGROUND "assets/sprite/background_menu.png"
    #define PLAYER "assets/sprite/main_character.png"
    #define BUTTON_OPTION "assets/button/option.png"
    #define BG_RECT ((sfIntRect) {0, 0, 560, 272})
    #define DWARF_RECT ((sfIntRect) {156, 110, 52, 60})
    #define ELF_RECT ((sfIntRect) {212, 228, 52, 62})//{212, 228, 264, 292})
    #define HUMAN_RECT ((sfIntRect) {208, 0, 52, 56})

typedef enum main_menu_s {
    MAIN,
    HELP,
    SETTING,
    MAIN_MENU_STATE_SIZE
} main_menu_t;

typedef struct button_s {
    sfTexture *texture;

    sfSprite **sprite;
    sfText **text;
} button_t;

typedef struct menu_s {
    main_menu_t screen;

    sfMusic *menu_sound;

    sfSprite *background_sprite;
    sfTexture *background_texture;
    sfClock *bg_anim_clock;

    help_t *help;
    settings_t *settings;


    sfSprite *dwarf_sprites;
    sfTexture *dwarf_texture;
    sfClock *dwarf_anim_clock;
    sfSprite *elf_sprites;
    sfTexture *elf_texture;
    sfClock *elf_anim_clock;
    sfSprite *human_sprites;
    sfTexture *human_texture;
    sfClock *human_anim_clock;
} menu_t;

#endif /* !MENU_H_ */
