/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** main_menu
*/

#ifndef MAIN_MENU_H_
    #define MAIN_MENU_H_

    #include <SFML/Graphics.h>

typedef struct main_menu_buttons_s {
    sfTexture *rectangle_text;
    sfFont *font;

    button_state_t *buttons_status;
    sfSprite **sprites;
    sfText **text;

    sfTexture *help_book;
    sfSprite *help_book_spr;
    sfTexture *help_back;
    sfSprite *help_back_spr;
} main_menu_buttons_t;

typedef struct main_menu_s {
    sfTexture *wos_text;
    sfSprite *wos_sprite;
    sfText *wos;

    main_menu_buttons_t *buttons;
} main_menu_t;

#endif /* !MAIN_MENU_H_ */
