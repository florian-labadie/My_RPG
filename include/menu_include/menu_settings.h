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

    #define OPEN_BOOK_RECT ((sfIntRect) {-50, 0, 252, 297})
    #define TURN_PAGE_RECT ((sfIntRect) {-9, 0, 248, 297})
    #define CLOSE_BOOK_RECT ((sfIntRect) {-9, 0, 252, 297})

typedef struct settings_s {
    sfTexture **book_textures;
    sfSprite **book_sprites;
    sfClock *book_clock;
} settings_t;

#endif /* !SETTINGS_H_ */
