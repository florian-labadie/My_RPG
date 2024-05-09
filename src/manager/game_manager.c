/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** game_manager
*/

#include "my.h"

static void player_mouvement(sfSprite *sprite, sfVector2f player_move)
{
    sfSprite_move(sprite, (sfVector2f){player_move.x, player_move.y});
    if (player_move.x > 0)
        sfSprite_setScale(sprite, (sfVector2f){0.5, 0.5});
    if (player_move.x < 0)
        sfSprite_setScale(sprite, (sfVector2f){-0.5, 0.5});
}

static void player_move_manager(game_t *game, player_race_t race)
{
    sfIntRect rects[3] = {HUMAN_RECT, DWARF_RECT, ELF_RECT};
    sfIntRect rect = rects[race];
    sfVector2f origins[3] = {{HUMAN_RECT.width / 2, HUMAN_RECT.height / 2},
        {DWARF_RECT.width / 2, DWARF_RECT.height / 2},
        {ELF_RECT.width / 2, ELF_RECT.height / 2}};

    player_mouvement(game->player->sprites->player, game->player_move);
    if (sfTime_asMilliseconds(sfClock_getElapsedTime
        (game->player->sprites->player_clock)) > 200) {
        rect = sfSprite_getTextureRect(game->player->sprites->player);
        rect.left += rects[race].width;
        if (rect.left >= 415)
            rect.left = rects[race].left;
        sfSprite_setOrigin(game->player->sprites->player, origins[race]);
        sfSprite_setTextureRect(game->player->sprites->player, rect);
        sfClock_restart(game->player->sprites->player_clock);
    }
}

static void player_still_manager(game_t *game, player_race_t race)
{
    sfIntRect rects[3] = {HUMAN_STILL_RECT, DWARF_STILL_RECT, ELF_STILL_RECT};
    sfIntRect rect = rects[race];
    sfVector2f origins[3] = 
        {{HUMAN_STILL_RECT.width / 2, HUMAN_STILL_RECT.height / 2},
        {DWARF_STILL_RECT.width / 2, DWARF_STILL_RECT.height / 2},
        {ELF_STILL_RECT.width / 2, ELF_STILL_RECT.height / 2}};

    if (sfTime_asMilliseconds(sfClock_getElapsedTime
        (game->player->sprites->player_clock)) > 200) {
        rect = sfSprite_getTextureRect(game->player->sprites->player);
        rect.left += rects[race].width;
        if (rect.left >= 208)
            rect.left = rects[race].left;
        sfSprite_setOrigin(game->player->sprites->player, origins[race]);
        sfSprite_setTextureRect(game->player->sprites->player, rect);
        sfClock_restart(game->player->sprites->player_clock);
    }
}

static void game_music(rpg_t *rpg)
{
    if (sfMusic_getStatus(rpg->game->map->game_sound) == sfStopped ||
        sfMusic_getStatus(rpg->game->map->game_sound) == sfPaused)
        sfMusic_play(rpg->game->map->game_sound);
}

void game_manager(rpg_t *rpg)
{
    game_music(rpg);
    if (rpg->game->player->sprites->player) {
        if (rpg->game->player_move.x != 0 || rpg->game->player_move.y != 0) {
            player_move_manager(rpg->game, rpg->game->player->race);
        }
        if (rpg->game->player_move.x == 0 && rpg->game->player_move.y == 0) {
            player_still_manager(rpg->game, rpg->game->player->race);
        }
    }
    return;
}
