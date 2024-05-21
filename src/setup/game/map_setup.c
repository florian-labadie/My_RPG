/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** map_set_up
*/

#include "my.h"

static int set_up_battlefield(map_t *map, float volume)
{
    map->battle_text = sfTexture_createFromFile(BATTLE_MAP, NULL);
    if (!map->battle_text)
        return KO;
    sfMusic_setVolume(map->battle_music, volume);
    map->battle_spr = create_button(map->battle_text,
    (sfVector2f) {1.0, 1.0}, (sfVector2f) {0.0, 0.0});
    return OK;
}

int setup_map(map_t *map, sfRenderWindow *window, float volume)
{
    map->choice_map = VILLAGE;
    map->rect = (sfFloatRect) {0.0, get_resize(window, 495.0, 0).x,
                400.0, 200.0};
    map->texture_ground = sfTexture_createFromFile(MAP_P, NULL);
    map->texture_obj = sfTexture_createFromFile(MAP_OBJ, NULL);
    map->layers = sfImage_createFromFile(LAYER_MAP);
    map->game_sound = sfMusic_createFromFile(AMB_MUSIC);
    map->battle_music = sfMusic_createFromFile(BATTLE_MUSIC);
    if (!map->texture_ground || !map->game_sound || !map->battle_music)
        return KO;
    map->sprite_ground = create_button(map->texture_ground,
                (sfVector2f){1.0, 1.0}, (sfVector2f){0.0, 0.0});
    map->sprite_obj = create_button(map->texture_obj, (sfVector2f) {1.0, 1.0},
    (sfVector2f) {0.0, 0.0});
    map->view = sfView_createFromRect(map->rect);
    sfMusic_setLoop(map->game_sound, sfTrue);
    sfMusic_setLoop(map->battle_music, sfTrue);
    if (setup_particles(map) == KO || setup_flag(map, window) == KO)
        return KO;
    if (set_up_battlefield(map, volume) == KO)
        return KO;
    return OK;
}
