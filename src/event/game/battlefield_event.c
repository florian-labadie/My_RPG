/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** battlefield_event
*/

#include "my.h"


static void teleport_player(rpg_t *rpg, sfEvent event)
{
    if (event.key.code == sfKeyF && event.type == sfEvtKeyPressed) {
        rpg->game->player->last_pos =
        sfSprite_getPosition(rpg->game->player->sprites->player);
        rpg->game->map->choice_map = BATTLEFIELD;
        sfMusic_stop(rpg->game->map->game_sound);
        sfMusic_play(rpg->game->map->battle_music);
        sfView_setSize(rpg->game->map->view,
        get_resize(rpg->window, 1920, 1080));
        sfView_setCenter(rpg->game->map->view,
            get_resize(rpg->window, 960, 540));
        sfRenderWindow_setView(rpg->window, rpg->game->map->view);
        sfSprite_setPosition(rpg->game->player->sprites->player,
        (sfVector2f) {1685.0, 940});
        sfSprite_setScale(rpg->game->player->sprites->player,
        (sfVector2f) {2.5, 2.5});
    }
}

void show_flag(rpg_t *rpg, sfEvent event)
{
    rpg->game->map->flag.is_flag = false;
    if (event.key.code == sfKeyX && event.type == sfEvtKeyPressed) {
        rpg->game->player->last_pos =
        sfSprite_getPosition(rpg->game->player->sprites->player);
        rpg->game->map->choice_map = BATTLEFIELD;
        sfMusic_stop(rpg->game->map->game_sound);
        sfMusic_play(rpg->game->map->battle_music);
        sfView_setSize(rpg->game->map->view,
        get_resize(rpg->window, 1920, 1080));
        sfView_setCenter(rpg->game->map->view,
            get_resize(rpg->window, 960, 540));
        sfRenderWindow_setView(rpg->window, rpg->game->map->view);
        sfSprite_setPosition(rpg->game->player->sprites->player,
        (sfVector2f) {1685.0, 940});
        sfSprite_setScale(rpg->game->player->sprites->player,
        (sfVector2f) {2.5, 2.5});
    }
    if (event.key.code == sfKeyX && event.type == sfEvtKeyPressed) {
        rpg->game->player->last_pos =
        sfSprite_getPosition(rpg->game->player->sprites->player);
        rpg->game->map->choice_map = BATTLEFIELD;
        sfMusic_stop(rpg->game->map->game_sound);
        sfMusic_play(rpg->game->map->battle_music);
        sfView_setSize(rpg->game->map->view,
        get_resize(rpg->window, 1920, 1080));
        sfView_setCenter(rpg->game->map->view,
            get_resize(rpg->window, 960, 540));
        sfRenderWindow_setView(rpg->window, rpg->game->map->view);
        sfSprite_setPosition(rpg->game->player->sprites->player,
        (sfVector2f) {1685.0, 940});
        sfSprite_setScale(rpg->game->player->sprites->player,
        (sfVector2f) {2.5, 2.5});
    }
    if (get_rectangle_bounds(rpg->game->map->flag.flag_zone,
    sfSprite_getPosition(rpg->game->player->sprites->player)) == sfTrue) {
        teleport_player(rpg, event);
        rpg->game->map->flag.is_flag = true;
    }
}

static void damage_ork(rpg_t *rpg, sfEvent event)
{
    sfFloatRect touch = {0.0, 0.0, 0.0, 0.0};
    sfFloatRect touch2 = {0.0, 0.0, 0.0, 0.0};

    if (event.type == sfEvtMouseButtonReleased)
        rpg->game->map->entities->ork_is_moving = true;
    for (int i = 0; rpg->game->map->choice_map == BATTLEFIELD
    && i < NB_ORK; i += 1) {
        if (sfTime_asSeconds(sfClock_getElapsedTime(
            rpg->game->map->entities->ork[i]->ork_damage)) < 2)
            continue;
        touch = sfCircleShape_getGlobalBounds
                (rpg->game->map->entities->ork[i]->hitbox);
        touch2 = sfCircleShape_getGlobalBounds
                (rpg->game->player->sprites->hitbox);
        if (sfFloatRect_intersects(&touch, &touch2, NULL) &&
        rpg->game->map->entities->ork[i]->hp > 0) {
            rpg->game->player->stats.health -= 5;
            sfClock_restart(rpg->game->map->entities->ork[i]->ork_damage);
        }
    }
}

static void death_player(rpg_t *rpg, sfEvent event)
{
    sfVector2f pos = {0.0, 0.0};
    pos.x - 40, pos.y + 30;
    if (rpg->game->player->stats.health <= 0) {
        rpg->game->map->entities->ork_is_moving = false;
        for (int i = 0; i < NB_ORK; i += 1) {
            pos = (sfVector2f) {rand() % 1400, rand() % 800};
            sfSprite_setPosition(rpg->game->map->entities->ork[i]->ork_spr, pos);
            sfCircleShape_setPosition(rpg->game->map->entities->ork[i]->hitbox,
            get_resize(rpg->window, pos.x - 40, pos.y + 30));
        }
        rpg->game->player->is_alive = false;
        sfClock_restart(rpg->game->player->life->time_lose);
        rpg->game->player->stats.nb_gold -= 75;
        if (rpg->game->player->stats.nb_gold < 0)
            rpg->game->player->stats.nb_gold = 0;
    }
}

void event_battlefield(rpg_t *rpg, sfEvent event)
{
    if (rpg->game->map->choice_map == BATTLEFIELD
    && event.key.code == sfKeyT && event.type == sfEvtKeyPressed) {
        rpg->game->map->choice_map = VILLAGE;
        rpg->game->map->entities->ork_is_moving = false;
        sfMusic_stop(rpg->game->map->battle_music);
        sfMusic_play(rpg->game->map->game_sound);
        sfSprite_setPosition(rpg->game->player->sprites->player,
        rpg->game->player->last_pos);
        sfSprite_setScale(rpg->game->player->sprites->player,
            (sfVector2f){0.5, 0.5});
    }
    damage_ork(rpg, event);
    death_player(rpg, event);
}