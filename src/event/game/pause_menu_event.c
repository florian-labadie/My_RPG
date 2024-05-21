/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** pause_menu_event
*/

#include "my.h"

void set_pause_screen(pause_t *pause, sfFloatRect view_rect)
{
    sfVector2f pos = (sfVector2f){view_rect.left + 200, view_rect.top + 25};

    sfSprite_setPosition(pause->sprites[3], pos);
    sfText_setPosition(pause->text[3], (sfVector2f){pos.x, pos.y});
    pos.y += 50;
    for (int i = 0; i < 3; i++) {
        sfSprite_setPosition(pause->sprites[i], pos);
        sfText_setPosition(pause->text[i], (sfVector2f){pos.x, pos.y - 2.0});
        pos.y += 50;
    }
}

static int change_event_from_pause(rpg_t **rpg, int i)
{
    if (i == 0)
        (*rpg)->game->screen = PLAYING;
    if (i == 1) {
        sfView_setSize((*rpg)->game->map->view,
            get_resize((*rpg)->window, 1920, 1080));
        sfView_setCenter((*rpg)->game->map->view,
            get_resize((*rpg)->window, 960, 540));
        sfRenderWindow_setView((*rpg)->window, (*rpg)->game->map->view);
        (*rpg)->screen = MAIN_MENU;
        (*rpg)->menu->screen = MAIN;
    }
    if (i == 2)
        (*rpg)->screen = END;
    return OK;
}

static int pause_buttons_action(rpg_t **rpg, sfVector2f mouse_pos)
{
    for (int i = 0; i < 3; i++) {
        if ((*rpg)->game->pause->buttons_status[i] != NORMAL) {
            change_button_rect((*rpg)->game->pause->sprites[i],
                &(*rpg)->game->pause->buttons_status[i],
                    NORMAL, NULL);
        }
        if (get_sprite_bounds
            ((*rpg)->game->pause->sprites[i], mouse_pos) == sfTrue)
            return change_event_from_pause(rpg, i);
    }
    return OK;
}

static int pause_menu_button(pause_t **pause,
    sfVector2f mouse_pos, button_state_t status, sfSound *sound)
{
    for (int i = 0; i < 3; i++) {
        if (get_sprite_bounds((*pause)->sprites[i], mouse_pos) == sfTrue &&
            (*pause)->buttons_status[i] != status) {
            return change_button_rect((*pause)->sprites[i],
                &(*pause)->buttons_status[i], status, sound);
            }
        if (get_sprite_bounds((*pause)->sprites[i], mouse_pos) == sfFalse &&
            (*pause)->buttons_status[i] != NORMAL)
            return change_button_rect((*pause)->sprites[i],
                &(*pause)->buttons_status[i], NORMAL, sound);
    }
    return OK;
}

int pause_menu_event(rpg_t *rpg, sfEvent event)
{
    sfVector2f mouse_pos = get_mouse_pos(rpg->window, (sfVector2u){400, 200});

    mouse_pos = (sfVector2f){mouse_pos.x + rpg->game->map->rect.left,
        mouse_pos.y + rpg->game->map->rect.top};
    if (event.key.code == sfKeyEscape && event.key.type == sfEvtKeyPressed)
        rpg->game->screen = PLAYING;
    if (event.mouseButton.type == sfEvtMouseButtonReleased)
        return pause_buttons_action(&rpg, mouse_pos);
    if (event.mouseButton.type == sfEvtMouseButtonPressed ||
        already_pressed(rpg->menu->main_menu->buttons->buttons_status, 3)
            == OK) {
        if (already_pressed(rpg->menu->main_menu->buttons->buttons_status, 3)
            == OK)
            return OK;
        return pause_menu_button(&rpg->game->pause, mouse_pos,
                        BUTTON_PRESSED, rpg->menu->click_button_sound);
    }
    return pause_menu_button(&rpg->game->pause, mouse_pos,
                        HOVER, rpg->menu->click_button_sound);
}
