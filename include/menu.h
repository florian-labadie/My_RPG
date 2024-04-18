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
    #define BUTTON_PANEL "assets/button/wood_button.png"
    #define BUTTON_MENU "assets/button/button.png"
    #define FONT "assets/Font/game_over.ttf"
    #define BG_RECT ((sfIntRect) {0, 0, 560, 272})
    #define RECTANGLE_RECT ((sfIntRect) {0.0, 0.0, 748.0, 287.0})
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
    sfTexture *rectangle_text;
    sfFont *font;

    sfSprite **sprite;
    sfText **text;
    char **button_name;
    sfIntRect rectangle_rect;
    sfSprite **play_sprite;
} button_t;

typedef struct menu_s {
    main_menu_t screen;

    sfMusic *menu_sound;

    sfSprite *background_sprite;
    sfTexture *background_texture;
    sfClock *bg_anim_clock;
    button_t *button;

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

int menu_button(button_t *button);

#endif /* !MENU_H_ */
