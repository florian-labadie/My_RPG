/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** game_event
*/

#include "my.h"

static int sprite_move_player(game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(game->player->sprites->player);

    pos.x += game->player_move.x;
    pos.y += game->player_move.y;
    if (pos.x < 30)
        pos.x = 30;
    if (pos.x > 930)
        pos.x = 930;
    if (pos.y < 30)
        pos.y = 30;
    if (pos.y > 665)
        pos.y = 665;
    sfSprite_setPosition(game->player->sprites->player, pos);
    if (pos.x > 200 && pos.x < 760)
        game->map->rect.left += game->player_move.x;
    if (pos.y > 100 && pos.y < 595)
        game->map->rect.top += game->player_move.y;
    return OK;
}

void change_view(game_t *game, sfRenderWindow *window)
{
    if (sprite_move_player(game) == OK) {
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
        (*rpg)->game->screen = PAUSE;
        return OK;
    }
    return OK;
}

int game_event(rpg_t *rpg, sfEvent event)
{
    if (check_game_screen_changes(&rpg, event) == END)
        return OK;
    get_movements(rpg, event);
    get_movements_realesed(rpg, event);
    return OK;
}
