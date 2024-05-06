/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** settings_menu_event
*/

#include "my.h"

int settings_menu_event(rpg_t *rpg, sfEvent event)
{
    
    return OK;
}

void music_sound(stock_setting_t *setting, settings_t *sprite, rpg_t *rpg)
{
    sfFloatRect bounds;
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(rpg->window);
    sfVector2f mousePosf = { (float)mousePos.x, (float)mousePos.y};

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        bounds = sfSprite_getGlobalBounds(sprite->plus_sign);
        if (sfFloatRect_contains(&bounds, mousePos.x, mousePos.y)) {
            setting->sound_game += 5.0f;
            setting->sound_game = fminf(setting->sound_game, 100.0f);
        }
    }
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sfFloatRect bounds = sfSprite_getGlobalBounds(sprite->minus_sign);
        if (sfFloatRect_contains(&bounds, mousePos.x, mousePos.y)) {
            setting->sound_game -= 5.0f;
            setting->sound_game = fminf(setting->sound_game, 100.0f);
        }
    }
    set_volume_music(setting);
}
