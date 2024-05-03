/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** selection
*/

#ifndef SELECTION_H_
    #define SELECTION_H_

    #include <SFML/Graphics.h>
    #define PLAYER "assets/sprite/main_character.png"
    #define BACKBOARD "assets/button/wood-plank.png"
    #define BUTTON_SELECT "assets/button/wood_button.png"
    #define ARROW_SELEC "assets/button/arrow_selec.png"
    #define BACKBOARD_RECT ((sfIntRect){0, 0, 469, 200})
    #define HUMAN_STILL_RECT ((sfIntRect){0, 0, 52, 56})
    #define DWARF_STILL_RECT ((sfIntRect){0, 110, 52, 60})
    #define ELF_STILL_RECT ((sfIntRect){0, 228, 52, 62})
    #define VALID_RECT ((sfIntRect){227, 272, 43, 41})
    #define BACK_RECT ((sfIntRect){284, 216, 43, 41})

typedef struct select_s {
    sfText **text;
    sfFont *font;

    player_race_t player;

    sfTexture *arrow_selec_text;
    sfSprite *arrow_selec;

    sfTexture *backboard_texture;
    sfSprite *backboard;

    sfTexture *button_select_texture;
    sfSprite **button_select;

    sfTexture *characters_texture;
    sfSprite **characters;
} select_t;


#endif /* !SELECTION_H_ */
