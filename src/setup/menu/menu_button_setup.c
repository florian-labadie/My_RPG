/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** menu_button
*/

#include "my.h"

static char **fill_name(void)
{
    char **button_name = malloc(sizeof(char *) * 4);

    button_name[0] = my_strdup(" Jouer");
    button_name[1] = my_strdup("Options");
    button_name[2] = my_strdup("Quitter");
    button_name[3] = NULL;
    if (!button_name)
        return NULL;
    for (int i = 0; i < 3; i += 1) {
        if (!button_name[i])
            return NULL;
    }
    return button_name;
}

static int creation_loop(main_menu_buttons_t **button, char **button_name)
{
    sfVector2f pos = {810.4, 335.25};

    (*button)->font = sfFont_createFromFile(FONT);
    for (int i = 0; i < 3; i += 1) {
        (*button)->sprites[i] = create_button((*button)->rectangle_text,
            (sfVector2f) {0.4, 0.4}, pos);
        if (!(*button)->sprites || !(*button)->sprites[i] ||
        !(*button)->rectangle_text)
            return KO;
        sfSprite_setTextureRect((*button)->sprites[i], BUTTON_RECT);
        (*button)->text[i] = create_text((*button)->font, button_name[i],
        150, (sfVector2f) {pos.x + 50.0, pos.y - 80.0});
        pos = (sfVector2f) {pos.x, pos.y + 200.0};
    }
    return OK;
}

static int set_button(main_menu_buttons_t **button)
{
    char **button_name = fill_name();

    *button = malloc(sizeof(main_menu_buttons_t));
    if (!button_name || !button || !(*button))
        return KO;
    (*button)->font = sfFont_createFromFile(FONT);
    (*button)->sprites = malloc(sizeof(sfSprite *) * 4);
    (*button)->text = malloc(sizeof(sfText *) * 4);
    (*button)->rectangle_text = sfTexture_createFromFile(BUTTON_MENU, NULL);
    if (creation_loop(button, button_name) == KO)
        return KO;
    (*button)->sprites[3] = NULL;
    for (int i = 0; button_name[i] != NULL; i += 1)
        free(button_name[i]);
    free(button_name);
    return OK;
}

int menu_button_setup(main_menu_buttons_t **button)
{
    if (set_button(button) == KO)
        return KO;
    return OK;
}
