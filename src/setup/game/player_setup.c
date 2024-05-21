/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** player_setup
*/

#include "my.h"

static void player_stats_setup(player_t *player)
{
    float stats[PLAYER_RACE_SIZE][5] = {{100.0, 50.0, 50.0, 50.0, 75.0},
                                        {100.0, 25.0, 75.0, 25.0, 100.0},
                                        {100.0, 75.0, 25.0, 75.0, 50.0}};

    player->stats.health = stats[player->race][0];
    player->stats.mana = stats[player->race][1];
    player->stats.attack = stats[player->race][2];
    player->stats.magic_attack = stats[player->race][3];
    player->stats.defense = stats[player->race][4];
}

static int player_sprites_setup(sfRenderWindow *window, player_t *player)
{
    sfIntRect rects[3] = {HUMAN_STILL_RECT, DWARF_STILL_RECT, ELF_STILL_RECT};
    sfVector2f origins[3] = {
        {HUMAN_STILL_RECT.width / 2, HUMAN_STILL_RECT.height / 2},
        {DWARF_STILL_RECT.width / 2, DWARF_STILL_RECT.height / 2},
        {ELF_STILL_RECT.width / 2, ELF_STILL_RECT.height / 2}};

    player->sprites->player_text = sfTexture_createFromFile(PLAYER, NULL);
    player->sprites->player_clock = sfClock_create();
    player->sprites->move_clock = sfClock_create();
    player->sprites->player_rect = rects[player->race];
    player->attack = false;
    player->position = (sfVector2f){170, 660};
    if (!player->sprites->player_text)
        return KO;
    player->sprites->player = create_button(player->sprites->player_text,
        (sfVector2f){0.5, 0.5}, player->position);
    sfSprite_setTextureRect(player->sprites->player, rects[player->race]);
    sfSprite_setOrigin(player->sprites->player, origins[player->race]);
    return OK;
}

int player_setup(sfRenderWindow *window, player_t *player)
{
    if (player_sprites_setup(window, player) == KO)
        return KO;
    return OK;
}
