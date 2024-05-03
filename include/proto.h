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
int change_button_rect(sfSprite *sprite, button_state_t *changed_status,
    button_state_t status, sfSound *sound);
int check_blankline(char *line);
void check_commentary(char **line);
sfVector2f get_resize(sfRenderWindow *window, float x, float y);
sfVector2f get_mouse_pos(sfRenderWindow *window, sfVector2u window_size);
float get_less_size(sfRenderWindow *window, float value);
void set_text_mid_origin(sfText *text);
void set_srpite_mid_origin(sfSprite *sprite);
void set_volume_music(rpg_t *rpg);

/* MENU SETUP */
int menu_setup(rpg_t *rpg, char const *user);
int background_menu_setup(menu_t *menu, sfRenderWindow *window);
int menu_button_setup(main_menu_buttons_t **button, sfRenderWindow *window);
int setup_option_menu(settings_t *settings, sfRenderWindow *window);
int open_book(settings_t *settings);

/* GAME SETUP */
int game_setup(rpg_t *rpg);
int player_setup(sfRenderWindow *window, player_t *player);
int setup_map(map_t *map, sfRenderWindow *window);
void change_view(game_t *game, sfRenderWindow *window);
int select_charac(game_t *game, sfRenderWindow *window);

/* MENU EVENT */
void event_manager(rpg_t *rpg);
int main_menu_event(rpg_t *rpg, sfEvent event);
int help_menu_event(rpg_t *rpg, sfEvent event);
int settings_menu_event(rpg_t *rpg, sfEvent event);

/* GAME EVENT */
int select_event(rpg_t *rpg, sfEvent event);
int load_save_event(rpg_t *rpg, sfEvent event);
int game_event(rpg_t *rpg, sfEvent event);
int pause_menu_event(rpg_t *rpg, sfEvent event);
int inventory_menu_event(rpg_t *rpg, sfEvent event);

/* MENU MANAGER */
void menu_manager(rpg_t *rpg);
void background_menu_manager(menu_t *menu);

/* GAME MANAGER */
void game_manager(rpg_t *rpg);

/* OPTION */
int anim_open_book(settings_t *settings);
int anim_next_page(settings_t *settings);
int anim_previous_page(settings_t *settings);
int anim_close_book(settings_t *settings);

/* OPTION */
int setup(settings_t *settings);
int display_book(settings_t *settings);

/* SETTINGS */
int settings_game(rpg_t *rpg);
int write_setting_in_file(rpg_t *rpg);

/* DRAWING FUNCTIONS */
void draw_game(rpg_t *rpg);
void draw_menu(rpg_t *rpg);

#endif /* PROTO_H_ */
