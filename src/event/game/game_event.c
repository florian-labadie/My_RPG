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
        set_pause_screen((*rpg)->game->pause, (*rpg)->game->map->rect);
        (*rpg)->game->player_move = (sfVector2f){0, 0};
        (*rpg)->game->screen = PAUSE;
        return OK;
    }
    return OK;
}

static void show_flag(rpg_t *rpg, sfEvent event)
{
    rpg->game->map->flag.is_flag = false;
    if (get_rectangle_bounds(rpg->game->map->flag.flag_zone,
    sfSprite_getPosition(rpg->game->player->sprites->player)) == sfTrue) {
        if (event.key.code == sfKeyF && event.type == sfEvtKeyPressed) {
            rpg->game->map->choice_map = BATTLEFIELD;
            sfMusic_stop(rpg->game->map->game_sound);
            sfMusic_play(rpg->game->map->battle_music);
            sfView_setSize(rpg->game->map->view,
            get_resize(rpg->window, 1920, 1080));
            sfView_setCenter(rpg->game->map->view,
                get_resize(rpg->window, 960, 540));
            sfRenderWindow_setView(rpg->window, rpg->game->map->view);
            sfSprite_setPosition(rpg->game->player->sprites->player,
            (sfVector2f) {1685.0, 940});
            sfSprite_setScale(rpg->game->player->sprites->player,
            (sfVector2f) {2.5, 2.5});
        }
        rpg->game->map->flag.is_flag = true;
    }
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
    }
    return OK;
}
