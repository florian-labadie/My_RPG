/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** destroy_game
*/

#include "my.h"

static void destroy_game_select(select_t *select)
{
    if (select) {
        for (int i = 0; i < PLAYER_RACE_SIZE; i++) {
            sfSprite_destroy(select->characters[i]);
            sfText_destroy(select->text[i]);
        }
        free(select->characters);
        free(select->text);
        for (int i = 0; i < 2; i++)
            sfSprite_destroy(select->button_select[i]);
        free(select->button_select);
        sfTexture_destroy(select->characters_texture);
        sfTexture_destroy(select->arrow_selec_text);
        sfSprite_destroy(select->arrow_selec);
        sfTexture_destroy(select->backboard_texture);
        sfSprite_destroy(select->backboard);
        sfTexture_destroy(select->button_select_texture);
        sfFont_destroy(select->font);
        free(select);
    }
}

void destroy_game(game_t *game)
{
    if (!game->player)
        return;
    if (game) {
        if (game->original_view)
            sfView_destroy(game->original_view);
        if (game->select)
            destroy_game_select(game->select);
    }
}
