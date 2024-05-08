/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** settings_menu_event
*/

#include "my.h"

int settings_menu_event(sfRenderWindow *window, sfEvent event)
{
    return OK;
}

void exit_action(menu_t *menu, sfBool exit)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && exit == sfTrue) {
        menu->screen = MAIN;
    }
}

void book_actions
(sfRenderWindow *window, menu_t *menu, sfBool arrow_l, sfBool arrow_r)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && arrow_r == sfTrue) {
        menu->settings->arrow_bool_r = sfTrue;
        menu->settings->arrow_bool_l = sfFalse;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && arrow_l == sfTrue) {
        menu->settings->arrow_bool_l = sfTrue;
        menu->settings->arrow_bool_r = sfFalse;
    }
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
}

void music_sound(rpg_t *rpg)
{
    sfVector2i mouse_p = sfMouse_getPositionRenderWindow(rpg->window);
    sfVector2f mousep = {(float)mouse_p.x, (float)mouse_p.y};
    sfBool is_plus = get_sprite_bounds(rpg->menu->settings->plus_sp, mousep);
    sfBool is_minus = get_sprite_bounds(rpg->menu->settings->minus_sp, mousep);

    if (sfMouse_isButtonPressed(sfMouseLeft) && is_plus == sfTrue) {
        rpg->setting->sound_game += 5.0f;
        rpg->setting->sound_game = fminf(rpg->setting->sound_game, 100.0f);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && is_minus == sfTrue) {
            rpg->setting->sound_game -= 5.0f;
            rpg->setting->sound_game = fminf(rpg->setting->sound_game, 100.0f);
    }
    set_volume_music(rpg);
}
