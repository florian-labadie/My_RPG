/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** map_set_up
*/

#include "my.h"

int setup_house(map_t *map, sfRenderWindow *window)
{
    map->house[0] = malloc(sizeof(house_t));
    map->house[1] = malloc(sizeof(house_t));
    map->house[2] = malloc(sizeof(house_t));
    map->house[0]->house_texture = sfTexture_createFromFile(FORGE_MAP, NULL);
    map->house[1]->house_texture = sfTexture_createFromFile(ALCHEMY_MAP, NULL);
    map->house[2]->house_texture = NULL;
    if (!map->house[0]->house_texture || !map->house[1]->house_texture)
        return 84;
    for (int i = 0; i < 2; i += 1) {
        map->house[i]->house = create_button(map->house[i]->house_texture,
            (sfVector2f){1.0, 1.0}, (sfVector2f){0.0, 0.0});
        map->house[i]->house_music = sfMusic_createFromFile(SHOP_MUSIC);
        if (!map->house[i]->house_music)
            return 84;
        map->house[i]->house_text = sfText_create();
        map->house[i]->house_font = sfFont_createFromFile(FONT);
    }
}

int setup_map(map_t *map, sfRenderWindow *window)
{
    map->choice_map = VILLAGE;
    map->rect = (sfFloatRect) {0.0, get_resize(window, 495.0, 0).x,
                400.0, 200.0};
    map->texture_ground = sfTexture_createFromFile(MAP_P, NULL);
    map->texture_obj = sfTexture_createFromFile(MAP_OBJ, NULL);
    map->layers = sfImage_createFromFile(LAYER_MAP);
    map->game_sound = sfMusic_createFromFile(AMB_MUSIC);
    if (!map->texture_ground)
        return KO;
    map->sprite_ground = create_button(map->texture_ground,
                (sfVector2f){1.0, 1.0}, (sfVector2f){0.0, 0.0});
    map->sprite_obj = create_button(map->texture_obj, (sfVector2f) {1.0, 1.0},
    (sfVector2f) {0.0, 0.0});
    map->view = sfView_createFromRect(map->rect);
    sfMusic_setLoop(map->game_sound, sfTrue);
    if (setup_particles(map) == KO || setup_flag(map, window) == KO)
        return KO;
    return OK;
}
