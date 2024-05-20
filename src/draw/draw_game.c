/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** draw_game
*/

#include "my.h"

static void check_pos(game_t *game, int i)
{
    if (game->map->particle_rect[i].left >= 78)
        game->map->particle_rect[i].left = 0;
    sfSprite_setPosition(game->map->particule_spr[i], (sfVector2f)
    {sfSprite_getPosition(game->map->particule_spr[i]).x,
    sfSprite_getPosition(game->map->particule_spr[i]).y - rand() % 2});
    if (sfSprite_getPosition(game->map->particule_spr[i]).y <= 172)
        sfSprite_setPosition(game->map->particule_spr[i], (sfVector2f)
        {sfSprite_getPosition(game->map->particule_spr[i]).x, 220.0});
}

static void particles_movement(game_t *game)
{
    if (game->map->time_clock.microseconds > 100000) {
        for (int i = 0; i < NB_PARTICLE; i += 1) {
            game->map->particle_rect[i].left += 6;
            check_pos(game, i);
        }
        sfClock_restart(game->map->part_clock);
    }
}

static void draw_pause_menu(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_drawRectangleShape(window, game->pause->background, NULL);
}

static void draw_story_game(sfRenderWindow *window, game_t *game)
{
    game->map->time_clock = sfClock_getElapsedTime(game->map->part_clock);
    game->map->seconds = game->map->time_clock.microseconds / 1000000.0;
    particles_movement(game);
    for (int i = 0; i < NB_PARTICLE; i += 1) {
        sfSprite_setTextureRect(game->map->particule_spr[i],
        game->map->particle_rect[i]);
        sfRenderWindow_drawSprite(window, game->map->particule_spr[i], NULL);
    }
    change_view(game, window);
}

static void draw_select_charac(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_clear(window, sfColor_fromRGB(0, 90, 0));
    sfRenderWindow_drawSprite(window, game->select->backboard, NULL);
    for (int i = 0; game->select->characters[i] != NULL; i += 1)
        sfRenderWindow_drawSprite(window, game->select->characters[i], NULL);
    for (int i = 0; game->select->button_select[i] != NULL; i += 1)
        sfRenderWindow_drawSprite
            (window, game->select->button_select[i], NULL);
    sfRenderWindow_drawText
        (window, game->select->text[game->select->player], NULL);
    sfRenderWindow_drawSprite(window, game->select->arrow_selec, NULL);
}

void draw_game(rpg_t *rpg)
{
    void (*draw_game_fct[])(sfRenderWindow *, game_t *) =
        {draw_select_charac, draw_story_game};

    if (rpg->game->screen >= LOAD_GAME) {
        sfRenderWindow_drawSprite(rpg->window,
            rpg->game->map->sprite_ground, NULL);
        sfRenderWindow_drawSprite(rpg->window,
            rpg->game->player->sprites->player, NULL);
        sfRenderWindow_drawSprite(rpg->window,
            rpg->game->map->sprite_obj, NULL);
    }
    if (rpg->game->screen != PAUSE)
        draw_game_fct[rpg->game->screen](rpg->window, rpg->game);
    else
        draw_pause_menu(rpg->window, rpg->game);
    return;
}
