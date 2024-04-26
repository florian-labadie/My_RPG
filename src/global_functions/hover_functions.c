/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** hover_functions
*/

#include "my.h"

void set_rect_button(sfSprite *button, button_state_t status)
{
    sfIntRect rect = {0, 0, 0, 0};

    rect = sfSprite_getTextureRect(button);
    rect.left = rect.width * (int)status;
    sfSprite_setTextureRect(button, rect);
}

void change_button_rect(sfSprite *sprite, button_state_t *changed_status,
    button_state_t status, sfSound *sound)
{
    *changed_status = status;
    if (sound && (sfSound_getStatus(sound) == sfStopped ||
        sfSound_getStatus(sound) == sfPaused) && *changed_status == PRESSED) {
        sfSound_play(sound);
    }
    set_rect_button(sprite, status);
}
