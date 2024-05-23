/*
** EPITECH PROJECT, 2024
** parallax.h
** File description:
** PARALLAX.h
*/

#ifndef PARALLAX_H
    #define PARALLAX_H
    #define SUCCESS 0
    #define ERROR 1
    #define EPITECH_ERROR 84
    #define NB_PARALLAX 4

    #include <SFML/Graphics.h>

typedef struct window_s {
    sfRenderWindow *window;
    sfClock *clock;
    sfTime time;
    float seconds;
} window_t;

typedef struct parallax_s {
    sfSprite *background_sprite;
    sfTexture *background_texture;
    sfSprite *sprites[NB_PARALLAX];
    sfTexture *textures[NB_PARALLAX];
    sfFont *font;
    sfText *parallax_text;
    float speeds[NB_PARALLAX];
} parallax_t;

#endif /* !PARALLAX_H */
