/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** game_event
*/

#include "my.h"

static void check_top_and_down(game_t *game, sfVector2f pos_1,
    sfVector2f pos_2, sfVector2f pos_3)
{
    if (game->player_move.y > 0) {
        pos_1.x += (game->player->sprites->player_rect.width / 4);
        pos_1.y += (game->player->sprites->player_rect.height / 4);
        pos_2.x -= (game->player->sprites->player_rect.width / 4);
        pos_2.y += (game->player->sprites->player_rect.height / 4);
        pos_3.y += (game->player->sprites->player_rect.height / 4);
    }
    if (game->player_move.y < 0) {
        pos_1.x += (game->player->sprites->player_rect.width / 4);
        pos_1.y -= (game->player->sprites->player_rect.height / 4);
        pos_2.x -= (game->player->sprites->player_rect.width / 4);
        pos_2.y -= (game->player->sprites->player_rect.height / 4);
        pos_3.y -= (game->player->sprites->player_rect.height / 4);  
    }
}

static int top_down(game_t *game)
{
    sfColor color1 = sfBlack;
    sfColor color2 = sfBlack;
    sfColor color3 = sfBlack;
    sfVector2f pos_1 = game->player->position;
    sfVector2f pos_2 =  game->player->position;
    sfVector2f pos_3 =  game->player->position;

    check_top_and_down(game, pos_1, pos_2, pos_3);
    color1 = sfImage_getPixel(game->map->layers, pos_1.x, pos_1.y);
    color2 = sfImage_getPixel(game->map->layers, pos_2.x, pos_2.y);
    color3 = sfImage_getPixel(game->map->layers, pos_3.x, pos_3.y);
    if (color1.a == 0 || color2.a == 0 || color3.a == 0)
        return KO;
    return OK;
}

static void check_left_and_right(game_t *game, sfVector2f pos_1,
    sfVector2f pos_2, sfVector2f pos_3)
{
    if (game->player_move.x > 0) {
        pos_1.x += (game->player->sprites->player_rect.width / 4);
        pos_1.y += (game->player->sprites->player_rect.height / 4);
        pos_2.x += (game->player->sprites->player_rect.width / 4);
        pos_2.y -= (game->player->sprites->player_rect.height / 4);
        pos_3.x += (game->player->sprites->player_rect.width / 4);
    }
    if (game->player_move.x < 0) {
        pos_1.x -= (game->player->sprites->player_rect.width / 4);
        pos_1.y += (game->player->sprites->player_rect.height / 4);
        pos_2.x -= (game->player->sprites->player_rect.width / 4);
        pos_2.y -= (game->player->sprites->player_rect.height / 4);
        pos_3.x -= (game->player->sprites->player_rect.width / 4);  
    }
}

static int left_right(game_t *game)
{
    sfColor color1 = sfBlack;
    sfColor color2 = sfBlack;
    sfColor color3 = sfBlack;
    sfVector2f pos_1 = game->player->position;
    sfVector2f pos_2 =  game->player->position;
    sfVector2f pos_3 =  game->player->position;

    check_left_and_right(game, pos_1, pos_2, pos_3);
    color1 = sfImage_getPixel(game->map->layers, pos_1.x, pos_1.y);
    color2 = sfImage_getPixel(game->map->layers, pos_2.x, pos_2.y);
    color3 = sfImage_getPixel(game->map->layers, pos_3.x, pos_3.y);
    if (color1.a == 0 || color2.a == 0 || color3.a == 0)
        return KO;
    return OK;
}

static int sprite_move_player(game_t *game)
{
    if (game->player_move.x != 0 && left_right(game) == OK)
        game->player->position.x += game->player_move.x;
    if (game->player_move.y != 0 && top_down(game) == OK)
        game->player->position.y += game->player_move.y;
    if (game->player->position.x < 30)
        game->player->position.x = 30;
    if (game->player->position.x > 930)
        game->player->position.x = 930;
    if (game->player->position.y < 30)
        game->player->position.y = 30;
    if (game->player->position.y > 665)
        game->player->position.y = 665;
    sfSprite_setPosition(game->player->sprites->player, game->player->position);
    if (game->player->position.x > 200 && game->player->position.x < 760)
        game->map->rect.left += game->player_move.x;
    if (game->player->position.y > 100 && game->player->position.y < 595)
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
