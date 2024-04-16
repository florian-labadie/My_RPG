/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** rpg
*/

#ifndef RPG_H_
#define RPG_H_

    #include "player.h"
    #include "menu.h"
    #include "map.h"

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>

typedef enum screen_s {
    MAIN_MENU,
    HELP_MENU,
    SETTINGS,
    GAME,
    PAUSE_MENU,
    INVENTORY
} screen_t;

typedef struct rpg_s {
    sfWindow *window;
    screen_t screen;

    player_t *player;
    menu_t *menu;
    map_t *map;
} rpg_t;

#endif /* !RPG_H_ */
