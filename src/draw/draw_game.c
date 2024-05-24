/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** draw_game
*/

#include "my.h"

static void draw_village(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_drawSprite(window, game->map->sprite_ground, NULL);
    sfRenderWindow_drawSprite(window, game->player->sprites->player, NULL);
    sfRenderWindow_drawSprite(window, game->map->sprite_obj, NULL);
    for (int i = 0; i < 2; i++) {
        if (game->interaction->field[i] == game->map->choice_map) {
            sfRenderWindow_drawSprite(window, game->interaction->sprite[i],
                NULL);
            sfRenderWindow_drawText(window, game->interaction->text[i], NULL);
        }
    }
    draw_particles(game, window);
    draw_flag(game, window);
    change_view(game, window);
}

static void move_ork(game_t *game)
{
    for (int j = 0; j < NB_ORK; j += 1) {
        game->map->entities->ork[j]->ork_rect.left += 50;
        if (game->map->entities->ork[j]->ork_rect.left >= 300)
            game->map->entities->ork[j]->ork_rect.left = 0;
        sfSprite_setTextureRect(game->map->entities->ork[j]->ork_spr,
        game->map->entities->ork[j]->ork_rect);
        if (game->map->entities->ork_is_moving == true)
            ork_movement(
            sfSprite_getPosition(game->map->entities->ork[j]->ork_spr),
            sfSprite_getPosition(game->player->sprites->player),
            game->map->entities->ork[j], 2.5);
    }
}

static void move_battle_sprite(game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->map->entities->wizz_clock);

    if (time.microseconds >= 350000) {
        move_ork(game);
        game->map->entities->wizzard_rect.left += 204;
        if (game->map->entities->wizzard_rect.left >= 408)
            game->map->entities->wizzard_rect.left = 0;
        sfSprite_setTextureRect(game->map->entities->wizzard_spr,
        game->map->entities->wizzard_rect);
        sfClock_restart(game->map->entities->wizz_clock);
    }
}

static void draw_battlefield(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_drawSprite(window, game->map->battle_spr, NULL);
    move_battle_sprite(game);
    for (int i = 0; i < NB_ORK; i += 1) {
        sfRenderWindow_drawCircleShape(window,
        game->map->entities->ork[i]->hitbox, NULL);
        if (game->map->entities->ork[i]->hp > 0)
            sfRenderWindow_drawSprite(window,
            game->map->entities->ork[i]->ork_spr, NULL);
        if (game->map->entities->ork[i]->hp <= 0 &&
        game->map->entities->ork[i]->is_alive != false) {
            game->player->stats.xp += 50;
            game->player->stats.nb_gold += 40;
            game->map->entities->ork[i]->is_alive = false;
        }
    }
    sfRenderWindow_drawSprite(window, game->map->entities->wizzard_spr, NULL);
    sfRenderWindow_drawSprite(window, game->player->sprites->player, NULL);
    sfRenderWindow_drawSprite(window, game->map->entities->bubble_spr, NULL);
    sfRenderWindow_drawText(window, game->map->entities->wizzard_sent, NULL);
    sfRenderWindow_drawText(window, game->map->help_exit, NULL);
    change_player_pos_bf(game, window);
    if (game->player->is_alive == false) {
        sfRenderWindow_drawRectangleShape(window,
        game->player->life->loos_rect, NULL);
        sfRenderWindow_drawSprite(window, game->player->life->lose_spr, NULL);
        if (sfTime_asSeconds(sfClock_getElapsedTime
        (game->player->life->time_lose)) > 3) {
            game->player->is_alive = true;
            game->map->choice_map = VILLAGE;
            sfMusic_stop(game->map->battle_music);
            sfMusic_play(game->map->game_sound);
            sfSprite_setPosition(game->player->sprites->player,
            game->player->last_pos);
            sfSprite_setPosition(game->player->sprites->player,
            game->player->last_pos);
            sfSprite_setScale(game->player->sprites->player,
            (sfVector2f){0.5, 0.5});
            game->player->stats.health = 100;
        }
    }
}

static void draw_story_game(sfRenderWindow *window, game_t *game)
{
    if (game->map->choice_map == VILLAGE)
        sfRenderWindow_setView(window, game->original_view);
    for (int i = 0; game->player->life->rects[i]; i++)
        sfRenderWindow_drawRectangleShape(window,
            game->player->life->rects[i], NULL);
    sfRenderWindow_drawSprite(window, game->player->life->health_bar_spr,
    NULL);
    sfRenderWindow_drawText(window, game->player->stats.level_text, NULL);
    if (game->map->choice_map == VILLAGE) {
        sfRenderWindow_setView(window, game->map->view);
    }
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
        {draw_select_charac, draw_story_game, draw_pause_menu, draw_inventory};
    void (*draw_map_function[])(sfRenderWindow *, game_t *) =
        {draw_village, draw_battlefield, draw_forge, draw_alchemist};

    if (rpg->game->screen >= PLAYING)
        draw_map_function[rpg->game->map->choice_map](rpg->window, rpg->game);
    draw_game_fct[rpg->game->screen](rpg->window, rpg->game);
}
