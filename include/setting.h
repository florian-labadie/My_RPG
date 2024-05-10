/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** setting
*/

#ifndef SETTING_H_
    #define SETTING_H_

    #include <SFML/Graphics.h>

    #include <stdbool.h>

    #define FILE_SETTING "Data/setting/GameSetting.txt"
    #define SETTING_STR "[SETTINGS]"
    #define SAVE_STR "[SAVE]"

typedef struct stock_setting_s {
    sfVector2f size_screen;

    bool screen_mode;
    float fps;
    float sound_game;
    char *language;
} stock_setting_t;

#endif /* !SETTING_H_ */
