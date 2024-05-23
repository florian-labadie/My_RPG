/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** draw_game
*/

#include "my.h"

static void set_pos_flag(game_t *game, sfRenderWindow *window)
{
    sfSprite_setPosition(game->map->flag.flag_spr, get_resize(window,
    sfSprite_getPosition(game->player->sprites->player).x -
    game->map->flag.flag_pos,
    sfSprite_getPosition(game->player->sprites->player).y - 80));
    sfRenderWindow_drawSprite(window, game->map->flag.flag_spr, NULL);
}

static void set_pos_text_flag(game_t *game, sfRenderWindow *window)
{
    sfText_setPosition(game->map->flag.write_flag, get_resize(window,
    sfSprite_getPosition(game->player->sprites->player).x -
    (game->map->flag.flag_pos - 15),
    sfSprite_getPosition(game->player->sprites->player).y - 80));
    sfRenderWindow_drawText(window, game->map->flag.write_flag, NULL);
}

static void draw_help_flag(game_t *game, sfTime flag_time,
    sfRenderWindow *window)
{
    if (game->map->flag.is_flag == true) {
        game->map->flag.was_open = true;
        if (flag_time.microseconds > 10000 && game->map->flag.flag_pos > 210) {
            game->map->flag.flag_pos -= 2;
            sfClock_restart(game->map->flag.flag_clock);
        }
        set_pos_flag(game, window);
        set_pos_text_flag(game, window);
    }
}

void draw_flag(game_t *game, sfRenderWindow *window)
{
    sfTime flag_time = sfClock_getElapsedTime(game->map->flag.flag_clock);

    draw_help_flag(game, flag_time, window);
    if (game->map->flag.was_open == true && game->map->flag.is_flag == false) {
        if (flag_time.microseconds > 10000 && game->map->flag.flag_pos <=
        300) {
            game->map->flag.flag_pos += 2;
            sfClock_restart(game->map->flag.flag_clock);
        }
        set_pos_flag(game, window);
        set_pos_text_flag(game, window);
    if (game->map->flag.flag_pos >= 300)
        game->map->flag.was_open = false;
    }
}

static void check_pos(game_t *game, int i)
{
    if (game->map->particle.particle_rect[i].left >= 78)
        game->map->particle.particle_rect[i].left = 0;
    sfSprite_setPosition(game->map->particle.particule_spr[i], (sfVector2f)
    {sfSprite_getPosition(game->map->particle.particule_spr[i]).x,
    sfSprite_getPosition(game->map->particle.particule_spr[i]).y -
    rand() % 2});
    if (sfSprite_getPosition(game->map->particle.particule_spr[i]).y <= 172)
        sfSprite_setPosition(game->map->particle.particule_spr[i], (sfVector2f)
        {sfSprite_getPosition(game->map->particle.particule_spr[i]).x, 220.0});
}

static void particles_movement(game_t *game)
{
    if (game->map->particle.time_clock.microseconds > 100000) {
        for (int i = 0; i < NB_PARTICLE; i += 1) {
            game->map->particle.particle_rect[i].left += 6;
            check_pos(game, i);
        }
        sfClock_restart(game->map->particle.part_clock);
    }
}

void draw_particles(game_t *game, sfRenderWindow *window)
{
    game->map->particle.time_clock =
    sfClock_getElapsedTime(game->map->particle.part_clock);
    particles_movement(game);
    for (int i = 0; i < NB_PARTICLE; i += 1) {
        sfSprite_setTextureRect(game->map->particle.particule_spr[i],
        game->map->particle.particle_rect[i]);
        sfRenderWindow_drawSprite(window, game->map->particle.particule_spr[i],
        NULL);
    }
}
