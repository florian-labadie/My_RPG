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

int setup_particles(map_t *map)
{
    sfVector2f pos = (sfVector2f) {665.0, 220.0};

    map->particle.particle_rect = malloc(sizeof(sfIntRect) * NB_PARTICLE);
    map->particle.particle_rect = setup_begin(map->particle.particle_rect);
    map->particle.part_clock = sfClock_create();
    map->particle.time_clock =
    sfClock_getElapsedTime(map->particle.part_clock);
    map->particle.particle_text = sfTexture_createFromFile(PARTICLE, NULL);
    if (!map->particle.particle_text)
        return KO;
    map->particle.particule_spr = malloc(sizeof(sfSprite *) * NB_PARTICLE);
    for (int i = 0; i < NB_PARTICLE; i += 1) {
        map->particle.particule_spr[i] =
        create_button(map->particle.particle_text, (sfVector2f)
        {1.5, 1.5}, (sfVector2f) {pos.x + rand() % 35, pos.y - rand() % 50});
        sfSprite_setTextureRect(map->particle.particule_spr[i],
        map->particle.particle_rect[i]);
    }
    return OK;
}

int setup_flag(map_t *map, sfRenderWindow *window)
{
    map->flag.is_flag = false;
    map->flag.was_open = false;
    map->flag.flag_pos = 300;
    map->flag.flag_clock = sfClock_create();
    map->flag.flag_text = sfTexture_createFromFile(FLAG, NULL);
    map->flag.flag_zone = sfRectangleShape_create();
    if (!map->flag.flag_text || !map->flag.flag_zone)
        return KO;
    map->flag.flag_font = sfFont_createFromFile(FONT);
    map->flag.write_flag = create_text(map->flag.flag_font,
    "Appuyer sur F pour\nSauver le village !", get_less_size(window, 20),
    (sfVector2f) {0.0, 0.0});
    map->flag.flag_spr = create_button(map->flag.flag_text,
    (sfVector2f) {0.5, 0.5}, (sfVector2f) {0.0, 520.0});
    sfRectangleShape_setSize(map->flag.flag_zone, (sfVector2f) {100.0, 35.0});
    sfRectangleShape_setPosition(map->flag.flag_zone,
    (sfVector2f) {654.0, 236.0});
    sfRectangleShape_setFillColor(map->flag.flag_zone, sfWhite);
    return OK;
}
