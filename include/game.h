/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_

    #include "player.h"

typedef enum game_state_s {
    PLAYING,
    PAUSE,
    INVENTORY,
    GAME_STATE_SIZE
} game_state_t;

typedef struct game_s {
    game_state_t screen;

    player_t *player;
} game_t;

#endif /* !GAME_H_ */
