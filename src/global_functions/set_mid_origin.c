/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** set_mid_origin
*/

#include "my.h"

void set_sprite_mid_origin(sfSprite *sprite)
{
    sfFloatRect rect = {0, 0, 0, 0};

    rect = sfSprite_getGlobalBounds(sprite);
    sfSprite_setOrigin(sprite, (sfVector2f){rect.width / 2, rect.height / 2});
}

void set_sprite_button_mid_origin(sfSprite *sprite)
{
    sfFloatRect rect = {0, 0, 0, 0};

    rect = sfSprite_getGlobalBounds(sprite);
    sfSprite_setOrigin(sprite, (sfVector2f){rect.width / 6, rect.height / 2});
}

void set_text_mid_origin(sfText *text)
{
    sfFloatRect rect = {0, 0, 0, 0};

    rect = sfText_getGlobalBounds(text);
    sfText_setOrigin(text, (sfVector2f){rect.width / 2, rect.height / 2});
}
