/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** villager_setup.c
*/

#include "my.h"

static int setup_villager_sp(game_t *game, sfRenderWindow *window)
{
    char *path[4] = {RICH_MAN_P, OLD_LADY_P, WOMAN_P, WORKER_P};

    for (int i = 0; i < 4; i++) {
        game->villager->v_text[i] = sfTexture_createFromFile(path[i], NULL);
        if (!game->villager->v_text[i])
            return KO;
    }
    game->villager->v_sp[0] = create_button(game->villager->v_text[0],
        get_resize(window, 0.13, 0.13), get_resize(window, 120, 120));
    game->villager->v_sp[1] = create_button(game->villager->v_text[1],
        get_resize(window, 0.13, 0.13), get_resize(window, 480, 550));
    game->villager->v_sp[2] = create_button(game->villager->v_text[2],
        get_resize(window, 0.13, 0.13), get_resize(window, 640, 255));
    game->villager->v_sp[3] = create_button(game->villager->v_text[3],
        get_resize(window, 0.13, 0.13), get_resize(window, 420, 120));
    if (!game->villager->v_sp[0] || !game->villager->v_sp[1] ||
        !game->villager->v_sp[2] || !game->villager->v_sp[3])
        return KO;
    return OK;
}

int setup_villager(game_t *game, sfRenderWindow *window)
{
    game->villager->v_sp = malloc(sizeof(sfSprite *) * (4 + 1));
    game->villager->v_text = malloc(sizeof(sfTexture *) * (4 + 1));
    if (setup_villager_sp(game, window) == KO)
        return KO;
    return OK;
}
