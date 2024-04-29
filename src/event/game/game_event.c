/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** game_event
*/

#include "my.h"

void change_view(rpg_t *rpg)
{
    rpg->map->rect.top += rpg->map->move_vect.y;
    rpg->map->rect.left += rpg->map->move_vect.x;
    if (rpg->map->rect.top < 0)
        rpg->map->rect.top = 0;
    if (rpg->map->rect.top > 495)
        rpg->map->rect.top = 495;
    if (rpg->map->rect.left < 0)
        rpg->map->rect.left = 0;
    if (rpg->map->rect.left > 560)
        rpg->map->rect.left = 560;
    rpg->map->view = sfView_createFromRect(rpg->map->rect);
    sfRenderWindow_setView(rpg->window, rpg->map->view);
}

static void get_movements_realesed(rpg_t *rpg, sfEvent event)
{
    if (event.key.code == sfKeyZ && event.key.type == sfEvtKeyReleased)
        rpg->map->move_vect.y = 0;
    if ((event.key.code == sfKeyS && event.key.type == sfEvtKeyReleased))
        rpg->map->move_vect.y = 0;
    if ((event.key.code == sfKeyQ && event.key.type == sfEvtKeyReleased))
        rpg->map->move_vect.x = 0;
    if ((event.key.code == sfKeyD && event.key.type == sfEvtKeyReleased))
        rpg->map->move_vect.x = 0;
}

static void get_movements(rpg_t *rpg, sfEvent event)
{
    if (rpg->map->move_vect.y != -1 && event.key.code == sfKeyZ &&
        event.key.type == sfEvtKeyPressed)
        rpg->map->move_vect.y += -1;
    if (rpg->map->move_vect.y != -1 && event.key.code == sfKeyS &&
        event.key.type == sfEvtKeyPressed)
            rpg->map->move_vect.y += 1;
    if (rpg->map->move_vect.x != -1 && event.key.code == sfKeyQ &&
        event.key.type == sfEvtKeyPressed)
        rpg->map->move_vect.x += -1;
    if (rpg->map->move_vect.x != 1 && event.key.code == sfKeyD &&
        event.key.type == sfEvtKeyPressed)
            rpg->map->move_vect.x += 1;
}

void game_event(rpg_t *rpg, sfEvent event)
{
    get_movements(rpg, event);
    get_movements_realesed(rpg, event);
    return;
}
