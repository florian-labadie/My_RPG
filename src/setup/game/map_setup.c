/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** map_set_up
*/

#include "my.h"

static int house_loop(map_t *map, sfRenderWindow *window)
{
    for (int i = 0; i < 2; i += 1) {
        map->house[i]->house = create_button(map->house[i]->house_texture,
            (sfVector2f){1.0, 1.0}, get_resize(window, 960, 540));
        map->house[i]->house_music = sfMusic_createFromFile(SHOP_MUSIC);
        sfMusic_setLoop(map->house[i]->house_music, sfTrue);
        if (!map->house[i]->house_music)
            return KO;
        map->house[i]->house_text = sfText_create();
        map->house[i]->house_font = sfFont_createFromFile(FONT);
        set_sprite_mid_origin(map->house[i]->house);
    }
    return OK;
}

int setup_house(map_t *map, sfRenderWindow *window)
{
    map->house[0] = malloc(sizeof(house_t));
    map->house[1] = malloc(sizeof(house_t));
    map->house[0]->house_texture = sfTexture_createFromFile(FORGE_MAP, NULL);
    map->house[1]->house_texture = sfTexture_createFromFile(ALCHEMY_MAP, NULL);
    map->house[2] = NULL;
    if (!map->house[0]->house_texture || !map->house[1]->house_texture ||
        house_loop(map, window) == KO)
        return KO;
    sfSprite_setScale(map->house[0]->house, (sfVector2f){1.94, 1.94});
    sfSprite_setScale(map->house[1]->house, (sfVector2f){1.56, 1.56});
    return OK;
}

int set_up_battlefield(sfRenderWindow *window, map_t *map, float volume)
{
    map->battle_text = sfTexture_createFromFile(BATTLE_MAP, NULL);
    if (!map->battle_text)
        return KO;
    sfMusic_setVolume(map->battle_music, volume);
    map->battle_spr = create_button(map->battle_text,
    (sfVector2f) {1.0, 1.0}, get_resize(window, 0.0, 0.0));
    return OK;
}

static int setup_map_object_with_file(map_t *map)
{
    map->texture_ground = sfTexture_createFromFile(MAP_P, NULL);
    map->texture_obj = sfTexture_createFromFile(MAP_OBJ, NULL);
    map->layers = sfImage_createFromFile(LAYER_MAP);
    map->game_sound = sfMusic_createFromFile(AMB_MUSIC);
    map->battle_music = sfMusic_createFromFile(BATTLE_MUSIC);
    if (!map->texture_ground || !map->texture_obj || !map->layers ||
        !map->game_sound || !map->battle_music)
        return KO;
    return OK;
}

int setup_map(map_t *map, sfRenderWindow *window, float volume)
{
    (void)volume;
    map->choice_map = VILLAGE;
    if (setup_map_object_with_file(map) == KO)
        return KO;
    map->rect = (sfFloatRect) {0.0, get_resize(window, 495.0, 0).x,
        400.0, 200.0};
    map->view = sfView_createFromRect(map->rect);
    map->sprite_ground = create_button(map->texture_ground,
                (sfVector2f){1.0, 1.0}, (sfVector2f){0.0, 0.0});
    map->sprite_obj = create_button(map->texture_obj, (sfVector2f) {1.0, 1.0},
    (sfVector2f) {0.0, 0.0});
    sfMusic_setLoop(map->game_sound, sfTrue);
    sfMusic_setLoop(map->battle_music, sfTrue);
    if (setup_particles(map) == KO || setup_flag(map, window) == KO ||
        entities_setup(&(map->entities), window) == KO)
        return KO;
    return OK;
}
