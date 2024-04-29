/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** main_menu_event
*/

#include "my.h"

static void change_text_rect(main_menu_buttons_t **button,
    button_state_t status, int i)
{
    int move = 5;
    sfVector2f current_pos = {};

    if ((*button)->buttons_status[i] == status)
        return;
    if ((*button)->buttons_status[i] > status) {
        move = -move;
    }
    if ((*button)->buttons_status[i] == BUTTON_PRESSED && status == NORMAL)
        move *= 2;
    current_pos = sfText_getPosition((*button)->text[i]);
    sfText_setPosition((*button)->text[i],
                        (sfVector2f){current_pos.x, current_pos.y + move});
}

static int already_pressed(button_state_t *button_status)
{
    for (int i = 0; i < 4; i++) {
        if (button_status[i] == BUTTON_PRESSED)
            return OK;
    }
    return KO;
}

static void change_screen_status(rpg_t **rpg, int i)
{
    if (i <= 1) {
        (*rpg)->screen = GAME;
        sfMusic_stop((*rpg)->menu->menu_sound);
        (*rpg)->game->screen = (game_state_t)i;
    }
    if (i == 2)
        (*rpg)->menu->screen = SETTING;
    if (i == 3)
        sfRenderWindow_close((*rpg)->window);
}

static void main_menu_button(main_menu_buttons_t **buttons,
    sfVector2f mouse_pos, button_state_t status, sfSound *sound)
{
    for (int i = 0; (*buttons)->sprites[i]; i++) {
        if (get_sprite_bounds((*buttons)->sprites[i], mouse_pos) == sfTrue &&
            (*buttons)->buttons_status[i] != status) {
            change_text_rect(buttons, status, i);
            return change_button_rect((*buttons)->sprites[i],
                &(*buttons)->buttons_status[i], status, sound);
            }
        if (get_sprite_bounds((*buttons)->sprites[i], mouse_pos) == sfFalse &&
            (*buttons)->buttons_status[i] != NORMAL) {
            change_text_rect(buttons, NORMAL, i);
            return change_button_rect((*buttons)->sprites[i],
                &(*buttons)->buttons_status[i], NORMAL, sound);
            }
    }
}

static void buttons_action(rpg_t *rpg, sfEvent event, sfVector2f mouse_pos)
{
    for (int i = 0; rpg->menu->main_menu->buttons->sprites[i]; i++) {
        if (rpg->menu->main_menu->buttons->buttons_status[i] ==
            BUTTON_PRESSED) {
            change_text_rect(&rpg->menu->main_menu->buttons, NORMAL, i);
            change_button_rect(rpg->menu->main_menu->buttons->sprites[i],
                &rpg->menu->main_menu->buttons->buttons_status[i],
                    NORMAL, NULL);
        }
        if (get_sprite_bounds
            (rpg->menu->main_menu->buttons->sprites[i], mouse_pos) == sfTrue)
            return change_screen_status(&rpg, i);
    }
}

void main_menu_event(rpg_t *rpg, sfEvent event)
{
    sfVector2f mouse_pos = get_mouse_pos(rpg->window, rpg->window_size);

    if (event.mouseButton.type == sfEvtMouseButtonReleased)
        return buttons_action(rpg, event, mouse_pos);
    if (event.mouseButton.type == sfEvtMouseButtonPressed ||
        already_pressed(rpg->menu->main_menu->buttons->buttons_status) == OK) {
        if (already_pressed(rpg->menu->main_menu->buttons->buttons_status)
            == OK)
            return;
        return main_menu_button(&rpg->menu->main_menu->buttons, mouse_pos,
                        BUTTON_PRESSED, rpg->menu->click_button_sound);
    }
    return main_menu_button(&rpg->menu->main_menu->buttons, mouse_pos,
                        HOVER, rpg->menu->click_button_sound);
}
