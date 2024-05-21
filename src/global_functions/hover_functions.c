/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** hover_functions
*/

#include "my.h"

int already_pressed(button_state_t *button_status, int size)
{
    for (int i = 0; i < size; i++) {
        if (button_status[i] == BUTTON_PRESSED)
            return OK;
    }
    return KO;
}

static void set_rect_button(sfSprite *button, button_state_t status)
{
    sfIntRect rect = {0, 0, 0, 0};

    rect = sfSprite_getTextureRect(button);
    rect.left = rect.width * (int)status;
    sfSprite_setTextureRect(button, rect);
}

int change_button_rect(sfSprite *sprite, button_state_t *changed_status,
    button_state_t status, sfSound *sound)
{
    if (!sprite || !changed_status)
        return KO;
    *changed_status = status;
    if (sound && (sfSound_getStatus(sound) == sfStopped || sfSound_getStatus
                (sound) == sfPaused) && *changed_status == BUTTON_PRESSED) {
        sfSound_play(sound);
    }
    set_rect_button(sprite, status);
    return OK;
}
