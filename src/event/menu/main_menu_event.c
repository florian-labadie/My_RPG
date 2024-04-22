/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** main_menu_event
*/

#include "my.h"

static int already_pressed(button_state_t *button_status)
{
    for (int i = 0; i < 3; i++) {
        if (button_status[i] == PRESSED)
            return OK;
    }
    return KO;
}

static void main_menu_button(sfSprite **buttons, button_state_t *button_status,
    sfVector2f mouse_pos, button_state_t status)
{
    for (int i = 0; buttons[i]; i++) {
        if (get_sprite_bounds(buttons[i], mouse_pos) == sfTrue &&
            button_status[i] != status)
            change_button_rect(buttons[i],
                &button_status[i], status);
        if (get_sprite_bounds(buttons[i], mouse_pos) == sfFalse &&
            button_status[i] != NORMAL)
            change_button_rect(buttons[i],
                &button_status[i], NORMAL);
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
        main_menu_button(rpg->menu->main_menu->buttons->sprites,
            rpg->menu->main_menu->buttons->buttons_status, mouse_pos, PRESSED);
    } else {
        main_menu_button(rpg->menu->main_menu->buttons->sprites,
            rpg->menu->main_menu->buttons->buttons_status, mouse_pos, HOVER);
    }
}
