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

static int setup_flag(map_t *map, sfRenderWindow *window)
{
    map->is_flag = false;
    map->was_open = false;
    map->flag_pos = 300;
    map->flag_clock = sfClock_create();
    map->flag_text = sfTexture_createFromFile(FLAG, NULL);
    map->flag_zone = sfRectangleShape_create();
    if (!map->flag_text || !map->flag_zone)
        return KO;
    map->flag_font = sfFont_createFromFile(FONT);
    map->write_flag = create_text(map->flag_font,
    "Appuyer sur F pour\nSauver le village !", get_less_size(window, 20),
    (sfVector2f) {0.0, 0.0});
    
    map->flag_spr = create_button(map->flag_text, (sfVector2f) {0.5, 0.5},
    (sfVector2f) {0.0, 520.0});
    sfRectangleShape_setSize(map->flag_zone, (sfVector2f) {100.0, 35.0});
    sfRectangleShape_setPosition(map->flag_zone, (sfVector2f) {654.0, 236.0});
    sfRectangleShape_setFillColor(map->flag_zone, sfWhite);
    return OK;
}

int setup_map(map_t *map, sfRenderWindow *window)
{
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
