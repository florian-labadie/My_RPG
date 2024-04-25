/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** save_game
*/

#include "my.h"

static void check_status(rpg_t *rpg, char *line)
{
    if (strcmp(line, SETTING_STR) == 0)
            rpg->setting->status = SETTINGS;
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
        setting->size_screen.x = atof(my_strtok(NULL, "\n"));
    if (strcmp(param, "Sizescreen.y") == 0)
        setting->size_screen.y = atof(my_strtok(NULL, "\n"));
    if (strcmp(param, "ScreenMode") == 0)
        setting->screen_mode = atoi(my_strtok(NULL, "\n"));
    if (strcmp(param, "FPS") == 0)
        setting->fps = atof(my_strtok(NULL, "\n"));
    if (strcmp(param, "SoundGame") == 0)
        setting->sound_game = atof(my_strtok(NULL, "\n"));
    return OK;
}

int settings_game(rpg_t *rpg)
{
    FILE *file = fopen(FILE_SETTING, "r");
    size_t len = 0;
    char *line = NULL;

    rpg->setting = malloc(sizeof(stock_setting_t));
    rpg->setting->status = malloc(sizeof(status_t));
    rpg->setting->status = SETTINGS;
    if (!rpg->setting || !file)
        return KO;
    while (getline(&line, &len, file) != -1) {
        check_commentary(&line);
        if (check_blankline(line) == OK)
            continue;
        check_status(rpg, line);
        if (rpg->setting->status == SETTINGS) {
            set_settings_menu(rpg->setting, line);
        }
    }
    return OK;
}
