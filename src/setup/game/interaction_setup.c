/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** interaction_setup
*/

#include "my.h"

static int texture_setup(game_t **game)
{
    (*game)->interaction->texture[0] =
        sfTexture_createFromFile(BULLE_SHOP, NULL);
    (*game)->interaction->field[0] = FORGE;
    (*game)->interaction->texture[1] =
        sfTexture_createFromFile(BULLE_SHOP, NULL);
    (*game)->interaction->field[1] = ALCHEMY;
    (*game)->interaction->texture[2] = NULL;
    if (!(*game)->interaction->texture[0] || !(*game)->interaction->texture[1])
        return KO;
    return OK;
}

static int setup_rect_for_text(sfRectangleShape ***shape, sfVector2f pos)
{
    (*shape) = malloc(sizeof(sfRectangleShape *) * 3);
    if (!(*shape))
        return KO;
    for (int i = 0; i < 2; i++) {
        (*shape)[i] = sfRectangleShape_create();
        sfRectangleShape_setSize((*shape)[i], (sfVector2f){100, 20});
        sfRectangleShape_setPosition(
            (*shape)[i], (sfVector2f){pos.x + 80, pos.y + 30 * (i + 1)});
        sfRectangleShape_setOrigin((*shape)[i], (sfVector2f){100 / 2, 20 / 2});
        sfRectangleShape_setFillColor((*shape)[i], sfTransparent);
    }
    return OK;
}

static int setup_sprite_text(game_t **game, sfRenderWindow *window)
{
    sfVector2f scale[2] = {get_resize(window, 0.8, 1.2),
        get_resize(window, 0.8, 1.2)};
    sfVector2f pos[2] = {get_resize(window, 910, 200),
        get_resize(window, 920, 410)};

    (*game)->interaction->shop = QUITT;
    for (int i = 0; (*game)->interaction->texture[i] != NULL; i++) {
        (*game)->interaction->sprite[i] =
            create_button((*game)->interaction->texture[i], scale[i], pos[i]);
        (*game)->interaction->font = sfFont_createFromFile(FONT);
        (*game)->interaction->text[i] = create_text((*game)->interaction->font,
            "Acheter\nQuitter", get_less_size(window, 50.0),
            (sfVector2f){pos[i].x + 80, pos[i].y + 7.5});
        set_text_mid_origin((*game)->interaction->text[i]);
        if (setup_rect_for_text(&((*game)->interaction->zone_text[i]), pos[i])
            == KO || !(*game)->interaction->sprite[i] ||
            !(*game)->interaction->text[i])
            return KO;
    }
    return OK;
}

int interaction_setup(game_t *game, sfRenderWindow *window)
{
    game->interaction->texture = malloc(sizeof(sfTexture *) * 3);
    game->interaction->sprite = malloc(sizeof(sfSprite *) * 3);
    game->interaction->text = malloc(sizeof(sfText *) * 3);
    game->interaction->field = malloc(sizeof(choice_map_t));
    game->interaction->zone_text = malloc(sizeof(sfRectangleShape **) * 3);
    if (!game->interaction->texture || !game->interaction->sprite ||
        !game->interaction->text || texture_setup(&game) == KO ||
        setup_sprite_text(&game, window) == KO)
        return KO;
    return OK;
}
