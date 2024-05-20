/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** rpg
*/

#ifndef RPG_H_
    #define RPG_H_

    #include "enum.h"

    #include "setting.h"
    #include "menu_include/menu.h"
    #include "game_include/game.h"

typedef enum screen_s {
    MAIN_MENU,
    GAME,
    END,
    SCREEN_STATES_SIZE
} screen_t;

typedef struct rpg_s {
    sfRenderWindow *window;
    screen_t screen;

    sfVector2u window_size;
    stock_setting_t *setting;
    menu_t *menu;
    game_t *game;
} rpg_t;

#endif /* !RPG_H_ */
