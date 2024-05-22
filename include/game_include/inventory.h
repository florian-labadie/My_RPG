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

static const sfVector2f inventory_pos[3] =
{{960, 120}, {480, 270}, {1440, 810}};

typedef struct inventory_t {
    sfRectangleShape *background;
    sfTexture **textures;
    sfSprite **sprites;
    sfText *text;
} inventory_t;

#endif /* !INVENTORY_H_ */
