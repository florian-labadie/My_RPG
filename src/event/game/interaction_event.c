/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** interaction_event
*/

#include "my.h"

static void actions_rect_reponse(rpg_t *rpg, sfRectangleShape **shape,
    int i, sfVector2f mouse_pos)
{
    if (get_rectangle_bounds(shape[0], mouse_pos) == sfTrue) {
    }
    if (get_rectangle_bounds(shape[1], mouse_pos) == sfTrue) {
        rpg->game->player->position = (sfVector2f){140.0, 440.0};
        sfSprite_setPosition(rpg->game->player->sprites->player,
            rpg->game->player->position);
        rpg->game->map->choice_map = VILLAGE;
        sfMusic_stop(rpg->game->map->house[i]->house_music);
        sfMusic_play(rpg->game->map->game_sound);
    }
}

static void button_action(rpg_t *rpg, sfVector2f mouse_pos)
{
    for (int i = 0; rpg->game->interaction->zone_text[i] != NULL; i++) {
        actions_rect_reponse(rpg, rpg->game->interaction->zone_text[i],
            i, mouse_pos);
    }
}

void interaction_event(rpg_t *rpg, sfEvent event)
{
    sfVector2i mouse_pos_int = {event.mouseButton.x, event.mouseButton.y};
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(rpg->window,
        mouse_pos_int, rpg->game->map->view);

    if (event.mouseButton.type == sfEvtMouseButtonReleased)
        return button_action(rpg, mouse_pos);
}
