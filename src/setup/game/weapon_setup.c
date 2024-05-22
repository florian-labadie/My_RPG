/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** weapon_setup
*/

#include "my.h"

static void setup_text_weapon(weapon_t **weapon, sfRenderWindow *window)
{
    sfVector2f pos[3] = {get_resize(window, 1250.0, 180.0),
        get_resize(window, 1250.0, 270.0), get_resize(window, 1250.0, 360.0)};
    char *text[3] = {"Normal", "Epique", "Legendaire"};

    for (int j = 0; j < 3; j += 1) {
        (*weapon)->text[j] = create_text((*weapon)->font, text[j],
            get_less_size(window, 70.0),
            (sfVector2f){pos[j].x, pos[j].y});
        set_text_mid_origin((*weapon)->text[j]);
        (*weapon)->zone_text[j] = sfRectangleShape_create();
        sfRectangleShape_setSize((*weapon)->zone_text[j],
            (sfVector2f){150, 40});
        sfRectangleShape_setPosition(
            (*weapon)->zone_text[j], (sfVector2f){pos[j].x, pos[j].y + 50});
        sfRectangleShape_setOrigin((*weapon)->zone_text[j],
            (sfVector2f){150 / 2, 40 / 2});
        sfRectangleShape_setFillColor((*weapon)->zone_text[j], sfRed);
    }
}

static void setup_sprite(shop_t **shop, sfRenderWindow *window)
{
    sfVector2f scales[3] = {get_resize(window, 2.5, 2.5),
        get_resize(window, 0.17, 0.159), get_resize(window, 7.6, 4.8)};
    sfVector2f pos[3] = {get_resize(window, 1050.0, 180.0),
        get_resize(window, 1050.0, 180.0), get_resize(window, 1050.0, 180.0)};

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
    setup_sprite(shop, window);
    return OK;
}

static int setup_sign(shop_t **shop, sfRenderWindow *window)
{
    sfVector2f scales[2] = {get_resize(window, 2.5, 2.9),
        get_resize(window, 2.6, 2.5)};
    sfVector2f pos[2] = {get_resize(window, 900.0, -250.0),
        get_resize(window, 950.0, -150.0)};

    (*shop)->texture_sign = sfTexture_createFromFile(WEAP_SIGN, NULL);
    if (!(*shop)->texture_sign)
        return KO;
    for (int i = 0; i < 2; i += 1) {
        (*shop)->sprite_sign[i] =
            create_button((*shop)->texture_sign, scales[i], pos[i]);
    }
    return OK;
}

int shop_buy_setup(game_t *game, sfRenderWindow *window)
{
    game->shop->sprite_sign = malloc(sizeof(sfSprite *) * 2);
    if (!game->shop->sprite_sign)
        return KO;
    if (weapon_setup(&game->shop, window) == KO ||
        setup_sign(&game->shop, window) == KO)
        return KO;
    return OK;
}
