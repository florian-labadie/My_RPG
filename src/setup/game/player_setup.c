/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** player_setup
*/

#include "my.h"

static void player_stats_setup(player_t *player)
{
    float stats[PLAYER_RACE_SIZE][5] = {{100.0, 75.0, 75.0, 75.0, 100.0},
                                        {100.0, 50.0, 100.0, 50.0, 125.0},
                                        {100.0, 100.0, 50.0, 100.0, 75.0}};

    player->stats.health = stats[player->race][0];
    player->stats.mana = stats[player->race][1];
    player->stats.attack = stats[player->race][2];
    player->stats.magic_attack = stats[player->race][3];
    player->stats.defense = stats[player->race][4];
}

static int player_sprites_setup(sfRenderWindow *window, player_t *player)
{
    player->sprites = malloc(sizeof(player_sprites_t));
}

int player_setup(sfRenderWindow *window, player_t *player)
{
    return OK;
}
