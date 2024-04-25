/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** setting
*/

#ifndef SETTING_H_
    #define SETTING_H_

    #include <stdbool.h>
    #define FILE_SETTING "src/save/GameSetting.txt"
    #define SETTING_STR "[SETTINGS]"
    #define SAVE_STR "[SAVE]"

typedef enum status_s {
    SETTINGS,
    SAVE
} status_t;

typedef struct setting_s {
    sfVector2f size_screen;
    bool screen_mode;
    float fps;
    float sound_game;
    status_t *status;
} setting_t;

#endif /* !SETTING_H_ */
