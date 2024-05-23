/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** map_set_up
*/

#include "my.h"

static int fill_ork_struct(entities_bf_t **entities, sfRenderWindow *window,
    sfTexture *ork_texture, sfVector2f pos)
{
    for (int i = 0; i < NB_ORK; i += 1) {
        (*entities)->ork[i] = malloc(sizeof(ork_t));
        if (!(*entities)->ork[i])
            return KO;
        pos = (sfVector2f) {rand() % 1400, rand() % 800};
        (*entities)->ork[i]->ork_spr = create_button(ork_texture,
        (sfVector2f) {3.0, 3.0}, get_resize(window,
        pos.x, pos.y));
        (*entities)->ork[i]->ork_rect = (sfIntRect) {0, 0, 50, 65};
        sfSprite_setTextureRect((*entities)->ork[i]->ork_spr,
        (*entities)->ork[i]->ork_rect);
        (*entities)->ork[i]->hp = 200;
        (*entities)->ork[i]->hitbox = sfCircleShape_create();
        sfCircleShape_setRadius((*entities)->ork[i]->hitbox, 90);
        sfCircleShape_setOrigin((*entities)->ork[i]->hitbox, (sfVector2f)
        {5, 5});
        sfCircleShape_setPosition((*entities)->ork[i]->hitbox,
        get_resize(window, pos.x - 40, pos.y + 30));
    }
}

static int ork_setup(entities_bf_t **entities, sfRenderWindow *window)
{
    sfTexture *ork_texture = sfTexture_createFromFile(ORK, NULL);
    sfVector2f pos = (sfVector2f) {0.0, 0.0};

    (*entities)->ork = malloc(sizeof(ork_t *) * NB_ORK);
    if (!ork_texture || !(*entities)->ork)
        return KO;
    for (int i = 0; i < NB_ORK; i += 1)
        (*entities)->ork[i] = NULL;
    if (fill_ork_struct(entities, window, ork_texture, pos) == KO)
        return KO;
    return OK;
}

static int wizzard_setup(entities_bf_t **entities, sfRenderWindow *window)
{
    (*entities)->wizzard_rect = (sfIntRect) {0, 202, 204, 202};
    (*entities)->wizz_clock = sfClock_create();
    (*entities)->wizzard_text = sfTexture_createFromFile(WIZZARD, NULL);
    if (!(*entities)->wizzard_text)
        return KO;
    (*entities)->wizzard_spr = create_button((*entities)->wizzard_text,
    (sfVector2f) {1.5, 1.5}, get_resize(window, 1700.0, 840.0));
    sfSprite_setTextureRect((*entities)->wizzard_spr,
    (*entities)->wizzard_rect);
    return OK;
}

int entities_setup(entities_bf_t **entities, sfRenderWindow *window)
{
    *entities = malloc(sizeof(entities_bf_t));
    if (!(*entities))
        return KO;
    if (ork_setup(entities, window) == KO ||
    wizzard_setup(entities, window) == KO)
        return KO;
    return OK;
}
