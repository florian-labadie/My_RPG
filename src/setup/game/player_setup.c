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

static int set_player_sprites(player_t *player, sfRenderWindow *window)
{
    sfIntRect rects[3] = {HUMAN_STILL_RECT, DWARF_STILL_RECT, ELF_STILL_RECT};
    sfVector2f origins[3] = {
        {HUMAN_STILL_RECT.width / 2, HUMAN_STILL_RECT.height / 2},
        {DWARF_STILL_RECT.width / 2, DWARF_STILL_RECT.height / 2},
        {ELF_STILL_RECT.width / 2, ELF_STILL_RECT.height / 2}};

    player->sprites->player_text = sfTexture_createFromFile(PLAYER, NULL);
    player->sprites->player_clock = sfClock_create();
    player->sprites->attack_clock = sfClock_create();
    player->sprites->move_clock = sfClock_create();
    player->attack = false;
    player->position = get_resize(window, 170, 660);
    player->sprites->player_rect = rects[player->race];
    if (!player->sprites->player_text)
        return KO;
    player->sprites->player = create_button(player->sprites->player_text,
        (sfVector2f){0.5, 0.5}, player->position);
    sfSprite_setTextureRect(player->sprites->player, rects[player->race]);
    sfSprite_setOrigin(player->sprites->player, origins[player->race]);
    return OK;
}

static int player_sprites_setup(sfRenderWindow *window, player_t *player)
{
    set_player_sprites(player, window);
    player->sprites->range = sfCircleShape_create();
    sfCircleShape_setRadius(player->sprites->range, 130);
    sfCircleShape_setOrigin(player->sprites->range, (sfVector2f){130, 130});
    player->sprites->hitbox = sfCircleShape_create();
    sfCircleShape_setRadius(player->sprites->hitbox, 80);
    sfCircleShape_setOrigin(player->sprites->hitbox, (sfVector2f){80, 80});
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
    player->is_alive = true;
    return OK;
}

static int life_setup(player_t *player)
{
    player->life = malloc(sizeof(life_player_t));
    player->life->rects = malloc(sizeof(sfRectangleShape *) * 3);
    player->life->rects[2] = NULL;
    player->life->health_bar_text = sfTexture_createFromFile(HEALTH_BAR, NULL);
    if (!player->life->health_bar_text)
        return KO;
    player->life->health_bar_spr = create_button(player->life->health_bar_text,
    (sfVector2f) {0.5, 0.5}, (sfVector2f) {28.0, 15.0});
    for (int i = 0; i < 2; i++) {
        player->life->rects[i] = sfRectangleShape_create();
        sfRectangleShape_setSize(player->life->rects[i],
            (sfVector2f){227.0, 21.0});
        sfRectangleShape_setPosition(player->life->rects[i], (sfVector2f)
            {75.0, 52.0});
    }
    sfRectangleShape_setFillColor(player->life->rects[0],
        sfColor_fromRGB(207, 207, 207));
    sfRectangleShape_setFillColor(player->life->rects[1],
        sfColor_fromRGB(209, 61, 61));
    return OK;
}

static int setup_death(sfRenderWindow *window, player_t *player)
{
    player->life->loos_rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(player->life->loos_rect,
    (sfVector2f) {0.0, 0.0});
    sfRectangleShape_setSize(player->life->loos_rect, (sfVector2f)
    {1920.0, 1080});
    sfRectangleShape_setFillColor(player->life->loos_rect,
    sfColor_fromRGBA(100, 100, 100, 200));
    player->life->lose_text = sfTexture_createFromFile(DEAFEAT, NULL);
    player->life->lose_spr = create_button(player->life->lose_text,
    (sfVector2f) {1.0, 1.0}, get_resize(window, 550.0, 250.0));
    player->life->time_lose = sfClock_create();
    return OK;
}

int player_setup(sfRenderWindow *window, player_t *player)
{
    if (player_sprites_setup(window, player) == KO || life_setup(player) == KO
    || setup_level(player, window) == KO || setup_death(window, player) == KO)
        return KO;
    player_stats_setup(player);
    return OK;
}
