/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** game_event
*/

#include "my.h"

void change_view(rpg_t *rpg)
{
    rpg->game->map->rect.top += rpg->game->player_move.y;
    rpg->game->map->rect.left += rpg->game->player_move.x;
    if (rpg->game->map->rect.top < 0)
        rpg->game->map->rect.top = 0;
    if (rpg->game->map->rect.top > 495)
        rpg->game->map->rect.top = 495;
    if (rpg->game->map->rect.left < 0)
        rpg->game->map->rect.left = 0;
    if (rpg->game->map->rect.left > 560)
        rpg->game->map->rect.left = 560;
    rpg->game->map->view = sfView_createFromRect(rpg->game->map->rect);
    sfRenderWindow_setView(rpg->window, rpg->game->map->view);
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

void game_event(rpg_t *rpg, sfEvent event)
{
    get_movements(rpg, event);
    get_movements_realesed(rpg, event);
    return;
}
