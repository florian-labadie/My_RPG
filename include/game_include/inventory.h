/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** inventory
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_

    #define INVENTORY_SIGN_PATH "assets/sprite/inventory_sign.png"
    #define INVENTORY_SLOTS_PATH "assets/sprite/inventory_slots.png"
    #define INVENTORY_STATS_PATH "assets/sprite/inventory_stats.png"

typedef struct inventory_t {
    sfRectangleShape *background;
    sfTexture **textures;
    sfSprite **sprites;
    sfText **text;
    sfText **stats_text;
} inventory_t;

#endif /* !INVENTORY_H_ */
