/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** battlefield_movement
*/

#include "my.h"

static int check_ork_bounds(game_t *game, sfFloatRect r)
{
    sfFloatRect ork_rect = {0};

    for (int i = 0; i < NB_ORK; i++) {
        ork_rect = sfCircleShape_getGlobalBounds
            (game->map->entities->ork[i]->hitbox);
        if (sfFloatRect_intersects(&r, &ork_rect, NULL))
            return OK;
    }
    return KO;
}

static int top_down_bf(game_t *game, sfRenderWindow *window, sfFloatRect r)
{
    if ((game->player_move.y < 0 && r.top <= 0) || (game->player_move.y > 0 &&
        r.top + r.height * 1.5 >= get_resize(window, 1080, 0).x))
        return KO;
    if (game->player_move.y < 0) {
        if (check_ork_bounds(game,
            ((sfFloatRect){r.left, r.top - 1, r.width, 1})) == OK)
            return KO;
    }
    if (game->player_move.y > 0) {
        if (check_ork_bounds(game,
            ((sfFloatRect){r.left, r.top + r.height, r.width, 1})) == OK)
            return KO;
    }
    return OK;
}

static int left_right_bf(game_t *game, sfRenderWindow *window, sfFloatRect r)
{
    if ((game->player_move.x < 0 && r.left <= 0) || (game->player_move.x > 0 &&
        r.left + r.width >= get_resize(window, 1920, 0).x))
        return KO;
    if (game->player_move.x < 0) {
        if (check_ork_bounds(game,
            ((sfFloatRect){r.left - 1, r.top, 1, r.height})) == OK)
            return KO;
    }
    if (game->player_move.x > 0) {
        if (check_ork_bounds(game,
            ((sfFloatRect){r.left + r.width, r.top, 1, r.height})) == OK)
            return KO;
    }
    return OK;
}

void change_player_pos_bf(game_t *game, sfRenderWindow *window)
{
    sfFloatRect r = sfSprite_getGlobalBounds(game->player->sprites->player);

    if (game->player_move.x != 0 && left_right_bf(game, window, r) == OK) {
        sfSprite_move(game->player->sprites->player,
        (sfVector2f){game->player_move.x * 10, 0});
    }
    if (game->player_move.y != 0 && top_down_bf(game, window, r) == OK) {
        sfSprite_move(game->player->sprites->player,
        (sfVector2f){0, game->player_move.y * 10});
    }
    sfCircleShape_setPosition(game->player->sprites->range,
        (sfVector2f){r.left + r.width / 2, r.top + r.height / 2});
    sfCircleShape_setPosition(game->player->sprites->hitbox,
        (sfVector2f){r.left + r.width / 2, r.top + r.height / 2});
}
