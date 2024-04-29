/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** enum
*/

#ifndef ENUM_H_
    #define ENUM_H_

typedef enum player_race_s {
    HUMAN,
    DWARF,
    ELF,
    PLAYER_RACE_SIZE
} player_race_t;

typedef enum key_status_s {
    NOT_PRESSED,
    KEY_PRESSED,
    KEY_STATUS_SIZE
} key_status_t;

typedef enum button_state_s {
    NORMAL,
    HOVER,
    BUTTON_PRESSED,
    BUTTON_STATE_SIZE
} button_state_t;

#endif /* !ENUM_H_ */
