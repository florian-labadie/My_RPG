/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** game_event
*/

#include "my.h"

static void change_view(rpg_t *rpg)
{
    rpg->map->view = sfView_createFromRect(rpg->map->rect);
    sfRenderWindow_setView(rpg->window, rpg->map->view);
}

static void get_movements(rpg_t *rpg, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) && rpg->map->rect.top > 0) {                
        rpg->map->rect.top -= 5;
        change_view(rpg);
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) &&
            rpg->map->rect.top < get_resize(rpg->window, 495, 0).x) {
        rpg->map->rect.top += 5;
        change_view(rpg);
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ) && rpg->map->rect.left > 0) {
        rpg->map->rect.left -= 5;
        change_view(rpg);
    }
    if (sfKeyboard_isKeyPressed(sfKeyD) &&
            rpg->map->rect.left < get_resize(rpg->window, 560, 0).x) {
        rpg->map->rect.left += 5;
        change_view(rpg);
    }
}

void game_event(rpg_t *rpg, sfEvent event)
{
    get_movements(rpg, event);
    return;
}
