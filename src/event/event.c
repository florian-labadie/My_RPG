/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** event
*/

#include "my.h"

static void (*events_manager[])(rpg_t *rpg) = {
    main_menu_event,
    game_event,
    pause_menu_event,
    inventory_event
};

static void what_is_clicked(rpg_t *rpg, sfVector2f mouse)
{
    sfFloatRect b = {-100, -100, -100, -100};
    sfBool contains = sfFalse;

    if (mouse.y >= 150 && mouse.y <= 1920 && rpg->status->mod != HELP)
        return draw(rpg);
    for (int i = 0; i < 16; i += 1) {
        b = sfRectangleShape_getGlobalBounds(rpg->buttons[i]->btn);
        contains = sfFloatRect_contains(&b, mouse.x, mouse.y);
        if (contains == sfTrue)
            return set_cursor(rpg, HOOKED);
    }
    for (int i = 0; i < 8; i += 1) {
        b = sfCircleShape_getGlobalBounds(rpg->colors[i]->circle);
        contains = sfFloatRect_contains(&b, mouse.x, mouse.y);
        if (contains == sfTrue)
            return set_cursor(rpg, HOOKED);
    }
    set_cursor(rpg, rpg->status->prev_cursor);
}

static int check_scrolls(rpg_t *rpg, sfEvent *event, sfVector2f mouse)
{
    if (rpg->pen_size->scroll == NORMAL) {
        scroll_size(rpg, event, mouse);
        return 1;
    }
    if (rpg->palette->scroll == NORMAL) {
        scroll_color(rpg, event, mouse);
        return 1;
    }
    return OK;
}

void event_manager(rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(rpg->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(rpg->window);
        if (mouse.y < 150)
            set_hover(rpg, mouse.x, mouse.y);
        get_keys(rpg, &event, mouse.y);
        if (check_scrolls(rpg, &event, mouse) == 1)
            return;
        if (sfMouse_isButtonPressed(sfMouseLeft))
            what_is_clicked(rpg, (sfVector2f){mouse.x, mouse.y});
        menu_event_manager(rpg, (sfVector2f){mouse.x, mouse.y}, &event);
    }
}
