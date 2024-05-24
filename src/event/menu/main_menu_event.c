/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** main_menu_event
*/

#include "my.h"

static int change_text_rect(main_menu_buttons_t **button,
    button_state_t status, int i)
{
    int move = 5;
    sfVector2f current_pos = {};

    if ((*button)->buttons_status[i] == status)
        return OK;
    if ((*button)->buttons_status[i] > status) {
        move = -move;
    }
    if ((*button)->buttons_status[i] == BUTTON_PRESSED && status == NORMAL)
        move *= 2;
    current_pos = sfText_getPosition((*button)->text[i]);
    sfText_setPosition((*button)->text[i],
                        (sfVector2f){current_pos.x, current_pos.y + move});
    return OK;
}

static int change_screen_status(rpg_t **rpg, int i)
{
    if (i == 0) {
        if (!(*rpg)->game->map && game_setup(*rpg) == KO)
            return KO;
        (*rpg)->game->map->rect = (sfFloatRect){0.0, get_resize((*rpg)->window,
            495.0, 0).x, 400.0, 200.0};
        (*rpg)->screen = GAME;
        sfMusic_stop((*rpg)->menu->menu_sound);
        (*rpg)->game->screen = SELECTION;
    }
    if (i == 2)
        (*rpg)->menu->screen = SETTING;
    if (i == 3) {
        (*rpg)->screen = END;
        sfRenderWindow_close((*rpg)->window);
    }
    if (i == 4) {
        (*rpg)->menu->screen = HELP;
    }
    return OK;
}

static int main_menu_button(main_menu_buttons_t **buttons,
    sfVector2f mouse_pos, button_state_t status, sfSound *sound)
{
    for (int i = 0; (*buttons)->sprites[i]; i++) {
        if (i == 1)
            continue;
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
    return OK;
}

static int buttons_action(rpg_t *rpg, sfVector2f mouse_pos)
{
    sfFloatRect rect =
    sfSprite_getGlobalBounds(rpg->menu->main_menu->buttons->help_back_spr);

    if (sfFloatRect_contains(&rect, mouse_pos.x, mouse_pos.y))
        return change_screen_status(&rpg, 4);
    for (int i = 0; rpg->menu->main_menu->buttons->sprites[i]; i++) {
        if (i == 1)
            continue;
        if (rpg->menu->main_menu->buttons->buttons_status[i] != NORMAL) {
            change_text_rect(&rpg->menu->main_menu->buttons, NORMAL, i);
            change_button_rect(rpg->menu->main_menu->buttons->sprites[i],
                &rpg->menu->main_menu->buttons->buttons_status[i],
                    NORMAL, NULL);
        }
        if (get_sprite_bounds
            (rpg->menu->main_menu->buttons->sprites[i], mouse_pos) == sfTrue)
            return change_screen_status(&rpg, i);
    }
    return OK;
}

int main_menu_event(rpg_t *rpg, sfEvent event)
{
    sfVector2f mouse_pos = get_mouse_pos(rpg->window, rpg->window_size);

    if (event.mouseButton.type == sfEvtMouseButtonReleased &&
        event.mouseButton.button == sfMouseLeft)
        return buttons_action(rpg, mouse_pos);
    if ((event.mouseButton.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft) ||
        already_pressed(rpg->menu->main_menu->buttons->buttons_status,
            4) == OK) {
        if (already_pressed(rpg->menu->main_menu->buttons->buttons_status, 4)
            == OK)
            return OK;
        return main_menu_button(&rpg->menu->main_menu->buttons, mouse_pos,
                        BUTTON_PRESSED, rpg->menu->click_button_sound);
    }
    return main_menu_button(&rpg->menu->main_menu->buttons, mouse_pos,
                        HOVER, rpg->menu->click_button_sound);
}

int parallax_event(rpg_t *rpg, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace)
        rpg->menu->screen = MAIN;
    return 0;
}
