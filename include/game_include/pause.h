/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** pause
*/

#ifndef PAUSE_H_
    #define PAUSE_H_

    #define PAUSE_SIGN_PATH "assets/button/green_sign.png"
    #define PAUSE_BUTTON_PATH "assets/button/green_button.png"
    #define PAUSE_SIGN_RECT ((sfIntRect){0, 0, 64, 32})
    #define PAUSE_BUTTON_RECT ((sfIntRect){0, 0, 64, 32})

typedef struct pause_s {
    sfRectangleShape *background;
    sfFont *font;
    sfText **text;
    sfTexture **textures;

    sfSprite **sprites;
    button_state_t *buttons_status;
} pause_t;

#endif /* !PAUSE_H_ */
