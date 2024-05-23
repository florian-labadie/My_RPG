/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** player_setup
*/

#include "my.h"

static void player_stats_setup(player_t *player)
{
    float stats[PLAYER_RACE_SIZE][5] = {{100.0, 50.0, 50.0, 50.0, 75.0},
                                        {100.0, 25.0, 75.0, 25.0, 100.0},
                                        {100.0, 75.0, 25.0, 75.0, 50.0}};

    player->stats.health = stats[player->race][0];
    player->stats.mana = stats[player->race][1];
    player->stats.attack = stats[player->race][2];
    player->stats.magic_attack = stats[player->race][3];
    player->stats.defense = stats[player->race][4];
}

static int player_sprites_setup(sfRenderWindow *window, player_t *player)
{
    sfIntRect rects[3] = {HUMAN_STILL_RECT, DWARF_STILL_RECT, ELF_STILL_RECT};
    sfVector2f origins[3] = {
        {HUMAN_STILL_RECT.width / 2, HUMAN_STILL_RECT.height / 2},
        {DWARF_STILL_RECT.width / 2, DWARF_STILL_RECT.height / 2},
        {ELF_STILL_RECT.width / 2, ELF_STILL_RECT.height / 2}};

    player->sprites->player_text = sfTexture_createFromFile(PLAYER, NULL);
    player->sprites->player_clock = sfClock_create();
    player->sprites->move_clock = sfClock_create();
    player->sprites->player_rect = rects[player->race];
    player->attack = false;
    player->position = (sfVector2f){170, 660};
    if (!player->sprites->player_text)
        return KO;
    player->sprites->player = create_button(player->sprites->player_text,
        (sfVector2f){0.5, 0.5}, player->position);
    sfSprite_setTextureRect(player->sprites->player, rects[player->race]);
    sfSprite_setOrigin(player->sprites->player, origins[player->race]);
    return OK;
}

static int setup_level(player_t *player, sfRenderWindow *window)
{
    sfFont *level_font = sfFont_createFromFile(TITLE_FONT);

    if (!level_font)
        return KO;
    player->stats.level = 1;
    player->stats.nb_gold = 0;
    player->stats.xp = 0;
    player->stats.level_text =
    create_text(level_font, int_to_str(player->stats.level),
    get_less_size(window, 35), get_resize(window, 68, 47.0));
    set_text_mid_origin(player->stats.level_text);
    return OK;
}

static int life_setup(player_t *player)
{
    player->life = malloc(sizeof(life_player_t));
    player->life->health_bar_text = sfTexture_createFromFile(HEALTH_BAR, NULL);
    if (!player->life->health_bar_text)
        return KO;
    player->life->health_bar_spr = create_button(player->life->health_bar_text,
    (sfVector2f) {0.5, 0.5}, (sfVector2f) {-20.0, -200.0});
    player->life->back = sfRectangleShape_create();
    player->life->red = sfRectangleShape_create();
    sfRectangleShape_setSize(player->life->red, (sfVector2f) {227.0, 21.0});
    sfRectangleShape_setSize(player->life->back, (sfVector2f) {245.0, 21.0});
    sfRectangleShape_setPosition(player->life->back, (sfVector2f)
    {57.0, 52.0});
    sfRectangleShape_setPosition(player->life->red, (sfVector2f) {75.0, 52.0});
    sfRectangleShape_setFillColor(player->life->back,
    sfColor_fromRGB(207, 207, 207));
    sfRectangleShape_setFillColor(player->life->red,
    sfColor_fromRGB(209, 61, 61));
    return OK;
}

int player_setup(sfRenderWindow *window, player_t *player)
{
    if (player_sprites_setup(window, player) == KO || life_setup(player) == KO
    || setup_level(player, window) == KO)
        return KO;
    player_stats_setup(player);
    return OK;
}
