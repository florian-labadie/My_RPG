/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** settings
*/

#ifndef SETTINGS_H_
    #define SETTINGS_H_

typedef struct settings_s {
    sfTexture *open_book;
    sfSprite *open_book_spr;
    sfClock *book_clock;
    sfIntRect rect;
} settings_t;

#endif /* !SETTINGS_H_ */
