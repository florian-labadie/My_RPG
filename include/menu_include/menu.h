/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** menu
*/

#ifndef MENU_H_
    #define MENU_H_

    #include <SFML/Audio.h>

    #include "main_menu.h"
    #include "help.h"
    #include "menu_settings.h"
    #include "parallax.h"

    #define BACKGROUND "assets/sprite/background_menu.png"
    #define WOS_SIGN "assets/sprite/tropical_button.png"
    #define PLAYER "assets/sprite/main_character.png"
    #define BUTTON_OPTION "assets/button/option.png"
    #define BUTTON_PANEL "assets/button/wood_button.png"
    #define BUTTON_MENU "assets/button/button.png"
    #define FONT "assets/Font/game_over.ttf"
    #define TITLE_FONT "assets/Font/GAMERIA.ttf"
    #define MUSIC_MENU "assets/music/menu_music.ogg"
    #define SOUND_CLICK_BUTTON "assets/music/tap_sound.ogg"
    #define HELP_BOOK "assets/button/help_book.png"
    #define BG_RECT ((sfIntRect){0, 0, 560, 272})
    #define BUTTON_RECT ((sfIntRect){0, 0, 748, 287})
    #define HUMAN_RECT ((sfIntRect){210, 0, 52, 56})
    #define DWARF_RECT ((sfIntRect){209, 112, 52, 57})
    #define ELF_RECT ((sfIntRect){210, 226, 52, 62})
    #define BACK_HELP ((sfIntRect){275, 261, 51, 57})

typedef enum menu_state_s {
    PARALLAX,
    MAIN,
    HELP,
    SETTING,
    MAIN_MENU_STATE_SIZE
} menu_state_t;

typedef struct background_menu_s {
    sfClock *bg_anim_clock;

    sfSprite *background_sprite;
    sfTexture *background_texture;

    sfTexture *characters_texture;
    sfSprite **characters;
} background_menu_t;

typedef struct menu_s {
    menu_state_t screen;

    sfMusic *menu_sound;
    sfSound *click_button_sound;
    sfSoundBuffer *sound_buffer;

    background_menu_t *background;

    main_menu_t *main_menu;
    help_t *help;
    settings_t *settings;
    parallax_t *parallax;
} menu_t;

#endif /* !MENU_H_ */
