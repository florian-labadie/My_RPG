/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** draw_game
*/

#include "my.h"

static void draw_pause_menu(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_drawRectangleShape(window, game->pause->background, NULL);
}

static void draw_story_game(sfRenderWindow *window, game_t *game)
{
    draw_particles(game, window);
    draw_flag(game, window);
    change_view(game, window);
}

static void draw_village(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_drawSprite(window,
        game->map->sprite_ground, NULL);
    sfRenderWindow_drawSprite(window,
        game->player->sprites->player, NULL);
    sfRenderWindow_drawSprite(window,
        game->map->sprite_obj, NULL);
}

static void draw_battlefield(sfRenderWindow *window, game_t *game)
{
}

static void draw_select_charac(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_clear(window, sfColor_fromRGB(0, 90, 0));
    sfRenderWindow_drawSprite(window, game->select->backboard, NULL);
    for (int i = 0; game->select->characters[i] != NULL; i += 1)
        sfRenderWindow_drawSprite(window, game->select->characters[i], NULL);
    for (int i = 0; game->select->button_select[i] != NULL; i += 1)
        sfRenderWindow_drawSprite
            (window, game->select->button_select[i], NULL);
    sfRenderWindow_drawText
        (window, game->select->text[game->select->player], NULL);
    sfRenderWindow_drawSprite(window, game->select->arrow_selec, NULL);
}

void draw_game(rpg_t *rpg)
{
    void (*draw_game_fct[])(sfRenderWindow *, game_t *) =
        {draw_select_charac, draw_story_game};
    void (*draw_map_function[])(sfRenderWindow *, game_t *) =
        {draw_village, draw_battlefield};

    if (rpg->game->screen >= LOAD_GAME) {
        draw_map_function[rpg->game->map->choice_map](rpg->window, rpg->game);
    }
    if (rpg->game->screen != PAUSE)
        draw_game_fct[rpg->game->screen](rpg->window, rpg->game);
    else
        draw_pause_menu(rpg->window, rpg->game);
    return;
}
