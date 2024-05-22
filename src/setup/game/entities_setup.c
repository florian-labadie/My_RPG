/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** map_set_up
*/

#include "my.h"

static int ork_setup(entities_bf_t **entities, sfRenderWindow *window)
{
    (*entities)->ork_text = sfTexture_createFromFile(ORK, NULL);
    if (!(*entities)->ork_text)
        return KO;
    (*entities)->ork_spr = malloc(sizeof(sfSprite *) * NB_ORK);
    (*entities)->ork_rect = (sfIntRect) {0, 0, 50, 65};
    for (int i = 0; i < NB_ORK; i += 1) {
        (*entities)->ork_spr[i] = create_button((*entities)->ork_text,
        (sfVector2f) {3.0, 3.0}, get_resize(window,
        rand() % 1500, rand() % 900));
        sfSprite_setTextureRect((*entities)->ork_spr[i],
        (*entities)->ork_rect);
    }
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
