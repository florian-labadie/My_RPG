/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** draw_villagers.c
*/

#include "my.h"

void draw_villager(game_t *game, sfRenderWindow *window)
{
    sfCircleShape *circle;
    sfFloatRect circleBounds;
    sfFloatRect sprite;
    for (int i = 0; i < 4; i++) {
        circle = game->villager->v_cir[i];
        circleBounds = sfCircleShape_getGlobalBounds(circle);
        sprite = sfSprite_getGlobalBounds(game->player->sprites->player);
        if (sfFloatRect_intersects(&circleBounds, &sprite, NULL)) {
            sfRenderWindow_drawSprite
            (window, game->villager->bubble_spr[i], NULL);
            sfRenderWindow_drawText
            (window, game->villager->bubble_texts[i], NULL);
        }
        sfRenderWindow_drawCircleShape
        (window, game->villager->v_cir[i], NULL);
        sfSprite_setTextureRect
        (game->villager->v_sp[i], (sfIntRect) {0, 0, 217, 219});
        sfRenderWindow_drawSprite
        (window, game->villager->v_sp[i], NULL);
    }
}
