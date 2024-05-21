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

/* GLOBAL FUNCTION */
sfSprite *create_button(sfTexture *texture, sfVector2f scale, sfVector2f pos);
sfText *create_text(sfFont *font, char *sentence, int size, sfVector2f pos);
bool get_sprite_bounds(sfSprite *sprite, sfVector2f pos);
bool get_rectangle_bounds(sfRectangleShape *rectangle, sfVector2f pos);
int already_pressed(button_state_t *button_status, int size);
int change_button_rect(sfSprite *sprite, button_state_t *changed_status,
    button_state_t status, sfSound *sound);
int check_blankline(char *line);
void check_commentary(char **line);
sfVector2f get_resize(sfRenderWindow *window, float x, float y);
sfVector2f get_mouse_pos(sfRenderWindow *window, sfVector2u window_size);
float get_less_size(sfRenderWindow *window, float value);
void set_text_mid_origin(sfText *text);
void set_sprite_button_mid_origin(sfSprite *sprite);
void set_volume_music(rpg_t *rpg);
char *read_one_dialogue(char *filepath);
char *read_many_dialogue(char *filepath, int dialogue_number);
int parallax_event(rpg_t *rpg, sfEvent event);

/* MENU SETUP */
int menu_setup(rpg_t *rpg, char const *user);
int background_menu_setup(menu_t *menu, sfRenderWindow *window);
int menu_button_setup(main_menu_buttons_t **button, sfRenderWindow *window);
int setup_option_menu(settings_t *settings, sfRenderWindow *window);
int open_book(settings_t *settings);
int init_parallax(parallax_t *parallax);

/* GAME SETUP */
int game_setup(rpg_t *rpg);
int player_setup(sfRenderWindow *window, player_t *player);
int setup_flag(map_t *map, sfRenderWindow *window);
int setup_particles(map_t *map);
int setup_map(map_t *map, sfRenderWindow *window, float volume);
void change_view(game_t *game, sfRenderWindow *window);
int select_charac(game_t *game, sfRenderWindow *window);
int pause_menu_setup(game_t *game, sfRenderWindow *window);
void set_pause_screen(pause_t *pause, sfFloatRect view_rect);

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
void book_actions
(sfRenderWindow *window, menu_t *menu, sfBool arrow_l, sfBool arrow_r);
void exit_action(menu_t *menu, sfBool exit);
int turn_book(settings_t *settings, sfSprite *sprite, sfClock *clock);
int open_close_book(sfSprite *sprite, sfClock *clock);

/* OPTION */
int setup(settings_t *settings);
int display_book(settings_t *settings);

/* SETTINGS */
int settings_game(rpg_t *rpg);
int write_setting_in_file(rpg_t *rpg);

/* DRAWING FUNCTIONS */
void draw_game(rpg_t *rpg);
void draw_menu(rpg_t *rpg);
void draw_particles(game_t *game, sfRenderWindow *window);
void draw_flag(game_t *game, sfRenderWindow *window);

#endif /* PROTO_H_ */
