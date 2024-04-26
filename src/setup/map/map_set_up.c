/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** map_set_up
*/

#include "my.h"

int set_up_map(map_t *map, sfRenderWindow *window)
{
    map->rect = (sfFloatRect) {0.0, get_resize(window, 495.0, 0).x,
                400.0, 200.0};
    map->texture = sfTexture_createFromFile(MAP_P, NULL);
    if (!map->texture)
        return KO;
    map->sprite = create_button(map->texture, (sfVector2f) {1.0, 1.0},
    (sfVector2f) {0.0, 0.0});
    map->view = sfView_create();
    map->view = sfView_createFromRect(map->rect);
    return OK;
}
