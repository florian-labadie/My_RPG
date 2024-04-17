/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-amazed-baptiste.blambert
** File description:
** proto
*/

#ifndef PROTO_H_
    #define PROTO_H_

    #include "rpg.h"

char *check_env(char const *const *env);
char *fs_open_file(char const *filepath);
int error_handling(int argc, char const *const *argv);

int launch_rpg(char const *user);
int rpg_loop(rpg_t *rpg);
void destroy_resources(rpg_t *rpg);

/* GLOBAL FUNCTION*/
sfSprite *create_button(sfTexture *texture, sfVector2f scale, sfVector2f pos);
sfText *create_text(sfFont *font, char *sentence, int size, sfVector2f pos);

/* MENU SETUP */
int menu_setup(rpg_t *rpg, char const *user);
int background_menu_setup(menu_t *menu);
int background_player_setup(menu_t *menu);
int menu_button_setup(button_t *button);

/* GAME SETUP */
int game_setup(rpg_t *rpg);

/* MENU EVENT */
void event_manager(rpg_t *rpg);
void main_menu_event(rpg_t *rpg, sfEvent event);
void help_menu_event(rpg_t *rpg, sfEvent event);
void settings_menu_event(rpg_t *rpg, sfEvent event);

/* GAME EVENT */
void game_event(rpg_t *rpg, sfEvent event);
void pause_menu_event(rpg_t *rpg, sfEvent event);
void inventory_menu_event(rpg_t *rpg, sfEvent event);

/* MENU MANAGER */
void menu_manager(rpg_t *rpg);
void background_menu_manager(menu_t *menu);
void background_player_manager(menu_t *menu);

/* GAME MANAGER */
void game_manager(rpg_t *rpg);

#endif /* PROTO_H_ */
