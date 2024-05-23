/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** pause_menu_setup
*/

#include "my.h"

static int setup_inventory_sprites(inventory_t **inventory,
    sfRenderWindow *window, sfFont *font)
{
    char const *path[3] = {INVENTORY_SIGN_PATH, INVENTORY_SLOTS_PATH,
        INVENTORY_STATS_PATH};

    for (int i = 0; i < 3; i++) {
        (*inventory)->textures[i] = sfTexture_createFromFile(path[i], NULL);
        (*inventory)->sprites[i] = sfSprite_create();
        sfSprite_setTexture((*inventory)->sprites[i],
            (*inventory)->textures[i], sfFalse);
        set_sprite_mid_origin((*inventory)->sprites[i]);
        sfSprite_setPosition((*inventory)->sprites[i],
            inventory_pos[i]);
        if (!(*inventory)->sprites || !(*inventory)->sprites[i])
            return KO;
    }
    return OK;
}

int inventory_menu_setup(game_t *game, sfRenderWindow *window)
{
    game->inventory->background = sfRectangleShape_create();
    sfRectangleShape_setSize(game->pause->background,
        get_resize(window, 1920, 1080));
    sfRectangleShape_setFillColor(game->pause->background,
        sfColor_fromRGBA(75, 75, 50, 100));
    game->inventory->textures = malloc(sizeof(sfTexture *) * 4);
    game->inventory->sprites = malloc(sizeof(sfSprite *) * 4);
    if (!game->inventory->textures || !game->inventory->sprites)
        return KO;
    game->inventory->sprites[3] = NULL;
    game->inventory->textures[3] = NULL;
    if (setup_inventory_sprites(&game->inventory,
        window, game->pause->font) == KO)
        return KO;
    return OK;
}
