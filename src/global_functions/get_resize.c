/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** get_size
*/

#include "my.h"

sfVector2f get_mouse_pos(sfRenderWindow *window, sfVector2u window_size)
{
    sfVector2i __mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2u __window_pos = sfRenderWindow_getSize(window);

    return (sfVector2f){window_size.x * __mouse_pos.x / __window_pos.x,
                        window_size.y * __mouse_pos.y / __window_pos.y};
}

sfVector2f get_resize(sfRenderWindow *window, float x, float y)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f resize = {0.0, 0.0};

    resize.x = (x * window_size.x) / 1920.0;
    resize.y = (y * window_size.y) / 1080.0;
    return resize;
}
