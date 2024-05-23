/*
** EPITECH PROJECT, 2024
** help_menu.h
** File description:
** HELP_MENU_H
*/

#ifndef HELP_MENU_H
    #define HELP_MENU_H

    #include <SFML/Graphics.h>
    #include "my.h"

typedef struct help_menu_s {
    sfText *text;
    sfFont *font;
    sfTexture *backboard_texture;
    sfSprite *backboard_sprite;
} help_menu_t;

#endif /* !HELP_MENU_H */
