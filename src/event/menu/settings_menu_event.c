/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** settings_menu_event
*/

#include "my.h"

void exit_action(rpg_t *rpg, sfEvent event, sfBool exit)
{
    if (event.type == sfEvtMouseButtonReleased && exit == sfTrue) {
        rpg->menu->screen = MAIN;
    }
}

void book_pages(rpg_t *rpg, sfEvent event)
{
    if (rpg->menu->settings->current_page == 0) {
        handle_events_page_1(rpg, event);
    } else if (rpg->menu->settings->current_page == 1) {
        handle_events_page_2(rpg, event);
    }
}

void book_actions(rpg_t *rpg, sfEvent event, sfBool arrow_l, sfBool arrow_r)
{
    if (event.type == sfEvtMouseButtonReleased && arrow_r == sfTrue) {
        if (rpg->menu->settings->current_page < MAX_PAGES) {
            rpg->menu->settings->current_page++;
            begin_anim(rpg->menu->settings->book_sp[2]);
        } else
            rpg->menu->settings->arrowr = sfFalse;
    }
    if (event.type == sfEvtMouseButtonReleased && arrow_l == sfTrue) {
        if (rpg->menu->settings->current_page == MAX_PAGES) {
            rpg->menu->settings->current_page--;
                begin_anim(rpg->menu->settings->book_sp[1]);
        } else
            rpg->menu->settings->arrowl = sfFalse;
    }
}

int settings_menu_event(rpg_t *rpg, sfEvent event)
{
    sfVector2f mouse = get_mouse_pos(rpg->window, rpg->window_size);
    sfBool exit = get_sprite_bounds(rpg->menu->settings->extern_sp[2], mouse);

    if (event.type == sfEvtMouseButtonReleased) {
        rpg->menu->settings->arrowl =
        get_sprite_bounds(rpg->menu->settings->extern_sp[0], mouse);
        rpg->menu->settings->arrowr =
        get_sprite_bounds(rpg->menu->settings->extern_sp[1], mouse);
    }
    exit_action(rpg, event, exit);
    book_actions
    (rpg, event, rpg->menu->settings->arrowl, rpg->menu->settings->arrowr);
    book_pages(rpg, event);
    return OK;
}
