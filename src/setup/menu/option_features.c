/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** option_features.c
*/

#include "my.h"

void set_fps(rpg_t *rpg, sfEvent event)
{
    sfVector2f mouse = get_mouse_pos(rpg->window, rpg->window_size);
    sfBool f_15 = get_sprite_bounds(rpg->menu->settings->fps_sp[0], mouse);
    sfBool f_45 = get_sprite_bounds(rpg->menu->settings->fps_sp[1], mouse);
    sfBool f_60 = get_sprite_bounds(rpg->menu->settings->fps_sp[2], mouse);

    if (event.type == sfEvtMouseButtonReleased && f_15 == sfTrue) {
        rpg->setting->fps = 15;
        sfRenderWindow_setFramerateLimit(rpg->window, rpg->setting->fps);
    }
    if (event.type == sfEvtMouseButtonReleased && f_45 == sfTrue) {
        rpg->setting->fps = 45;
        sfRenderWindow_setFramerateLimit(rpg->window, rpg->setting->fps);
    }
    if (event.type == sfEvtMouseButtonReleased && f_60 == sfTrue) {
        rpg->setting->fps = 60;
        sfRenderWindow_setFramerateLimit(rpg->window, rpg->setting->fps);
    }
}

void set_window_size(rpg_t *rpg, sfEvent event)
{
    sfVector2f mouse = get_mouse_pos(rpg->window, rpg->window_size);
    sfBool full = get_sprite_bounds(rpg->menu->settings->reso_sp[0], mouse);
    sfBool split = get_sprite_bounds(rpg->menu->settings->reso_sp[1], mouse);

    if (event.type == sfEvtMouseButtonReleased && full == sfTrue)
        sfRenderWindow_setSize(rpg->window, (sfVector2u){1920, 1080});
    if (event.type == sfEvtMouseButtonReleased && split == sfTrue)
        sfRenderWindow_setSize(rpg->window, (sfVector2u){960, 540});
}

void update_volume_text(rpg_t *rpg, float volume)
{
    char volume_str[10];

    snprintf(volume_str, sizeof(volume_str), "%.0f", volume);
    sfText_setString(rpg->menu->setting->volume_text, volume_str);
}

void music_sound(rpg_t *rpg, sfEvent event)
{
    sfVector2f mouse = get_mouse_pos(rpg->window, rpg->window_size);
    sfBool plus = get_sprite_bounds(rpg->menu->settings->intern_sp[0], mouse);
    sfBool minus = get_sprite_bounds(rpg->menu->settings->intern_sp[1], mouse);

    if (event.type == sfEvtMouseButtonReleased && plus == sfTrue) {
        rpg->setting->sound_game += 10.0f;
        rpg->setting->sound_game =
        fminf(rpg->setting->sound_game, 100.0f);
    }
    if (event.type == sfEvtMouseButtonReleased && minus == sfTrue) {
        rpg->setting->sound_game -= 10.0f;
        rpg->setting->sound_game =
        fminf(rpg->setting->sound_game, 100.0f);
    }
}
