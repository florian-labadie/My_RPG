/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** reset_view
*/

#include "my.h"

void reset_view(sfView *view, sfRenderWindow *window, sfVector2f pos)
{
    sfView_setSize(view, get_resize(window, pos.x, pos.y));
    sfView_setCenter(view, get_resize(window, pos.x / 2, pos.y / 2));
    sfRenderWindow_setView(window, view);
}
