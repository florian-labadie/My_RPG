/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** settings_menu_event
*/

#include "my.h"

int settings_menu_event(rpg_t *rpg, sfEvent event)
{
    (void)rpg;
    (void)event;
    return OK;
}

void exit_action(menu_t *menu, sfBool exit)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && exit == sfTrue) {
        menu->screen = MAIN;
    }
}

void book_pages
(sfRenderWindow *window, menu_t *menu, sfBool arrow_l, sfBool arrow_r)
{
    if (menu->settings->arrow_bool_r == sfTrue) {
        sfRenderWindow_drawSprite(window, menu->settings->book_sp[2], NULL);
        turn_book
        (menu->settings, menu->settings->book_sp[2], menu->settings->b_clock);
    }
    if (menu->settings->arrow_bool_l == sfTrue) {
        sfRenderWindow_drawSprite(window, menu->settings->book_sp[1], NULL);
        turn_book
        (menu->settings, menu->settings->book_sp[1], menu->settings->b_clock);
    }
    if (menu->settings->current_page == 1) {
        handle_events_page_1(menu);
    } else if (menu->settings->current_page == 2) {
        handle_events_page_2(menu);
    }
}

void book_actions
(sfRenderWindow *window, menu_t *menu, sfBool arrow_l, sfBool arrow_r)
{
    sfVector2i mouse_pi = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse_p = {(float)mouse_pi.x, (float)mouse_pi.y};

    if (sfMouse_isButtonPressed(sfMouseLeft) && arrow_r == sfTrue) {
        menu->settings->arrow_bool_r = sfTrue;
        menu->settings->arrow_bool_l = sfFalse;
        if (menu->settings->current_page < MAX_PAGES)
            menu->settings->current_page++;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && arrow_l == sfTrue) {
        menu->settings->arrow_bool_l = sfTrue;
        menu->settings->arrow_bool_r = sfFalse;
        if (menu->settings->current_page == MAX_PAGES)
            menu->settings->current_page--;
    }
    book_pages(window, menu, arrow_l, arrow_r);
}

void music_sound(menu_t *menu)
{
    sfVector2i mouse_p = sfMouse_getPositionRenderWindow(menu->window);
    sfVector2f mousep = {(float)mouse_p.x, (float)mouse_p.y};
    sfBool plus = get_sprite_bounds(menu->settings->intern_sp[0], mousep);
    sfBool minus = get_sprite_bounds(menu->settings->intern_sp[1], mousep);

    if (sfMouse_isButtonPressed(sfMouseLeft) && plus == sfTrue) {
        menu->setting->sound_game += 10.0f;
        menu->setting->sound_game = fminf(menu->setting->sound_game, 100.0f);
        update_volume_text(menu->settings, menu->setting->sound_game);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && minus == sfTrue) {
        menu->setting->sound_game -= 10.0f;
        menu->setting->sound_game = fminf(menu->setting->sound_game, 100.0f);
        update_volume_text(menu->settings, menu->setting->sound_game);
    }
}
