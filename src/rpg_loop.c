/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** rpgLoop
*/

#include "my.h"

int rpg_loop(rpg_t *rpg)
{
    void (*draw_fct[])(rpg_t *rpg) = {draw_menu, draw_game};
    void (*mangager_fct[])(rpg_t *rpg) = {menu_manager, game_manager};

    while (sfRenderWindow_isOpen(rpg->window)) {
        sfRenderWindow_clear(rpg->window, sfWhite);
        mangager_fct[rpg->screen](rpg);
        event_manager(rpg);
        draw_fct[rpg->screen](rpg);
        sfRenderWindow_display(rpg->window);
    }
    writte_setting_in_file(rpg);
    sfRenderWindow_close(rpg->window);
    destroy_resources(rpg);
    return 0;
}
