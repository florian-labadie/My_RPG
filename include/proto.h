/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-amazed-baptiste.blambert
** File description:
** proto
*/

#ifndef PROTO_H_
    #define PROTO_H_

    #include "rpg.h"

    #include "stdbool.h"

char *check_env(char const *const *env);
char *fs_open_file(char const *filepath);
int error_handling(int argc, char const *const *argv);

int launch_rpg(char const *user);
int rpg_loop(rpg_t *rpg);
void destroy_resources(rpg_t *rpg);

/* GLOBAL FUNCTION*/
sfSprite *create_button(sfTexture *texture, sfVector2f scale, sfVector2f pos);
sfText *create_text(sfFont *font, char *sentence, int size, sfVector2f pos);
bool get_sprite_bounds(sfSprite *sprite, sfVector2f pos);
void set_rect_button(sfSprite *button, button_state_t status);
void change_button_rect(sfSprite *sprite, button_state_t *changed_status,
    button_state_t status, sfSound *sound);
int check_blankline(char *line);
void check_commentary(char **line);
sfVector2f get_resize(sfRenderWindow *window, float x, float y);
sfVector2f get_mouse_pos(sfRenderWindow *window, sfVector2u window_size);
float get_less_size(sfRenderWindow *window, float value);

/* MENU SETUP */
int menu_setup(rpg_t *rpg, char const *user);
int background_menu_setup(menu_t *menu, sfRenderWindow *window);
int menu_button_setup(main_menu_buttons_t **button, sfRenderWindow *window);

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

/* GAME MANAGER */
void game_manager(rpg_t *rpg);

int settings_game(rpg_t *rpg);
#endif /* PROTO_H_ */
