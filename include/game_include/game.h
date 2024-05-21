/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_

    #include "player.h"
    #include "pause.h"
    #include "inventory.h"
    #include "selection.h"
    #include "map.h"

typedef enum game_state_s {
    SELECTION,
    PLAYING,
    PAUSE,
    INVENTORY,
    GAME_STATE_SIZE
} game_state_t;

typedef struct game_s {
    game_state_t screen;

    sfVector2f player_move;

    select_t *select;
    map_t *map;
    player_t *player;
    inventory_t *inventory;
    pause_t *pause;
} game_t;

#endif /* !GAME_H_ */
