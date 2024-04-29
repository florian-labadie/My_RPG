/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** map_set_up
*/

#include "my.h"

int set_up_map(map_t *map, sfRenderWindow *window)
{
    map->move_vect = (sfVector2f) {0.0, 0.0};
    map->rect = (sfFloatRect) {0.0, get_resize(window, 495.0, 0).x,
                400.0, 200.0};
    map->texture_ground = sfTexture_createFromFile(MAP_P, NULL);
    map->texture_obj = sfTexture_createFromFile(MAP_OBJ, NULL);
    map->game_sound = sfMusic_createFromFile(AMB_MUSIC);
    if (!map->texture_ground)
        return KO;
    map->sprite_ground = create_button(map->texture_ground, (sfVector2f) {1.0, 1.0},
    (sfVector2f) {0.0, 0.0});
    map->sprite_obj = create_button(map->texture_obj, (sfVector2f) {1.0, 1.0},
    (sfVector2f) {0.0, 0.0});
    map->view = sfView_createFromRect(map->rect);
    sfMusic_setLoop(map->game_sound, sfTrue);
    return OK;
}
