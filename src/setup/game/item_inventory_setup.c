/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** item_inventoyr_setup
*/

#include "my.h"

static int setup_item_weapons(item_t **item, sfRenderWindow *window)
{
    sfIntRect rects_gants[3] = {GANTS_NORM, GANTS_EPIC, GANTS_LEG};
    sfIntRect rects_sword[3] = {SWORD_NORM, SWORD_EPIC, SWORD_LEG};
    sfIntRect rects_staff[3] = {STAFF_NORM, STAFF_EPIC, STAFF_LEG};

    for (int j = 0; j < 3; j += 1) {
        (*item)->weapons[0][j] = create_button((*item)->texture[1],
            get_resize(window, 3, 3), get_resize(window, 420 + (j * 125), 1060));
        sfSprite_setTextureRect((*item)->weapons[0][j], rects_gants[j]);
        set_sprite_mid_origin((*item)->weapons[0][j]);
        sfSprite_setColor((*item)->weapons[0][j], sfColor_fromRGB(100, 100, 100));
        (*item)->weapons[1][j] = create_button((*item)->texture[2],
            get_resize(window, 0.2, 0.2), get_resize(window, 240 + (j * 125), 905));
        sfSprite_setTextureRect((*item)->weapons[1][j], rects_sword[j]);
        set_sprite_mid_origin((*item)->weapons[1][j]);
        sfSprite_setColor((*item)->weapons[1][j], sfColor_fromRGB(100, 100, 100));
        (*item)->weapons[2][j] = create_button((*item)->texture[3],
           get_resize(window, 6, 6), get_resize(window, 490 + (j * 130), 1230));
        sfSprite_setTextureRect((*item)->weapons[2][j], rects_staff[j]);
        set_sprite_mid_origin((*item)->weapons[2][j]);
        sfSprite_setColor((*item)->weapons[2][j], sfColor_fromRGB(100, 100, 100));
    }
    return OK;
}

static int setup_item_potion(item_t **item, sfRenderWindow *window)
{   
    (*item)->health_pot = malloc(sizeof(sfSprite *) * 5);
    (*item)->mana_pot = malloc(sizeof(sfSprite *) * 5);
    for (int i = 0; i < 4; i++) {
        (*item)->health_pot[i] = create_button((*item)->texture[0],
            get_resize(window, 0.4, 0.4), get_resize(window, 265 + (i * 130), 320));
        sfSprite_setTextureRect((*item)->health_pot[i], SLOTH_HEALTH);
        set_sprite_mid_origin((*item)->health_pot[i]);
        sfSprite_setColor((*item)->health_pot[i], sfColor_fromRGB(100, 100, 100));
    }
    for (int i = 0; i < 4; i++) {
        (*item)->mana_pot[i] = create_button((*item)->texture[0],
            get_resize(window, 0.3, 0.3), get_resize(window, 260 + (i * 130), 580));
        sfSprite_setTextureRect((*item)->mana_pot[i], SLOTH_MANA);
        set_sprite_mid_origin((*item)->mana_pot[i]);
        sfSprite_setColor((*item)->mana_pot[i], sfColor_fromRGB(100, 100, 100));
    }
    return OK;
}

int setup_item_inventory(game_t *game, sfRenderWindow *window)
{
    game->inventory->item->texture = malloc(sizeof(sfTexture *) * 5);
    game->inventory->item->weapons = malloc(sizeof(sfSprite **) * 4);
    for (int i = 0; i < 3; i += 1) {
        game->inventory->item->weapons[i] = malloc(sizeof(sfSprite *) * 4);
        game->inventory->item->weapons[i][3] = NULL;
    }
    if (!game->inventory->item->texture || !game->inventory->item->weapons)
        return KO;
    game->inventory->item->weapons[3] = NULL;
    game->inventory->item->texture[0] = sfTexture_createFromFile(POTION, NULL);
    game->inventory->item->texture[1] = sfTexture_createFromFile(GANTS, NULL);
    game->inventory->item->texture[2] = sfTexture_createFromFile(SWORD, NULL);
    game->inventory->item->texture[3] =
        sfTexture_createFromFile(MAGIC_STAFF, NULL);
    game->inventory->item->texture[4] = NULL;
    if (setup_item_potion(&game->inventory->item, window) == KO ||
        setup_item_weapons(&game->inventory->item, window) == KO)
        return KO;
    return OK;
}
