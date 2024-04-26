/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** option_button.c
*/

#include "my.h"

int if_click_option(rpg_t *rpg)
{
    sfFloatRect local_bounds = sfSprite_getLocalBounds();
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->settings->open_book_spr, NULL);
    display_book(rpg->menu->settings);
}
