/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** hover_functions
*/

#include "my.h"

void set_hover_button(main_menu_buttons_t *button, int i)
{
    sfIntRect rect = {0, 0, 0, 0};

    rect = sfSprite_getTextureRect(button->sprites[i]);
    rect.left += 748;
    if (rect.left >= 2244)
        rect.left = 0;
    sfSprite_setTextureRect(button->sprites[i], rect);
}
