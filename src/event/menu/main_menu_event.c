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
    if ((*button)->buttons_status[i] == PRESSED && status == NORMAL)
        move *= 2;
    current_pos = sfText_getPosition((*button)->text[i]);
    sfText_setPosition((*button)->text[i],
                        (sfVector2f){current_pos.x, current_pos.y + move});
}

static int already_pressed(button_state_t *button_status)
{
    for (int i = 0; i < 3; i++) {
        if (button_status[i] == PRESSED)
            return OK;
    }
    return KO;
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

void main_menu_event(rpg_t *rpg, sfEvent event)
{
    sfVector2i __2imouse_pos = sfMouse_getPositionRenderWindow(rpg->window);
    sfVector2f mouse_pos = (sfVector2f){__2imouse_pos.x, __2imouse_pos.y};

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (already_pressed(rpg->menu->main_menu->buttons->buttons_status)
            == OK)
            return;
        main_menu_button(&rpg->menu->main_menu->buttons, mouse_pos,
                        PRESSED, rpg->menu->click_button_sound);
    } else {
        main_menu_button(&rpg->menu->main_menu->buttons, mouse_pos,
                        HOVER, rpg->menu->click_button_sound);
    }
}
