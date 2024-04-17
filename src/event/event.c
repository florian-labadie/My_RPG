/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** event
*/

#include "my.h"

static void (*events_manager[][GAME_STATE_SIZE])(rpg_t *rpg) = {
    {main_menu_event, help_menu_event, settings_menu_event},
    {game_event, pause_menu_event, inventory_menu_event}
};

void event_manager(rpg_t *rpg)
{
    sfEvent event = {};

    while (sfRenderWindow_pollEvent(rpg->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(rpg->window);
        events_manager[rpg->screen][0](rpg);
    }
}
