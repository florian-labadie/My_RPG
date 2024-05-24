/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** game_event
*/

#include "my.h"

static void get_movements_realesed(rpg_t *rpg, sfEvent event)
{
    if (event.type == sfEvtKeyReleased) {
        if (event.key.code == sfKeyZ || event.key.code == sfKeyS)
            rpg->game->player_move.y = 0;
        if (event.key.code == sfKeyQ || event.key.code == sfKeyD)
            rpg->game->player_move.x = 0;
    }
}

static void get_movements(rpg_t *rpg, sfEvent event)
{
    if (rpg->game->player_move.y >= -0.10 && event.key.code == sfKeyZ &&
        event.key.type == sfEvtKeyPressed)
        rpg->game->player_move.y += -0.10;
    if (rpg->game->player_move.y <= 0.10 && event.key.code == sfKeyS &&
        event.key.type == sfEvtKeyPressed)
        rpg->game->player_move.y += 0.10;
    if (rpg->game->player_move.x >= -0.10 && event.key.code == sfKeyQ &&
        event.key.type == sfEvtKeyPressed)
        rpg->game->player_move.x += -0.10;
    if (rpg->game->player_move.x <= 0.10 && event.key.code == sfKeyD &&
        event.key.type == sfEvtKeyPressed)
        rpg->game->player_move.x += 0.10;
}

static int check_game_screen_changes(rpg_t **rpg, sfEvent event)
{
    if (event.key.code == sfKeyBackspace &&
        event.key.type == sfEvtKeyPressed) {
        (*rpg)->screen = END;
        return END;
    }
    if (event.key.code == sfKeyEscape && event.key.type == sfEvtKeyPressed) {
        (*rpg)->game->player_move = (sfVector2f){0, 0};
        (*rpg)->game->screen = PAUSE;
        return OK;
    }
    if (event.key.code == sfKeyTab && event.key.type == sfEvtKeyPressed) {
        (*rpg)->game->player_move = (sfVector2f){0, 0};
        (*rpg)->game->screen = INVENTORY;
        return OK;
    }
    return OK;
}

int game_event(rpg_t *rpg, sfEvent event)
{
    if (check_game_screen_changes(&rpg, event) == END)
        return OK;
    if (rpg->game->map->choice_map == VILLAGE ||
        rpg->game->map->choice_map == BATTLEFIELD) {
        if (event.mouseButton.type == sfEvtMouseButtonPressed &&
            event.mouseButton.button == sfMouseLeft &&
            rpg->game->player->attack == false)
            rpg->game->player->attack = true;
        get_movements(rpg, event);
        get_movements_realesed(rpg, event);
        show_flag(rpg, event);
        event_battlefield(rpg, event);
    }
    if (rpg->game->map->choice_map == FORGE ||
        rpg->game->map->choice_map == ALCHEMY) {
        if (rpg->game->interaction->shop == BUY)
            buy_article(rpg, event);
        interaction_event(rpg, event);
    }
    return OK;
}
