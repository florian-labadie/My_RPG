/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** bounds_functions
*/

#include "my.h"

bool get_sprite_bounds(sfSprite *sprite, sfVector2f pos)
{
    sfFloatRect b = {-100, -100, -100, -100};
    sfBool contains = sfFalse;

    if (!sprite)
        return sfFalse;
    b = sfSprite_getGlobalBounds(sprite);
    contains = sfFloatRect_contains(&b, pos.x, pos.y);
    return contains;
}

bool get_rectangle_bounds(sfRectangleShape *rectangle, sfVector2f pos)
{
    sfFloatRect b = {-100, -100, -100, -100};
    sfBool contains = sfFalse;

    if (!rectangle)
        return sfFalse;
    b = sfRectangleShape_getGlobalBounds(rectangle);
    contains = sfFloatRect_contains(&b, pos.x, pos.y);
    return contains;
}
