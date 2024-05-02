/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** writte_setting_in_file
*/

#include "my.h"

int write_setting_in_file(rpg_t *rpg)
{
    FILE *file_setting = fopen(FILE_SETTING, "w");

    if (!file_setting) {
        printf("Couldn't open setting file\n");
        return KO;
    }
    fprintf(file_setting, "[SETTINGS]\n\n");
    fprintf(file_setting, "Sizescreen.x=%.1f\n", rpg->setting->size_screen.x);
    fprintf(file_setting, "Sizescreen.y=%.1f\n", rpg->setting->size_screen.y);
    fprintf(file_setting, "ScreenMode=%d\n", rpg->setting->screen_mode);
    fprintf(file_setting, "FPS=%.1f\n", rpg->setting->fps);
    fprintf(file_setting, "SoundGame=%.1f\n", rpg->setting->sound_game);
    fclose(file_setting);
    return OK;
}
