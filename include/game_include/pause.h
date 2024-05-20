/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** pause
*/

#ifndef PAUSE_H_
    #define PAUSE_H_

    #define PAUSE_BUTTON_PATH "assets/button/pause_buttons.png"
    #define PAUSE_SIGN_RECT ((sfIntRect){205, 2, 64, 32})
    #define PAUSE_BUTTON_RECT ((sfIntRect){205, 78, 64, 23})

typedef struct pause_s {
    sfRectangleShape *background;
    sfFont *font;
    sfText **texts;
    sfTexture *textures;
    sfSprite **sprites;
} pause_t;

#endif /* !PAUSE_H_ */
