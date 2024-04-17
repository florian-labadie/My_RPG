/*
** EPITECH PROJECT, 2024
** paint
** File description:
** create_button
*/

#include "my.h"

sfSprite *create_button(sfTexture *texture, sfVector2f scale, sfVector2f pos)
{
    sfSprite *button_sprite = sfSprite_create();

    sfSprite_setTexture(button_sprite, texture, sfTrue);
    sfSprite_setPosition(button_sprite, pos);
    sfSprite_setScale(button_sprite, scale);
    return button_sprite;
}
