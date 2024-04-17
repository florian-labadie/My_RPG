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

/* FCT Générique*/
sfSprite *create_button(sfTexture *texture, sfVector2f scale, sfVector2f pos);
sfText *create_text(sfFont *font, char *sentence, int size, sfVector2f pos);

/* MENU */
int setup_menu(rpg_t *rpg);
int setup_background_menu(menu_t *menu);
void background_menu_manager(menu_t *menu);
int setup_background_player(menu_t *menu);
void background_player_manager(menu_t *menu);

// EVENT MANAGEMENT FUNCTIONS
void event_manager(rpg_t *rpg);
void main_menu_event(rpg_t *rpg);
void help_menu_event(rpg_t *rpg);
void settings_menu_event(rpg_t *rpg);
void game_event(rpg_t *rpg);
void pause_menu_event(rpg_t *rpg);
void inventory_menu_event(rpg_t *rpg);

#endif /* PROTO_H_ */
