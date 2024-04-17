/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** menu
*/

#ifndef MENU_H_
    #define MENU_H_

    #include "rpg.h"

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #define BACKGROUND "assets/sprite/background_menu.png"
    #define BUTTON_OPTION "assets/button/option.png"
    #define BUTTON_PANEL "assets/button/wood_button.png"
    #define FONT "assets/Font/game_over.ttf"
    #define BG_RECT ((sfIntRect) {0, 0, 560, 272})
    #define RECTANGLE_RECT ((sfIntRect) {15, 160, 150, 65})

typedef struct button_s {
    sfTexture *rectangle_text;
    sfFont *font;

    char **button_name;
    sfIntRect rectangle_rect;
    sfSprite **play_sprite;
    sfText **text;
} button_t;

typedef struct menu_s {
    char *user;

    sfMusic *menu_sound;
    sfSprite *background_sprite;
    sfTexture *background_texture;
    sfClock *bg_anim_clock;
    button_t *button;
} menu_t;

int menu_button(button_t *button);

#endif /* !MENU_H_ */
