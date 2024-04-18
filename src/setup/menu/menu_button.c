/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** menu_button
*/

#include "my.h"

static char **fill_name(char **button_name)
{
    button_name = malloc(sizeof(char *) * 4);
    if (!button_name)
        return NULL;
    button_name[0] = my_strdup(" Jouer");
    button_name[1] = my_strdup("Options");
    button_name[2] = my_strdup("Quitter");
    button_name[3] = NULL;
    for (int i = 0; i < 3; i += 1) {
        if (!button_name[i])
            return NULL;
    }
    return button_name;
}

static int creation_loop(button_t *button)
{
    sfVector2f pos = {815.0, 165.25};

    for (int i = 0; i < 3; i += 1) {
        if (button->play_sprite != NULL)
            button->play_sprite[i] = create_button(button->rectangle_text,
            (sfVector2f) {0.4, 0.4}, pos);
        if (!button->play_sprite[i] || !button->play_sprite ||
        !button->rectangle_text)
            return KO;
        sfSprite_setTextureRect(button->play_sprite[i], RECTANGLE_RECT);
        button->text[i] = create_text(button->font, button->button_name[i],
        150, (sfVector2f) {pos.x + 50.0, pos.y - 80.0});
        pos = (sfVector2f) {pos.x, pos.y + 250.0};
    }
    return OK;
}

static int set_button(button_t *button)
{
    button->font = sfFont_createFromFile(FONT);
    button->play_sprite = malloc(sizeof(sfSprite *) * 4);
    button->text = malloc(sizeof(sfText *) * 4);
    button->rectangle_text = sfTexture_createFromFile(BUTTON_MENU, NULL);
    button->button_name = fill_name(button->button_name);
    if (!button->button_name)
        return 84;
    button->button_name[3] = NULL;
    if (creation_loop(button) == KO)
        return 84;
    button->play_sprite[3] = NULL;
    for (int i = 0; button->button_name[i] != NULL; i += 1) {
        free(button->button_name[i]);
    }
    return OK;
}

int menu_button_setup(button_t *button)
{
    if (set_button(button) == KO)
        return KO;
    return OK;
}
