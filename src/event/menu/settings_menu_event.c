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

void book_pages(rpg_t *rpg, sfEvent event, sfBool arrow_l, sfBool arrow_r)
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
    book_pages
    (rpg, event, rpg->menu->settings->arrowl, rpg->menu->settings->arrowr);
    return OK;
}

void music_sound(rpg_t *rpg, sfEvent event)
{
    sfVector2f mouse = get_mouse_pos(rpg->window, rpg->window_size);
    sfBool plus = get_sprite_bounds(rpg->menu->settings->intern_sp[0], mouse);
    sfBool minus = get_sprite_bounds(rpg->menu->settings->intern_sp[1], mouse);

    if (event.type == sfEvtMouseButtonReleased && plus == sfTrue) {
        rpg->menu->setting->sound_game += 10.0f;
        rpg->menu->setting->sound_game =
        fminf(rpg->menu->setting->sound_game, 100.0f);
        update_volume_text
        (rpg->menu->settings, rpg->menu->setting->sound_game);
    }
    if (event.type == sfEvtMouseButtonReleased && minus == sfTrue) {
        rpg->menu->setting->sound_game -= 10.0f;
        rpg->menu->setting->sound_game =
        fminf(rpg->menu->setting->sound_game, 100.0f);
        update_volume_text
        (rpg->menu->settings, rpg->menu->setting->sound_game);
    }
    set_volume_music(rpg);
}
