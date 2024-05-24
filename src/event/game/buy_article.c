/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** buy_article
*/

#include "my.h"

static void quitt_buy_item(rpg_t *rpg, sfSprite *sprite, sfVector2f mouse_pos)
{
    if (get_sprite_bounds(sprite, mouse_pos) == sfTrue) {
        rpg->game->interaction->shop = QUITT;
    }
}

static void buy_potion(rpg_t *rpg, sfRectangleShape **shape,
    sfVector2f mouse_pos)
{
    if (get_rectangle_bounds(shape[0], mouse_pos) == sfTrue) {
        if (rpg->game->player->stats.nb_gold >= 50 &&
            rpg->game->inventory->nbr_health_pot <= 4) {
            rpg->game->player->stats.nb_gold -= 50;
            rpg->game->inventory->nbr_health_pot += 1;
        }
    }
    if (get_rectangle_bounds(shape[1], mouse_pos) == sfTrue) {
        if (rpg->game->player->stats.nb_gold >= 50 &&
            rpg->game->inventory->nbr_mana_pot <= 4) {
            rpg->game->player->stats.nb_gold -= 50;
            rpg->game->inventory->nbr_mana_pot += 1;
        }
    }
}

static void buy_weapon_itemleg(rpg_t *rpg, sfRectangleShape **shape,
    sfVector2f mouse_pos)
{
    if (get_rectangle_bounds(shape[2], mouse_pos) == sfTrue) {
        if (rpg->game->player->stats.nb_gold >= 500) {
            rpg->game->player->stats.nb_gold -= 500;
            rpg->game->player->stats.attack += 15;
            sfSprite_setColor(rpg->game->inventory->item->
                weapons[rpg->game->player->race][2], sfWhite);
        }
    }
}

static void buy_weapon(rpg_t *rpg, sfRectangleShape **shape,
    sfVector2f mouse_pos)
{
    if (get_rectangle_bounds(shape[0], mouse_pos) == sfTrue) {
        if (rpg->game->player->stats.nb_gold >= 50) {
            rpg->game->player->stats.nb_gold -= 50;
            rpg->game->player->stats.attack += 5;
            sfSprite_setColor(rpg->game->inventory->item->
                weapons[rpg->game->player->race][0], sfWhite);
        }
    }
    if (get_rectangle_bounds(shape[1], mouse_pos) == sfTrue) {
        if (rpg->game->player->stats.nb_gold >= 200) {
            rpg->game->player->stats.nb_gold -= 200;
            rpg->game->player->stats.attack += 10;
            sfSprite_setColor(rpg->game->inventory->item->
                weapons[rpg->game->player->race][1], sfWhite);
        }
    }
    buy_weapon_itemleg(rpg, shape, mouse_pos);
}

static void check_shop(rpg_t *rpg, sfVector2f mouse_pos)
{
    if (rpg->game->map->choice_map == FORGE) {
        buy_weapon(rpg, rpg->game->shop->
            weapon[rpg->game->player->race]->zone_text, mouse_pos);
        quitt_buy_item(rpg, rpg->game->shop->sprite_quitt[0], mouse_pos);
    }
    if (rpg->game->map->choice_map == ALCHEMY) {
        buy_potion(rpg, rpg->game->shop->potion->zone_text,
            mouse_pos);
        quitt_buy_item(rpg, rpg->game->shop->sprite_quitt[1], mouse_pos);
    }
}

void buy_article(rpg_t *rpg, sfEvent event)
{
    sfVector2i mouse_pos_int = {event.mouseButton.x, event.mouseButton.y};
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(rpg->window,
        mouse_pos_int, rpg->game->map->view);

    if (event.mouseButton.type == sfEvtMouseButtonReleased &&
            event.mouseButton.button == sfMouseLeft) {
        check_shop(rpg, mouse_pos);
    }
}
