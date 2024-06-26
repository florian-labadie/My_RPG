/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** save_game
*/

#include "my.h"

static void setting_by_default(stock_setting_t *setting)
{
    if (setting->size_screen.x < 0 || setting->size_screen.y < 0)
        setting->size_screen = (sfVector2f){1920.0, 1080.0};
    if (setting->fps < 0)
        setting->fps = 60.0;
    if (setting->screen_mode != false && setting->screen_mode != true)
        setting->screen_mode = true;
    if (setting->sound_game < 0)
        setting->sound_game = 50.0;
    if (!setting->language || my_strcmp(setting->language, "FR") == OK)
        setting->language = my_strdup("FR");
}

static char *check_is_value(void)
{
    char *value = my_strtok(NULL, "\n");

    if (!value)
        return "-1";
    return value;
}

static int set_settings_menu(stock_setting_t *setting, char *line)
{
    char *param = NULL;

    if (!line)
        return KO;
    param = my_strtok(line, " =");
    if (!param)
        return KO;
    if (strcmp(param, "Sizescreen.x") == 0)
        setting->size_screen.x = atof(check_is_value());
    if (strcmp(param, "Sizescreen.y") == 0)
        setting->size_screen.y = atof(check_is_value());
    if (strcmp(param, "ScreenMode") == 0)
        setting->screen_mode = atoi(check_is_value());
    if (strcmp(param, "FPS") == 0)
        setting->fps = atof(check_is_value());
    if (strcmp(param, "SoundGame") == 0)
        setting->sound_game = atof(check_is_value());
    if (strcmp(param, "Language") == 0)
        setting->language = my_strdup(check_is_value());
    return OK;
}

static int get_setting_file(rpg_t *rpg, char *line)
{
    rpg->setting->size_screen = (sfVector2f) {-1, -1};
    rpg->setting->fps = -1;
    rpg->setting->screen_mode = false;
    rpg->setting->sound_game = -1;
    rpg->setting->language = NULL;
    if (set_settings_menu(rpg->setting, line) == KO)
        return KO;
    setting_by_default(rpg->setting);
    return OK;
}

static int parse_settings_file(rpg_t *rpg)
{
    FILE *file = fopen(FILE_SETTING, "r");
    size_t len = 0;
    char *line = NULL;

    if (!file)
        return KO;
    while (getline(&line, &len, file) != -1) {
        check_commentary(&line);
        if (check_blankline(line) == OK)
            continue;
        if (get_setting_file(rpg, line) == KO)
            return KO;
    }
    free(line);
    fclose(file);
    return OK;
}

int settings_game(rpg_t *rpg)
{
    rpg->setting = malloc(sizeof(stock_setting_t));
    rpg->setting->language = NULL;
    if (!rpg->setting)
        return KO;
    if (parse_settings_file(rpg) == KO)
        return KO;
    setting_by_default(rpg->setting);
    return OK;
}
