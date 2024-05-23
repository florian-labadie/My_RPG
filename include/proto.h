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
void set_sprite_mid_origin(sfSprite *sprite);
void set_sprite_button_mid_origin(sfSprite *sprite);
void set_volume_music(rpg_t *rpg);
char *read_one_dialogue(char *filepath);
char *read_many_dialogue(char *filepath, int dialogue_number);
int parallax_event(rpg_t *rpg, sfEvent event);
void reset_view(sfView *view, sfRenderWindow *window, sfVector2f pos);

/* MENU SETUP */
int menu_setup(rpg_t *rpg, char const *user);
int background_menu_setup(menu_t *menu, sfRenderWindow *window);
int menu_button_setup(main_menu_buttons_t **button, sfRenderWindow *window);
int setup_option_menu(settings_t *settings, sfRenderWindow *window);
void setup_help_menu(sfRenderWindow *window, menu_t *menu);
int open_book(settings_t *settings);
int init_parallax(parallax_t *parallax);


/* GAME SETUP */
int game_setup(rpg_t *rpg);
int player_setup(sfRenderWindow *window, player_t *player);
int entities_setup(entities_bf_t **entities, sfRenderWindow *window);
int setup_flag(map_t *map, sfRenderWindow *window);
int setup_particles(map_t *map);
int setup_map(map_t *map, sfRenderWindow *window, float volume);
int setup_house(map_t *map, sfRenderWindow *window);
int set_up_battlefield(sfRenderWindow *window, map_t *map, float volume);
void change_view(game_t *game, sfRenderWindow *window);
void change_player_pos_bf(game_t *game, sfRenderWindow *window);
int select_charac(game_t *game, sfRenderWindow *window);
int pause_menu_setup(game_t *game, sfRenderWindow *window);
int interaction_setup(game_t *game, sfRenderWindow *window);
int inventory_menu_setup(game_t *game, sfRenderWindow *window);
int shop_buy_setup(game_t *game, sfRenderWindow *window);
int setup_item_inventory(game_t *game, sfRenderWindow *window);
int init_help_menu(rpg_t *rpg, help_menu_t *help_menu);

/* MENU EVENT */
void event_manager(rpg_t *rpg);
int main_menu_event(rpg_t *rpg, sfEvent event);
int settings_menu_event(rpg_t *rpg, sfEvent event);
int help_menu_event(rpg_t *rpg, sfEvent event);

/* GAME EVENT */
int select_event(rpg_t *rpg, sfEvent event);
int load_save_event(rpg_t *rpg, sfEvent event);
int game_event(rpg_t *rpg, sfEvent event);
int pause_menu_event(rpg_t *rpg, sfEvent event);
int inventory_menu_event(rpg_t *rpg, sfEvent event);
void interaction_event(rpg_t *rpg, sfEvent event);
void buy_article(rpg_t *rpg, sfEvent event);
void show_flag(rpg_t *rpg, sfEvent event);
void event_battlefield(rpg_t *rpg, sfEvent event);

/* MENU MANAGER */
void menu_manager(rpg_t *rpg);
void background_menu_manager(menu_t *menu);

/* GAME MANAGER */
void game_manager(rpg_t *rpg);
void level_manager(game_t *game);
void life_manager(game_t *game, sfRenderWindow *window, float value);
void inventory_manager(game_t *game);
void ork_movement(sfVector2f ork_pos, sfVector2f player_pos, ork_t *ork,
    float speed);

/* OPTION */
void book_actions(rpg_t *rpg, sfEvent event, sfBool arrow_l, sfBool arrow_r);
void exit_action(rpg_t *rpg, sfEvent event, sfBool exit);
int turn_book(settings_t *settings, sfSprite *sprite, sfClock *clock);
int open_close_book(sfSprite *sprite, sfClock *clock);
void display_page_1(sfRenderWindow *wiw, menu_t *menu);
void display_page_2(sfRenderWindow *wiw, menu_t *menu);
void handle_events_page_1(rpg_t *rpg, sfEvent event);
void handle_events_page_2(rpg_t *rpg, sfEvent event);
void update_volume_text(rpg_t *rpg, float volume);
void music_sound(rpg_t *rpg, sfEvent event);
void begin_anim(sfSprite *sprite);
void set_fps(rpg_t *rpg, sfEvent event);
void set_window_size(rpg_t *rpg, sfEvent event);
void draw_arrows_and_turn_pages(sfRenderWindow *window, menu_t *menu);

/* OPTION */
int setup(settings_t *settings);
int display_book(settings_t *settings);

/* SETTINGS */
int settings_game(rpg_t *rpg);
int write_setting_in_file(rpg_t *rpg);

/* DRAWING FUNCTIONS */
void draw_game(rpg_t *rpg);
void draw_forge(sfRenderWindow *window, game_t *game);
void draw_alchemist(sfRenderWindow *window, game_t *game);
void draw_pause_menu(sfRenderWindow *window, game_t *game);
void draw_inventory(sfRenderWindow *window, game_t *game);
void draw_menu(rpg_t *rpg);
void draw_particles(game_t *game, sfRenderWindow *window);
void draw_flag(game_t *game, sfRenderWindow *window);

/* DESTROY FUNCTIONS */
void destroy_rpg(rpg_t *rpg);
void destroy_game(game_t *game);
void destroy_menu(menu_t *menu);
void set_life_village(game_t *game, sfRenderWindow *window);
void set_life_battle(sfRenderWindow *window, game_t *game);

#endif /* PROTO_H_ */
