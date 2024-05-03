/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** selection_charac
*/

#include "my.h"

static char **fill_name(void)
{
    char **descript = malloc(sizeof(char *) * (3 + 1));

    descript[0] = my_strdup
        ("Je suis devenu un puissant aventurier afin de venger mon village.\n\
Je combat maintenant afin de proteger les plus faibles\n \
de la menace des orcs.\n\n\
Vie : 100\n\
Mana :  50\n\
Attaque : 50\n\
Attaque Magique : 50\n\
Defense : 75\n\
\n\
Les Humains sont un choix polyvalent, ils ont une certaine affinite\n\
avec la magie et le combat.");
    descript[1] = my_strdup
        ("Je viens du royaume de Grimbergen. Vivant depuis longtemps\n \ 
sous la montagne, j ai decide de quitter mon royaume afin de\n \
decouvrir le monde et de parfaire mon art.\n\n\
Vie : 100\n\
Mana : 25\n\
Attaque : 75\n\
Attaque Magique : 25\n\
Defense : 100\n\n\
Les nains sont un choix interessant si vous voulez\n \
juste briser des cranes a la seule force de vos bras (DEMACIA).");
    descript[2] = my_strdup
        ("Je viens du royaume de Sapin. Vivant depuis longtemps\n \
au sein de la foret et avec les esprits. J ai decide de quitter\n \
ma foret natale afin d apprendre de nouveaux sortileges.\n\n\
Vie : 100\n\
Mana : 75\n\
Attaque : 25\n\
Attaque Magique : 75\n\
Defense : 50\n\n\
Les elfs sont des maitres dans l art de la magie et sont un \n \
excellent choix si vous souhaitez faire des barbecues d orc.");
    descript[3] = NULL;
    if (!descript)
        return NULL;
    for (int i = 0; i < 3; i += 1) {
        if (!descript[i])
            return NULL;
    }
    return descript;
}

static int setup_description(select_t **select, sfRenderWindow *window)
{
    char **descript = fill_name();

    if (!descript)
        return KO;
    (*select)->text = malloc(sizeof(sfText *) * PLAYER_RACE_SIZE);
    (*select)->font = sfFont_createFromFile(FONT);
    for (int i = 0; descript[i] != NULL; i++) {
        (*select)->text[i] = create_text((*select)->font, descript[i],
            get_less_size(window, 100.0), get_resize(window, 600.0, 50.0));
    }
    return OK;
}

static int setup_arrow(select_t *select, sfRenderWindow *window)
{
    select->arrow_selec_text = sfTexture_createFromFile(ARROW_SELEC, NULL);
    select->arrow_selec = create_button(select->arrow_selec_text,
        get_resize(window, 0.2, 0.2), get_resize(window, 325.0, 200.0));
    if (!select->arrow_selec)
        return KO;
    sfSprite_setRotation(select->arrow_selec, 180.0);
    sfSprite_setOrigin(select->arrow_selec, (sfVector2f){252.0, 257.0});
    return OK;
}

static int setup_button_selec(select_t **select, sfRenderWindow *window)
{
    sfVector2f scales[2] = {get_resize(window, 2, 2),
        get_resize(window, 2, 2)};
    sfVector2f pos[2] = {get_resize(window, 1600.0, 825.0),
        get_resize(window, 250.0, 825.0)};
    sfIntRect rects[2] = {VALID_RECT, BACK_RECT};

    (*select)->button_select_texture =
        sfTexture_createFromFile(BUTTON_SELECT, NULL);
    (*select)->button_select = malloc(sizeof(sfSprite *) * 3);
    (*select)->button_select[2] = NULL;
    for (int i = 0; i < 2; i += 1) {
        (*select)->button_select[i] =
            create_button((*select)->button_select_texture, scales[i], pos[i]);
        if (!(*select)->button_select)
            return KO;
        sfSprite_setTextureRect((*select)->button_select[i], rects[i]);
    }
    return OK;
}

static void init_charac(select_t **select)
{
    (*select)->characters = malloc(sizeof(sfSprite *) * 4);
    (*select)->characters[3] = NULL;
    (*select)->characters_texture = sfTexture_createFromFile(PLAYER, NULL);
}

static int setup_select_characters(select_t **select, sfRenderWindow *window)
{
    sfVector2f scales[3] = {get_resize(window, 2.5, 2.5),
        get_resize(window, 2.5, 2.5), get_resize(window, 2.5, 2.5)};
    sfVector2f pos[3] = {get_resize(window, 450.0, 200.0),
    get_resize(window, 450.0, 450.0), get_resize(window, 450.0, 700.0)};
    sfIntRect rects[3] = {HUMAN_STILL_RECT, DWARF_STILL_RECT, ELF_STILL_RECT};
    sfVector2f origins[3] = {
        {HUMAN_STILL_RECT.width / 2, HUMAN_STILL_RECT.height / 2},
        {DWARF_STILL_RECT.width / 2, DWARF_STILL_RECT.height / 2},
        {ELF_STILL_RECT.width / 2, ELF_STILL_RECT.height / 2}};

    init_charac(select);
    for (int i = 0; i < 3; i++) {
        (*select)->characters[i] = create_button
            ((*select)->characters_texture, scales[i], pos[i]);
        if (!(*select)->characters[i])
            return KO;
        sfSprite_setTextureRect((*select)->characters[i], rects[i]);
        sfSprite_setOrigin((*select)->characters[i], origins[i]);
    }
    return OK;
}

int select_charac(game_t *game, sfRenderWindow *window)
{
    game->select->backboard_texture =
        sfTexture_createFromFile(BACKBOARD, NULL);
    game->select->backboard =
        create_button(game->select->backboard_texture,
        get_resize(window, 3.8, 4.7), get_resize(window, 75.0, 50.0));
    if (!game->select->backboard)
        return KO;
    game->select->player = 0;
    sfSprite_setTextureRect(game->select->backboard, BACKBOARD_RECT);
    if (setup_select_characters(&game->select, window) == KO ||
        setup_button_selec(&game->select, window) == KO ||
        setup_arrow(game->select, window) == KO ||
        setup_description(&game->select, window) == KO)
        return KO;
    return OK;
}
