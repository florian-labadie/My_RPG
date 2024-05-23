/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** weapon_setup
*/

#include "my.h"

static void setup_text_weapon(weapon_t **weapon, sfRenderWindow *window)
{
    sfVector2f pos[3] = {get_resize(window, 1260.0, 180.0),
        get_resize(window, 1260.0, 270.0), get_resize(window, 1260.0, 360.0)};
    sfVector2f rect_size[3] = {get_resize(window, 200.0, 40.0),
        get_resize(window, 225.0, 40.0), get_resize(window, 250.0, 40.0)};
    char *text[3] = {"Normal  50 PO", "Epique  200 PO", "Legendaire  500 PO"};

    for (int j = 0; j < 3; j += 1) {
        (*weapon)->text[j] = create_text((*weapon)->font, text[j],
            get_less_size(window, 70.0),
            (sfVector2f){pos[j].x, pos[j].y});
        set_text_mid_origin((*weapon)->text[j]);
        (*weapon)->zone_text[j] = sfRectangleShape_create();
        sfRectangleShape_setSize((*weapon)->zone_text[j],
            rect_size[j]);
        sfRectangleShape_setPosition((*weapon)->zone_text[j],
            (sfVector2f){pos[j].x, pos[j].y + get_resize(window, 0, 50.0).y});
        sfRectangleShape_setOrigin((*weapon)->zone_text[j],
            (sfVector2f){rect_size[j].x / 2, 40 / 2});
        sfRectangleShape_setFillColor((*weapon)->zone_text[j], sfTransparent);
    }
}

static void setup_sprite_weapon(shop_t **shop, sfRenderWindow *window)
{
    sfVector2f scales[3] = {get_resize(window, 2.5, 2.5),
        get_resize(window, 0.17, 0.159), get_resize(window, 7.6, 4.8)};
    sfVector2f pos[3] = {get_resize(window, 1040.0, 180.0),
        get_resize(window, 1040.0, 180.0), get_resize(window, 1040.0, 180.0)};

    for (int i = 0; i < 3; i += 1) {
        (*shop)->weapon[i]->sprite_weap =
            create_button((*shop)->weapon[i]->texture_weap, scales[i], pos[i]);
        (*shop)->weapon[i]->font = sfFont_createFromFile(FONT);
        setup_text_weapon(&((*shop)->weapon[i]), window);
    }
}

static int weapon_setup(shop_t **shop, sfRenderWindow *window)
{
    for (int i = 0; i < 3; i += 1) {
        (*shop)->weapon[i] = malloc(sizeof(weapon_t));
        if (!(*shop)->weapon[i])
            return KO;
    }
    (*shop)->weapon[0]->texture_weap = sfTexture_createFromFile(GANTS, NULL);
    (*shop)->weapon[1]->texture_weap = sfTexture_createFromFile(SWORD, NULL);
    (*shop)->weapon[2]->texture_weap =
        sfTexture_createFromFile(MAGIC_STAFF, NULL);
    if (!(*shop)->weapon[0]->texture_weap || !(*shop)->weapon[1]->texture_weap
        || !(*shop)->weapon[2]->texture_weap)
        return KO;
    for (int i = 0; i < 3; i += 1) {
        (*shop)->weapon[i]->text = malloc(sizeof(sfText *) * 4);
        (*shop)->weapon[i]->zone_text = malloc(sizeof(sfRectangleShape *) * 4);
    }
    setup_sprite_weapon(shop, window);
    return OK;
}

static void setup_text_potion(potion_t **potion, sfRenderWindow *window)
{
    sfVector2f pos[2] = {get_resize(window, 1320.0, 140.0),
        get_resize(window, 1320.0, 255.0)};
    char *text[2] = {"Potion de soin  50 PO", "Potion de mana  50 PO"};

    for (int j = 0; j < 2; j += 1) {
        (*potion)->text[j] = create_text((*potion)->font, text[j],
            get_less_size(window, 70.0), (sfVector2f){pos[j].x, pos[j].y});
        set_text_mid_origin((*potion)->text[j]);
        (*potion)->zone_text[j] = sfRectangleShape_create();
        sfRectangleShape_setSize((*potion)->zone_text[j],
            (sfVector2f){280, 40});
        sfRectangleShape_setPosition((*potion)->zone_text[j],
            (sfVector2f){pos[j].x, pos[j].y + get_resize(window, 0, 50.0).y});
        sfRectangleShape_setOrigin((*potion)->zone_text[j],
            (sfVector2f){280 / 2, 40 / 2});
        sfRectangleShape_setFillColor((*potion)->zone_text[j], sfTransparent);
    }
}

static int setup_sprite_potion(shop_t **shop, sfRenderWindow *window)
{
    (*shop)->potion->sprite =
        create_button((*shop)->potion->texture_pot, (sfVector2f){0.3, 0.3},
        (sfVector2f){1100, 140});
    (*shop)->potion->font = sfFont_createFromFile(FONT);
    if (!(*shop)->potion->sprite || !(*shop)->potion->font)
        return KO;
    setup_text_potion(&((*shop)->potion), window);
    return OK;
}

static int potion_setup(shop_t **shop, sfRenderWindow *window)
{
    (*shop)->potion->texture_pot = sfTexture_createFromFile(POTION, NULL);
    if (!(*shop)->potion->texture_pot)
        return KO;
    (*shop)->potion->text = malloc(sizeof(sfText *) * 3);
    (*shop)->potion->zone_text = malloc(sizeof(sfRectangleShape *) * 3);
    setup_sprite_potion(shop, window);
    return OK;
}

static void setup_sign_sprite(shop_t **shop, sfRenderWindow *window)
{
    sfVector2f scales[2] = {get_resize(window, 2.5, 2.9),
        get_resize(window, 2.6, 2.5)};
    sfVector2f pos[2] = {get_resize(window, 900.0, -250.0),
        get_resize(window, 950.0, -250.0)};
    sfVector2f scales_quit[2] = {get_resize(window, 0.9, 0.9),
        get_resize(window, 0.9, 0.9)};
    sfVector2f pos_quit[2] = {get_resize(window, 1370.0, 190.0),
        get_resize(window, 1440.0, 130.0)};

    for (int i = 0; i < 2; i += 1) {
        (*shop)->sprite_sign[i] =
            create_button((*shop)->texture_sign, scales[i], pos[i]);
        (*shop)->sprite_quitt[i] =
            create_button((*shop)->texture_quitt, scales_quit[i], pos_quit[i]);
        sfSprite_setTextureRect((*shop)->sprite_quitt[i], BACK_RECT);
    }
}

static int setup_sign(shop_t **shop, sfRenderWindow *window)
{
    (*shop)->texture_quitt = sfTexture_createFromFile(BUTTON_PANEL, NULL);
    (*shop)->texture_sign = sfTexture_createFromFile(WEAP_SIGN, NULL);
    if (!(*shop)->texture_sign || !(*shop)->texture_quitt)
        return KO;
    setup_sign_sprite(shop, window);
    return OK;
}

int shop_buy_setup(game_t *game, sfRenderWindow *window)
{
    game->shop->sprite_sign = malloc(sizeof(sfSprite *) * 2);
    game->shop->sprite_quitt = malloc(sizeof(sfSprite *) * 2);
    if (!game->shop->sprite_sign || !game->shop->sprite_quitt)
        return KO;
    if (weapon_setup(&game->shop, window) == KO ||
        setup_sign(&game->shop, window) == KO ||
        potion_setup(&game->shop, window) == KO)
        return KO;
    return OK;
}
