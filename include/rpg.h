/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** rpg
*/

#ifndef RPG_H_
    #define RPG_H_

    #include "game_include/game.h"
    #include "menu_include/menu.h"
    #include "map.h"

typedef enum screen_s {
    MAIN_MENU,
    GAME,
    SCREEN_STATES_SIZE
} screen_t;

typedef struct rpg_s {
    sfRenderWindow *window;
    screen_t screen;

    sfVector2u window_size;
    game_t *game;
    menu_t *menu;
    map_t *map;
} rpg_t;

#endif /* !RPG_H_ */
