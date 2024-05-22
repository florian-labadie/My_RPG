/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** game_setup
*/

#include "my.h"

static int check_setup_map(rpg_t *rpg)
{
    if (setup_map(rpg->game->map, rpg->window, rpg->setting->sound_game) == KO
        || select_charac(rpg->game, rpg->window) == KO ||
        pause_menu_setup(rpg->game, rpg->window) == KO ||
        setup_house(rpg->game->map, rpg->window) == KO ||
        set_up_battlefield(rpg->window, rpg->game->map,
            rpg->setting->sound_game) == KO ||
        interaction_setup(rpg->game, rpg->window) == KO ||
        inventory_menu_setup(rpg->game, rpg->window) == KO)
        return KO;
    return OK;
}

int game_setup(rpg_t *rpg)
{
    rpg->game->player_move = (sfVector2f) {0.0, 0.0};
    rpg->game->original_view = sfView_create();
    reset_view(rpg->game->original_view, rpg->window,
        (sfVector2f){1920, 1080});
    rpg->game->map = malloc(sizeof(map_t));
    rpg->game->map->house = malloc(sizeof(house_t *) * 3);
    rpg->game->player = malloc(sizeof(player_t));
    rpg->game->player->sprites = malloc(sizeof(player_sprites_t));
    rpg->game->select = malloc(sizeof(select_t));
    rpg->game->pause = malloc(sizeof(pause_t));
    rpg->game->inventory = malloc(sizeof(inventory_t));
    rpg->game->interaction = malloc(sizeof(interaction_t));
    if (!rpg->game->player || !rpg->game->map || !rpg->game->select ||
        !rpg->game->player->sprites)
        return KO;
    if (check_setup_map(rpg) == KO)
        return KO;
    return OK;
}
