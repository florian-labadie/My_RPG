/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** settings
*/

#ifndef SETTINGS_H_
    #define SETTINGS_H_

    #define OPEN_BOOK_P "assets/book_animation/book_1.png"
    #define NEXT_PAGE_P "assets/book_animation/book_2.png"
    #define PREVIOUS_PAGE_P "assets/book_animation/book_3.png"
    #define CLOSE_BOOK_P "assets/book_animation/book_4.png"
    #define RIGHT_ARROW_P "assets/book_animation/right_arrow.png"
    #define LEFT_ARROW_P "assets/book_animation/left_arrow.png"
    #define PLUS_SIGN_P "assets/book_animation/plus_sign.png"
    #define MINUS_SIGN_P "assets/book_animation/minus_sign.png"

    #define OPEN_BOOK_RECT ((sfIntRect) {-50, 0, 252, 297})
    #define TURN_PAGE_RECT ((sfIntRect) {-9, 0, 248, 297})
    #define CLOSE_BOOK_RECT ((sfIntRect) {-9, 0, 252, 297})
    #define RIGHT_ARROW_RECT ((sfIntRect) {1, 5, 123, 61})
    #define LEFT_ARROW_RECT ((sfIntRect) {1, 5, 123, 61})

typedef struct settings_s {
    sfTexture **book_textures;
    sfSprite **book_sprites;
    sfSprite **arrows_text;
    sfSprite **arrows_sprites;
    sfSprite *plus_sign;
    sfSprite *minus_sign;
    sfClock *book_clock;
} settings_t;

#endif /* !SETTINGS_H_ */
