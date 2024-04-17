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
    #define BG_RECT ((sfIntRect) {0, 0, 560, 272})

typedef struct button_s {
    sfSprite *sprite;
    sfTexture *texture;

    sfIntRect texture_rect;
    sfClock *anim_clock;
} button_t;

typedef struct menu_s {
    char *user;

    sfMusic *menu_sound;
    sfSprite *background_sprite;
    sfTexture *background_texture;
    sfClock *bg_anim_clock;
} menu_t;

#endif /* !MENU_H_ */
