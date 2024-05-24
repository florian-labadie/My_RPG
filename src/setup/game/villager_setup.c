/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** villager_setup.c
*/

#include "my.h"

static sfSprite *create_button2(sfTexture *texture, sfVector2f scale,
    sfVector2f pos)
{
    sfSprite *button_sprite = sfSprite_create();

    if (texture == NULL)
        return NULL;
    sfSprite_setTexture(button_sprite, texture, sfFalse);
    sfSprite_setPosition(button_sprite, pos);
    sfSprite_setScale(button_sprite, scale);
    return button_sprite;
}

static int setup_villager_sp(game_t *game, sfRenderWindow *window)
{
    char *path[4] = {RICH_MAN_P, OLD_LADY_P, WOMAN_P, WORKER_P};

    for (int i = 0; i < 4; i++) {
        game->villager->v_text[i] = sfTexture_createFromFile(path[i], NULL);
        if (!game->villager->v_text[i])
            return KO;
    }
    game->villager->v_sp[0] = create_button2(game->villager->v_text[0],
        get_resize(window, 0.13, 0.13), get_resize(window, 120, 120));
    game->villager->v_sp[1] = create_button2(game->villager->v_text[1],
        get_resize(window, 0.13, 0.13), get_resize(window, 450, 600));
    game->villager->v_sp[2] = create_button2(game->villager->v_text[2],
        get_resize(window, 0.13, 0.13), get_resize(window, 640, 255));
    game->villager->v_sp[3] = create_button2(game->villager->v_text[3],
        get_resize(window, 0.13, 0.13), get_resize(window, 420, 120));
    if (!game->villager->v_sp[0] || !game->villager->v_sp[1] ||
        !game->villager->v_sp[2] || !game->villager->v_sp[3])
        return KO;
    return OK;
}

static void set_zone_speak_pnj(game_t *game, int *i)
{
    sfCircleShape_setRadius(game->villager->v_cir[*i], CIRCLE_RADIUS);
    sfCircleShape_setOrigin(game->villager->v_cir[*i], game->villager->set);
        game->villager->sp_b =
    sfSprite_getGlobalBounds(game->villager->v_sp[*i]);
    game->villager->sp_c = (sfVector2f)
        {game->villager->sp_b.left + game->villager->sp_b.width / 2.0f,
        game->villager->sp_b.top + game->villager->sp_b.height / 2.0f};
    sfCircleShape_setPosition
        (game->villager->v_cir[*i], game->villager->sp_c);
    sfCircleShape_setFillColor
        (game->villager->v_cir[*i], game->villager->trans);
    sfCircleShape_setOutlineColor
        (game->villager->v_cir[*i], game->villager->trans);
}

int setup_villager_circle(game_t *game)
{
    game->villager->set = (sfVector2f){CIRCLE_RADIUS, CIRCLE_RADIUS};
    game->villager->trans = sfColor_fromRGBA(255, 255, 255, 0);
    for (int i = 0; i < 4; i++) {
        game->villager->v_cir[i] = sfCircleShape_create();
        if (!game->villager->v_cir[i])
            return KO;
        set_zone_speak_pnj(game, &i);
    }
    return OK;
}

void create_bubble_texts(villager_t *villager, sfRenderWindow *window)
{
    sfFont *font = sfFont_createFromFile(GAMERIA_FONT);
    char *texts[4] = {
        "TANT DE MORTS",
        "ALLER VITE AU LAC",
        "ALLER COMBATTRE \n LES ORCS HERO",
        "ENCORE CES ORCS"
    };

    for (int i = 0; i < 4; i++) {
        villager->bubble_texts[i] =
        create_text(font, texts[i], get_less_size(window, 7),
        get_resize(window, sfSprite_getPosition(villager->bubble_spr[i]).x,
        sfSprite_getPosition(villager->bubble_spr[i]).y + 50));
    }
}

void set_bubble_text_positions(villager_t *villager, sfRenderWindow *window)
{
    sfVector2f offset[4] = {
        {15, 15},
        {10, 50},
        {15, 25},
        {15, 15}
    };

    for (int i = 0; i < 4; i++) {
        sfText_setPosition(villager->bubble_texts[i], get_resize(window,
        sfSprite_getPosition(villager->bubble_spr[i]).x + offset[i].x,
        sfSprite_getPosition(villager->bubble_spr[i]).y + offset[i].y));
    }
}

void set_bubble_texts(villager_t *villager, sfRenderWindow *window)
{
    create_bubble_texts(villager, window);
    set_bubble_text_positions(villager, window);
}

static int setup_chat(game_t *game, sfRenderWindow *window)
{
    sfIntRect bubble_rect = {0, 202, 204, 202};

    game->villager->bubble_text = sfTexture_createFromFile(BULLE_SHOP, NULL);
    if (!game->villager->bubble_text)
        return KO;
    for (int i = 0; i < 4; i += 1) {
        game->villager->bubble_spr[i] =
        create_button(game->villager->bubble_text, (sfVector2f) {0.5, 0.5},
        get_resize(window, sfSprite_getPosition(game->villager->v_sp[i]).x +10,
        sfSprite_getPosition(game->villager->v_sp[i]).y - 30));
        sfSprite_setTextureRect(game->villager->v_sp[i], bubble_rect);
    }
    sfSprite_setPosition(game->villager->bubble_spr[1],
        get_resize(window, sfSprite_getPosition(game->villager->v_sp[1]).x,
        sfSprite_getPosition(game->villager->v_sp[1]).y));
    set_bubble_texts(game->villager, window);
    return OK;
}

int setup_villager(game_t *game, sfRenderWindow *window)
{
    game->villager->v_sp = malloc(sizeof(sfSprite *) * (4 + 1));
    game->villager->v_text = malloc(sizeof(sfTexture *) * (4 + 1));
    game->villager->v_cir = malloc(sizeof(sfCircleShape *) * (4 + 1));
    game->villager->bubble_spr = malloc(sizeof(sfSprite *) * 5);
    game->villager->bubble_texts = malloc(4 * sizeof(sfText *));
    if (!game->villager->bubble_texts)
        return KO;
    if (setup_villager_sp(game, window) == KO ||
        setup_villager_circle(game) == KO ||
        setup_chat(game, window) == KO)
        return KO;
    return OK;
}
