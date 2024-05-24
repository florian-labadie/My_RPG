/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** inventory_menu_event
*/

#include "my.h"

static void take_potion(rpg_t *rpg, sfEvent event)
{
    sfVector2i mouse_pos_int = {event.mouseButton.x, event.mouseButton.y};
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(rpg->window,
        mouse_pos_int, rpg->game->original_view);

    for (int i = 0; i < 4; i++) {
        if (get_sprite_bounds(rpg->game->inventory->item->health_pot[i],
            mouse_pos) == sfTrue &&
            i <= rpg->game->inventory->nbr_health_pot &&
            rpg->game->player->stats.health < 100) {
            rpg->game->player->stats.health += 50;
            rpg->game->inventory->nbr_health_pot -= 1;
        }
        if (get_sprite_bounds(rpg->game->inventory->item->mana_pot[i],
            mouse_pos) == sfTrue && i <= rpg->game->inventory->nbr_mana_pot) {
            rpg->game->player->stats.mana += 50;
            rpg->game->inventory->nbr_mana_pot -= 1;
        }
    }
    if (rpg->game->player->stats.health > 100)
        rpg->game->player->stats.health = 100;
}

int inventory_menu_event(rpg_t *rpg, sfEvent event)
{
    if (event.key.code == sfKeyTab && event.key.type == sfEvtKeyReleased)
        rpg->game->screen = PLAYING;
    if (event.key.code == sfKeyPause && event.key.type == sfEvtKeyReleased)
        rpg->game->screen = PAUSE;
    if (event.mouseButton.type == sfEvtMouseButtonReleased)
        take_potion(rpg, event);
    return OK;
}
