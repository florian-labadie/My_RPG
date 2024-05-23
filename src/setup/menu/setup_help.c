/*
** EPITECH PROJECT, 2024
** setup_help.c
** File description:
** setup
*/

#include "my.h"

void create_help_text(sfRenderWindow *window, menu_t *menu)
{
    sfVector2f text_pos;

    menu->help_menu->font = sfFont_createFromFile("assets/parallax/sewer.ttf");
    text_pos.x = 1920 / 2.8;
    text_pos.y = 1080 / 2.9;
    menu->help_menu->text = create_text(menu->help_menu->font,
    "Bienvenu dans le menu d'Aide", 35, text_pos);
}

void setup_help_menu(sfRenderWindow *window, menu_t *menu)
{
    sfTexture *backboard_texture = sfTexture_createFromFile(BACKBOARD, NULL);
    sfSprite *backboard_sprite = sfSprite_create();

    create_help_text(window, menu);
    sfSprite_setTexture(backboard_sprite, backboard_texture, sfTrue);
    sfSprite_setTextureRect(backboard_sprite, BACKBOARD_RECT);
    sfSprite_setPosition(backboard_sprite, (sfVector2f){300, 350});
    sfSprite_setScale(backboard_sprite, (sfVector2f){3.0f, 2.5f});
    sfRenderWindow_drawSprite(window, backboard_sprite, NULL);
}
