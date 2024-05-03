/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** create_text
*/

#include "my.h"

sfText *create_text(sfFont *font, char *sentence, int size, sfVector2f pos)
{
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setString(text, sentence);
    sfText_setFillColor(text, sfBlack);
    sfText_setPosition(text, pos);
    return text;
}
