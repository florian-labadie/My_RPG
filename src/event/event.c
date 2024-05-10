/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** event
*/

#include "my.h"

static int (*events_manager[][GAME_STATE_SIZE])(rpg_t *rpg, sfEvent event) = {
    {main_menu_event, help_menu_event, settings_menu_event},
    {select_event, game_event, pause_menu_event, inventory_menu_event}
};

static void charnge_enum_status(rpg_t *rpg, char *status)
{
    if (rpg->screen == MAIN_MENU)
        *status = rpg->menu->screen;
    if (rpg->screen == GAME)
        *status = rpg->game->screen;
}

void event_manager(rpg_t *rpg)
{
    sfEvent event = {};
    char status = 0;

    while (sfRenderWindow_pollEvent(rpg->window, &event)) {
        if (event.type == sfEvtClosed || rpg->screen == END) {
            rpg->screen = END;
            return sfRenderWindow_close(rpg->window);
        }
        charnge_enum_status(rpg, &status);
        events_manager[rpg->screen][(int)status](rpg, event);
    }
}
