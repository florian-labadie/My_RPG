/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** select_event
*/

#include "my.h"

static int choose_character(rpg_t *rpg, player_race_t *current,
    player_race_t race)
{
    if ((int)race == -1)
        race = 2;
    if (race > 2)
        race = 0;
    if (race == HUMAN) {
        sfSprite_setPosition(rpg->game->select->arrow_selec,
            get_resize(rpg->window, 325.0, 200.0));
        *current = race;
    }
    if (race == DWARF) {
        sfSprite_setPosition(rpg->game->select->arrow_selec,
            get_resize(rpg->window, 325.0, 450.0));
        *current = race;
    }
    if (race == ELF) {
        sfSprite_setPosition(rpg->game->select->arrow_selec,
            get_resize(rpg->window, 325.0, 700.0));
        *current = race;
    }
    return OK;
}

static int change_screen_status(rpg_t **rpg, int i)
{
    if (i == 0)
        (*rpg)->game->screen = LOAD_GAME;
    if (i == 1) {
        (*rpg)->screen = MAIN_MENU;
        (*rpg)->menu->screen = MAIN;
        sfMusic_play((*rpg)->menu->menu_sound);
        sfMusic_stop((*rpg)->game->map->game_sound);
    }
    return OK;
}

static int buttons_select_action(rpg_t *rpg, sfEvent event,
    sfVector2f mouse_pos)
{
    for (int i = 0; rpg->game->select->button_select[i] != NULL; i++) {
        if (get_sprite_bounds
            (rpg->game->select->button_select[i], mouse_pos) == sfTrue)
            return change_screen_status(&rpg, i);
    }
    for (int i = 0; rpg->game->select->characters[i] != NULL; i++) {
        if (get_sprite_bounds
            (rpg->game->select->characters[i], mouse_pos) == sfTrue)
            return choose_character(rpg, &rpg->game->select->player, i);
    }
    return OK;
}

static void sprite_growth(rpg_t *rpg, sfVector2f mouse_pos)
{
    for (int i = 0; rpg->game->select->button_select[i] != NULL; i++) {
        if (get_sprite_bounds
            (rpg->game->select->button_select[i], mouse_pos) == sfTrue) {
            sfSprite_setScale(rpg->game->select->button_select[i],
                get_resize(rpg->window, 2.5, 2.5));
        } else
            sfSprite_setScale(rpg->game->select->button_select[i],
                get_resize(rpg->window, 2, 2));
    }
    for (int i = 0; rpg->game->select->characters[i] != NULL; i++) {
        if (get_sprite_bounds
                (rpg->game->select->characters[i], mouse_pos) == sfTrue) {
            sfSprite_setScale(rpg->game->select->characters[i],
                get_resize(rpg->window, 3, 3));
        } else
            sfSprite_setScale(rpg->game->select->characters[i],
                get_resize(rpg->window, 2.5, 2.5));
    }
}

int select_event(rpg_t *rpg, sfEvent event)
{
    sfVector2f mouse_pos = get_mouse_pos(rpg->window, rpg->window_size);

    if (event.mouseButton.type == sfEvtMouseButtonReleased)
        return buttons_select_action(rpg, event, mouse_pos);
    if (event.key.type == sfEvtKeyPressed && event.key.code == sfKeyDown)
        return choose_character(rpg, &rpg->game->select->player,
            (int)rpg->game->select->player + 1);
    if (event.key.type == sfEvtKeyPressed && event.key.code == sfKeyUp)
        return choose_character(rpg, &rpg->game->select->player,
            (int)rpg->game->select->player - 1);
    sprite_growth(rpg, mouse_pos);
    return OK;
}
