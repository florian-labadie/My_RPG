/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** map_set_up
*/

#include "my.h"

static sfIntRect *setup_begin(sfIntRect *begin)
{
    int index = 0;

    for (int i = 0; index < NB_PARTICLE; i += 6) {
        begin[index] = (sfIntRect) {i, 0, 6, 6};
        index += 1;
    }
    return begin;
}

static int setup_particles(map_t *map)
{
    sfVector2f pos = (sfVector2f) {665.0, 220.0};

    map->particle_rect = malloc(sizeof(sfIntRect) * NB_PARTICLE);
    map->particle_rect = setup_begin(map->particle_rect);
    map->part_clock = sfClock_create();
    map->time_clock = sfClock_getElapsedTime(map->part_clock);
    map->particle_text = sfTexture_createFromFile(PARTICLE, NULL);
    if (!map->particle_text)
        return KO;
    map->particule_spr = malloc(sizeof(sfSprite *) * NB_PARTICLE);
    for (int i = 0; i < NB_PARTICLE; i += 1) {
        map->particule_spr[i] = create_button(map->particle_text, (sfVector2f)
        {1.5, 1.5}, (sfVector2f) {pos.x + rand() % 35, pos.y - rand() % 50});
        sfSprite_setTextureRect(map->particule_spr[i], map->particle_rect[i]);
    }
    return OK;
}

int setup_map(map_t *map, sfRenderWindow *window)
{
    map->rect = (sfFloatRect) {0.0, get_resize(window, 495.0, 0).x,
                400.0, 200.0};
    map->texture_ground = sfTexture_createFromFile(MAP_P, NULL);
    map->texture_obj = sfTexture_createFromFile(MAP_OBJ, NULL);
    map->game_sound = sfMusic_createFromFile(AMB_MUSIC);
    if (!map->texture_ground)
        return KO;
    map->sprite_ground = create_button(map->texture_ground,
                (sfVector2f){1.0, 1.0}, (sfVector2f){0.0, 0.0});
    map->sprite_obj = create_button(map->texture_obj, (sfVector2f) {1.0, 1.0},
    (sfVector2f) {0.0, 0.0});
    map->view = sfView_createFromRect(map->rect);
    sfMusic_setLoop(map->game_sound, sfTrue);
    if (setup_particles(map) == KO)
        return KO;
    return OK;
}
