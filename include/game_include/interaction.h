/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** interaction
*/

#ifndef INTERACTION_H_
    #define INTERACTION_H_

    #include <SFML/Graphics.h>

typedef enum shop_interac_s {
    QUITT,
    BUY,
    NB_OF_TEXT
} shop_interac_t;

typedef struct interaction_s {
    sfTexture **texture;
    sfSprite **sprite;
    sfText **text;
    sfFont *font;

    sfRectangleShape ***zone_text;
    choice_map_t *field;
    shop_interac_t shop;
} interaction_t;

#endif /* !INTERACTION_H_ */
