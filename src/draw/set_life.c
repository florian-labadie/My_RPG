/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** draw_game
*/

#include "my.h"

static void life_manager(sfRenderWindow *window, game_t *game, int size,
    int size2)
{
    float life = (game->player->stats.health * size) / 100;

    sfRectangleShape_setSize(game->player->life->red, (sfVector2f)
    {life, size2});
}

void set_life_village(game_t *game, sfRenderWindow *window)
{
    sfRectangleShape_setSize(game->player->life->red, (sfVector2f) {67, 7});
    sfRectangleShape_setPosition(game->player->life->red, (sfVector2f)
    {sfView_getCenter(game->map->view).x - 185,
    sfView_getCenter(game->map->view).y - 84});
    sfRectangleShape_setSize(game->player->life->back, (sfVector2f) {67, 7});
    sfRectangleShape_setPosition(game->player->life->back, (sfVector2f)
    {sfView_getCenter(game->map->view).x - 185,
    sfView_getCenter(game->map->view).y - 84});
    sfSprite_setScale(game->player->life->health_bar_spr, (sfVector2f)
    {0.15, 0.15});
    sfRenderWindow_drawRectangleShape(window, game->player->life->back, NULL);
    life_manager(window, game, 67, 7);
    sfRenderWindow_drawRectangleShape(window, game->player->life->red, NULL);
    sfSprite_setPosition(game->player->life->health_bar_spr, (sfVector2f)
    {sfView_getCenter(game->map->view).x - 200,
    sfView_getCenter(game->map->view).y - 95});
    sfRenderWindow_drawSprite(window, game->player->life->health_bar_spr,
    NULL);
}

void set_life_battle(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_drawRectangleShape(window, game->player->life->back, NULL);
    sfRectangleShape_setSize(game->player->life->red, (sfVector2f)
    {227.0, 21.0});
    sfRectangleShape_setSize(game->player->life->back, (sfVector2f)
    {245.0, 21.0});
    sfRectangleShape_setPosition(game->player->life->back, (sfVector2f)
    {57.0, 52.0});
    sfRectangleShape_setPosition(game->player->life->red, (sfVector2f)
    {75.0, 52.0});
    life_manager(window, game, 227, 21);
    sfSprite_setScale(game->player->life->health_bar_spr, (sfVector2f)
    {0.5, 0.5});
    sfSprite_setPosition(game->player->life->health_bar_spr, (sfVector2f)
    {28.0, 15.0});
    sfRenderWindow_drawRectangleShape(window, game->player->life->red, NULL);
    sfRenderWindow_drawSprite(window, game->player->life->health_bar_spr,
    NULL);
}
