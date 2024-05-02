/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** game_event
*/

#include "my.h"

void change_view(game_t *game, sfRenderWindow *window)
{
    game->map->rect.top += game->player_move.y;
    game->map->rect.left += game->player_move.x;
    if (game->map->rect.top < 0)
        game->map->rect.top = 0;
    if (game->map->rect.top > 495)
        game->map->rect.top = 495;
    if (game->map->rect.left < 0)
        game->map->rect.left = 0;
    if (game->map->rect.left > 560)
        game->map->rect.left = 560;
    game->map->view = sfView_createFromRect(game->map->rect);
    sfRenderWindow_setView(window, game->map->view);
}

static void get_movements_realesed(rpg_t *rpg, sfEvent event)
{
    if (event.key.code == sfKeyZ && event.key.type == sfEvtKeyReleased)
        rpg->game->player_move.y = 0;
    if ((event.key.code == sfKeyS && event.key.type == sfEvtKeyReleased))
        rpg->game->player_move.y = 0;
    if ((event.key.code == sfKeyQ && event.key.type == sfEvtKeyReleased))
        rpg->game->player_move.x = 0;
    if ((event.key.code == sfKeyD && event.key.type == sfEvtKeyReleased))
        rpg->game->player_move.x = 0;
}

static void get_movements(rpg_t *rpg, sfEvent event)
{
    if (rpg->game->player_move.y != -0.25 && event.key.code == sfKeyZ &&
        event.key.type == sfEvtKeyPressed)
        rpg->game->player_move.y += -0.25;
    if (rpg->game->player_move.y != 0.25 && event.key.code == sfKeyS &&
        event.key.type == sfEvtKeyPressed)
            rpg->game->player_move.y += 0.25;
    if (rpg->game->player_move.x != -0.25 && event.key.code == sfKeyQ &&
        event.key.type == sfEvtKeyPressed)
        rpg->game->player_move.x += -0.25;
    if (rpg->game->player_move.x != 0.25 && event.key.code == sfKeyD &&
        event.key.type == sfEvtKeyPressed)
            rpg->game->player_move.x += 0.25;
}

int game_event(rpg_t *rpg, sfEvent event)
{
    get_movements(rpg, event);
    get_movements_realesed(rpg, event);
    return OK;
}
