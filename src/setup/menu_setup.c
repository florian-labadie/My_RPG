/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** setup_menu
*/

#include "my.h"

static int malloc_struct(rpg_t *rpg)
{
    rpg->menu = malloc(sizeof(menu_t));
    rpg->menu->main_menu = malloc(sizeof(main_menu_t));
    rpg->menu->help = malloc(sizeof(help_t));
    rpg->menu->settings = malloc(sizeof(settings_t));
    rpg->menu->background = malloc(sizeof(background_menu_t));
    rpg->game = malloc(sizeof(game_t));
    rpg->game->player = malloc(sizeof(player_t));
    rpg->map = malloc(sizeof(map_t));
    if (!rpg->menu || !rpg->menu->main_menu || !rpg->menu->help ||
        !rpg->menu->settings || !rpg->menu->background || !rpg->game ||
        !rpg->game->player || !rpg->map)
        return KO;
    return OK;
}

static int setup_menu_music(menu_t *menu, stock_setting_t *setting)
{
    menu->menu_sound = sfMusic_createFromFile(MUSIC_MENU);
    menu->sound_buffer = sfSoundBuffer_createFromFile(SOUND_CLICK_BUTTON);
    menu->click_button_sound = sfSound_create();
    if (!menu->menu_sound || !menu->click_button_sound || !menu->sound_buffer)
        return KO;
    sfSound_setBuffer(menu->click_button_sound, menu->sound_buffer);
    return OK;
}

static int setup_main_menu(menu_t *menu, sfRenderWindow *window)
{
    if (menu_button_setup(&menu->main_menu->buttons, window) == KO)
        return KO;
    menu->main_menu->wos_text = sfTexture_createFromFile(WOS_SIGN, NULL);
    menu->main_menu->wos_sprite = create_button(menu->main_menu->wos_text,
        get_resize(window, 2.5, 1.3), get_resize(window, 410, -10));
    menu->main_menu->buttons->font = sfFont_createFromFile(TITLE_FONT);
    menu->main_menu->wos = create_text(menu->main_menu->buttons->font,
        "World Of silveria", get_less_size(window, 80.0),
        get_resize(window, 630, 70.0));
    return OK;
}

int menu_setup(rpg_t *rpg, char const *user)
{
    if (!rpg || !user || malloc_struct(rpg) == KO)
        return KO;
    rpg->menu->screen = MAIN;
    if (!rpg->menu->main_menu || !rpg->menu->help || !rpg->menu->settings)
        return KO;
    if (background_menu_setup(rpg->menu, rpg->window) == KO ||
        setup_main_menu(rpg->menu, rpg->window) == KO ||
        setup_menu_music(rpg->menu, rpg->setting) == KO)
        return KO;
    if (game_setup(rpg) == KO)
        return OK;
    if (setup(rpg->menu->settings) == KO)
        return KO;
    return OK;
}
