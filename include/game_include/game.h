/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_

    #include "player.h"
    #include "villager.h"
    #include "pause.h"
    #include "inventory.h"
    #include "selection.h"
    #include "map.h"
    #include "interaction.h"
    #include "weapon.h"
    #define BULLE_SHOP "assets/sprite/bulle.png"

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
    sfView *original_view;

    select_t *select;
    map_t *map;
    player_t *player;
    villager_t *villager;
    inventory_t *inventory;
    pause_t *pause;
    interaction_t *interaction;
    shop_t *shop;
} game_t;

#endif /* !GAME_H_ */
