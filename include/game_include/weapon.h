/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** weapon
*/

#ifndef WEAPON_H_
    #define WEAPON_H_

    #include <SFML/Graphics.h>
    #define MAGIC_STAFF "assets/sprite/staff.png"
    #define SWORD "assets/sprite/sword.png"
    #define GANTS "assets/sprite/Gants.png"
    #define WEAP_SIGN "assets/sprite/pancarte_shop.png"
    #define POTION "assets/sprite/potions.png"

typedef struct weapon_s {
    sfTexture *texture_weap;
    sfSprite *sprite_weap;
    sfText **text;
    sfFont *font;

    sfRectangleShape **zone_text;
} weapon_t;

typedef struct potion_s {
    sfTexture *texture_pot;
    sfSprite *sprite;
    sfText **text;
    sfFont *font;

    sfRectangleShape **zone_text;
} potion_t;

typedef struct shop_s {
    sfTexture *texture_sign;
    sfSprite **sprite_sign;
    sfTexture *texture_quitt;
    sfSprite **sprite_quitt;

    weapon_t **weapon;
    potion_t *potion;
} shop_t;

#endif /* !WEAPON_H_ */
