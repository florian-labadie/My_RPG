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
    void (*manager_fct[])(rpg_t *rpg) = {menu_manager, game_manager};

    while (sfRenderWindow_isOpen(rpg->window)) {
        sfRenderWindow_clear(rpg->window, sfWhite);
        set_volume_music(rpg);
        event_manager(rpg);
        if (rpg->screen == END)
            break;
        manager_fct[rpg->screen](rpg);
        draw_fct[rpg->screen](rpg);
        sfRenderWindow_display(rpg->window);
    }
    sfRenderWindow_close(rpg->window);
    write_setting_in_file(rpg);
    destroy_resources(rpg);
    return 0;
}
