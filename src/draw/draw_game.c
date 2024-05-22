/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** draw_game
*/

#include "my.h"

static void draw_pause_menu(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_drawRectangleShape(window, game->pause->background, NULL);
    sfRenderWindow_drawSprite(window, game->pause->sprites[3], NULL);
    sfRenderWindow_drawText(window, game->pause->text[3], NULL);
    for (int i = 0; i < 3; i++) {
        sfRenderWindow_drawSprite(window, game->pause->sprites[i], NULL);
        sfRenderWindow_drawText(window, game->pause->text[i], NULL);
    }
}

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
    set_life_village(game, window);
}

static void draw_rectangle(sfRenderWindow *window, sfRectangleShape **shape)
{
    for (int i = 0; i < 2; i += 1) {
        sfRenderWindow_drawRectangleShape(window, shape[i], NULL);
    }
}

static void draw_forge(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, game->map->house[0]->house, NULL);
    sfRenderWindow_drawSprite(window, game->player->sprites->player, NULL);
    for (int i = 0; i < 2; i++) {
        if (game->interaction->field[i] == game->map->choice_map) {
            sfRenderWindow_drawSprite(window, game->interaction->sprite[i],
                NULL);
            draw_rectangle(window, game->interaction->zone_text[i]);
            sfRenderWindow_drawText(window, game->interaction->text[i], NULL);
        }
    }
}

static void draw_alchemist(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, game->map->house[1]->house, NULL);
    sfRenderWindow_drawSprite(window, game->player->sprites->player, NULL);
    for (int i = 0; i < 2; i++) {
        if (game->interaction->field[i] == game->map->choice_map) {
            sfRenderWindow_drawSprite(window, game->interaction->sprite[i],
                NULL);
            draw_rectangle(window, game->interaction->zone_text[i]);
            sfRenderWindow_drawText(window, game->interaction->text[i], NULL);
        }
    }
}

static void move_battle_sprite(game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->map->entities->wizz_clock);

    if (time.microseconds >= 350000) {
        game->map->entities->ork_rect.left += 50;
        if (game->map->entities->ork_rect.left >= 300)
            game->map->entities->ork_rect.left = 0;
        for (int i = 0; i < NB_ORK; i += 1)
            sfSprite_setTextureRect(game->map->entities->ork_spr[i],
            game->map->entities->ork_rect);
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
    for (int i = 0; i < NB_ORK; i += 1)
        sfRenderWindow_drawSprite(window, game->map->entities->ork_spr[i],
        NULL);
    sfRenderWindow_drawSprite(window, game->map->entities->wizzard_spr, NULL);
    sfRenderWindow_drawSprite(window,
    game->player->sprites->player, NULL);
    set_life_battle(window, game);
}

static void draw_story_game(sfRenderWindow *window, game_t *game)
{
    return;
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
        {draw_select_charac, draw_story_game, draw_pause_menu};
    void (*draw_map_function[])(sfRenderWindow *, game_t *) =
        {draw_village, draw_battlefield, draw_forge, draw_alchemist};

    if (rpg->game->screen >= PLAYING)
        draw_map_function[rpg->game->map->choice_map](rpg->window, rpg->game);
    draw_game_fct[rpg->game->screen](rpg->window, rpg->game);
}
