/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** ork_manager
*/

#include "my.h"

void damage_for_ork(rpg_t *rpg)
{
    sfFloatRect touch = {0.0, 0.0, 0.0, 0.0};
    sfFloatRect touch2 = {0.0, 0.0, 0.0, 0.0};

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

void attack_orks(game_t *game)
{
    sfFloatRect r1 = {0};
    sfFloatRect r2 = {0};

    for (int i = 0; game->map->choice_map == BATTLEFIELD &&
        i < NB_ORK; i += 1) {
        if (!game->map->entities->ork[i]->is_alive)
            continue;
        r1 = sfCircleShape_getGlobalBounds
                (game->map->entities->ork[i]->hitbox);
        r2 = sfCircleShape_getGlobalBounds
                (game->player->sprites->range);
        if (sfFloatRect_intersects(&r1, &r2, NULL))
            game->map->entities->ork[i]->hp -=
                game->player->stats.attack * 2.5;
    }
}
