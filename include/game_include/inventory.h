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
    #define SLOTH_HEALTH ((sfIntRect){72, 21, 176, 249})
    #define SLOTH_MANA ((sfIntRect){40, 375, 238, 287})
    #define SWORD_NORM ((sfIntRect){0, 82, 624, 494})
    #define SWORD_EPIC ((sfIntRect){0, 582, 624, 513})
    #define SWORD_LEG ((sfIntRect){0, 1084, 624, 531})
    #define GANTS_NORM ((sfIntRect){0, 0, 43, 34})
    #define GANTS_EPIC ((sfIntRect){0, 35, 43, 36})
    #define GANTS_LEG ((sfIntRect){0, 68, 43, 38})
    #define STAFF_NORM ((sfIntRect){0, 0, 14, 18})
    #define STAFF_EPIC ((sfIntRect){0, 18, 14, 18})
    #define STAFF_LEG ((sfIntRect){0, 36, 14, 18})

typedef struct item_s {
    sfTexture **texture;
    sfSprite **health_pot;
    sfSprite **mana_pot;
    sfSprite ***weapons;
} item_t;

typedef struct inventory_t {
    sfRectangleShape *background;
    sfTexture **textures;
    sfSprite **sprites;
    sfText **text;

    int nbr_health_pot;
    int nbr_mana_pot;

    item_t *item;
    sfText **stats_text;
} inventory_t;

#endif /* !INVENTORY_H_ */
