/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** background_menu_manager
*/

#include "my.h"

void ork_movement(sfVector2f ork_pos, sfVector2f player_pos, ork_t *ork,
    float speed)
{
    float dx = player_pos.x - ork_pos.x;
    float dy = player_pos.y - ork_pos.y;

    if (dx != 0) {
        ork_pos.x += (dx > 0 ? 1 : -1) * speed;
        if ((dx > 0 && ork_pos.x >= player_pos.x) ||
            (dx < 0 && ork_pos.x <= player_pos.x)) {
            ork_pos.x = player_pos.x;
        }
    }
    if (dy != 0) {
        ork_pos.y += (dy > 0 ? 1 : -1) * speed;
        if ((dy > 0 && ork_pos.y >= player_pos.y) ||
            (dy < 0 && ork_pos.y <= player_pos.y)) {
            ork_pos.y = player_pos.y;
        }
    }
    sfSprite_setPosition(ork->ork_spr, ork_pos);
    sfCircleShape_setPosition(ork->hitbox, (sfVector2f)
    {ork_pos.x - 40, ork_pos.y + 30});
}
