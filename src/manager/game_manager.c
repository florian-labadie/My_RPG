/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** game_manager
*/

#include "my.h"

static void player_mouvement(sfSprite *sprite, sfVector2f player_move)
{
    sfVector2f scale = sfSprite_getScale(sprite);

    if (player_move.x > 0)
        sfSprite_setScale(sprite, (sfVector2f){ABS(scale.x), ABS(scale.y)});
    if (player_move.x < 0)
        sfSprite_setScale(sprite, (sfVector2f){-ABS(scale.x), ABS(scale.y)});
}

static void player_attack(game_t *game, player_race_t race, sfIntRect *rects,
    float add)
{
    sfVector2f origins[3] =
        {{HUMAN_ATT_RECT.width / 2, HUMAN_ATT_RECT.height / 2},
        {DWARF_ATT_RECT.width / 2, DWARF_ATT_RECT.height / 2},
        {ELF_ATT_RECT.width / 2, ELF_ATT_RECT.height / 2}};
    sfIntRect rect = rects[race];

    if (sfTime_asMilliseconds(sfClock_getElapsedTime
        (game->player->sprites->player_clock)) > 200) {
        rect.left =
            sfSprite_getTextureRect(game->player->sprites->player).left;
        rect.left += rects[race].width + add;
        if (rect.left >= 415) {
            game->player->attack = false;
            return;
        }
        sfSprite_setOrigin(game->player->sprites->player, origins[race]);
        sfSprite_setTextureRect(game->player->sprites->player, rect);
        sfClock_restart(game->player->sprites->player_clock);
    }
}

static void player_attack_manager(game_t *game, player_race_t race)
{
    sfIntRect rects[3] = {HUMAN_ATT_RECT, DWARF_ATT_RECT, ELF_ATT_RECT};
    float add = 1.0;

    if (race == DWARF)
        add = 1.9;
    if (race == ELF)
        add = 1.95;
    player_mouvement(game->player->sprites->player, game->player_move);
    player_attack(game, race, rects, add);
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
        rect.left = sfSprite_getTextureRect
            (game->player->sprites->player).left;
        rect.left += rects[race].width;
        if (rect.left >= 415)
            rect.left = rects[race].left;
        sfSprite_setOrigin(game->player->sprites->player, origins[race]);
        sfSprite_setTextureRect(game->player->sprites->player, rect);
        sfClock_restart(game->player->sprites->player_clock);
    }
}

static void still_player(game_t *game, player_race_t race,
    sfIntRect *rects, sfVector2f *origins)
{
    sfIntRect rect = rects[race];

    if (sfTime_asMilliseconds(sfClock_getElapsedTime
        (game->player->sprites->player_clock)) > 200) {
        rect.left = sfSprite_getTextureRect
            (game->player->sprites->player).left;
        rect.left += rects[race].width;
        if (rect.left >= 208)
            rect.left = rects[race].left;
        sfSprite_setOrigin(game->player->sprites->player, origins[race]);
        sfSprite_setTextureRect(game->player->sprites->player, rect);
        sfClock_restart(game->player->sprites->player_clock);
    }
}

static void player_still_manager(game_t *game, player_race_t race)
{
    sfIntRect rects[3] = {HUMAN_STILL_RECT, DWARF_STILL_RECT, ELF_STILL_RECT};
    sfVector2f origins[3] =
        {{HUMAN_STILL_RECT.width / 2, HUMAN_STILL_RECT.height / 2},
        {DWARF_STILL_RECT.width / 2, DWARF_STILL_RECT.height / 2},
        {ELF_STILL_RECT.width / 2, ELF_STILL_RECT.height / 2}};

    still_player(game, race, rects, origins);
}

static void game_music(rpg_t *rpg)
{
    if (rpg->game->map->choice_map == VILLAGE &&
        (sfMusic_getStatus(rpg->game->map->game_sound) == sfStopped ||
        sfMusic_getStatus(rpg->game->map->game_sound) == sfPaused))
        sfMusic_play(rpg->game->map->game_sound);
}

static void move_player(rpg_t *rpg)
{
    if (rpg->game->map->choice_map <= BATTLEFIELD) {
        if (rpg->game->player_move.x != 0 || rpg->game->player_move.y
            != 0)
            player_move_manager(rpg->game, rpg->game->player->race);
        if (rpg->game->player_move.x == 0 && rpg->game->player_move.y
            == 0)
            player_still_manager(rpg->game, rpg->game->player->race);
    } else
        player_still_manager(rpg->game, rpg->game->player->race);
}

static void death_player(rpg_t *rpg)
{
    sfVector2f pos = {0.0, 0.0};

    if (rpg->game->player->stats.health <= 0) {
        rpg->game->map->entities->ork_is_moving = false;
        for (int i = 0; i < NB_ORK; i += 1) {
            pos = (sfVector2f) {rand() % 1400, rand() % 800};
            sfSprite_setPosition(rpg->game->map->entities->ork[i]->ork_spr,
            pos);
            sfCircleShape_setPosition(rpg->game->map->entities->ork[i]->hitbox,
            get_resize(rpg->window, pos.x - 40, pos.y + 30));
        }
        rpg->game->player->is_alive = false;
        rpg->game->player->stats.nb_gold -= 75;
        if (rpg->game->player->stats.nb_gold < 0)
            rpg->game->player->stats.nb_gold = 0;
    }
}

void game_manager(rpg_t *rpg)
{
    game_music(rpg);
    if (rpg->game->screen == SELECTION)
        return;
    inventory_manager(rpg->game);
    call_life_lev(rpg);
    if (rpg->game->map->choice_map == BATTLEFIELD) {
        damage_for_ork(rpg);
        death_player(rpg);
    }
    if (rpg->game->map->choice_map <= BATTLEFIELD &&
        rpg->game->player->attack == true) {
        player_attack_manager(rpg->game, rpg->game->player->race);
        if (sfTime_asSeconds(sfClock_getElapsedTime
        (rpg->game->player->sprites->attack_clock)) >= 2) {
            attack_orks(rpg->game);
            sfClock_restart(rpg->game->player->sprites->attack_clock);
        }
    } else
        move_player(rpg);
    return;
}
