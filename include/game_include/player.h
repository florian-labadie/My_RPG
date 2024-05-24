/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_
    #define HEALTH_BAR "assets/sprite/life.jpg"
    #define DEAFEAT "assets/sprite/defeat.png"

    #include "rpg.h"

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #define HUMAN_STILL_RECT ((sfIntRect){0, 0, 52, 56})
    #define DWARF_STILL_RECT ((sfIntRect){0, 110, 52, 60})
    #define ELF_STILL_RECT ((sfIntRect){0, 228, 52, 62})
    #define HUMAN_RECT ((sfIntRect){210, 0, 52, 56})
    #define DWARF_RECT ((sfIntRect){209, 112, 52, 57})
    #define ELF_RECT ((sfIntRect){210, 226, 52, 62})
    #define HUMAN_ATT_RECT ((sfIntRect){210, 56, 52, 56})
    #define DWARF_ATT_RECT ((sfIntRect){209, 169, 52, 57})
    #define ELF_ATT_RECT ((sfIntRect){210, 290, 52, 62})
    #define CHARACTERS_ATK_RECT ((sfIntRect){0, 0, 54, 55})

typedef enum player_direction_e {
    UP,
    DOWN,
    LEFT,
    RIGHT
} player_direction_t;

typedef enum player_state_e {
    STILL,
    MOVE
} player_state_t;

typedef struct player_stats_s {
    float health;
    float mana;
    float attack;
    float magic_attack;
    float defense;
    int level;
    int xp;
    int nb_gold;
    sfText *level_text;
} player_stats_t;

typedef struct player_sprites_s {
    sfCircleShape *range;
    sfCircleShape *hitbox;
    sfTexture *player_text;
    sfSprite *player;

    sfIntRect player_rect;
    sfClock *player_clock;
    sfClock *attack_clock;
    sfClock *move_clock;
} player_sprites_t;

typedef struct life_player_s {
    sfTexture *health_bar_text;
    sfSprite *health_bar_spr;

    sfRectangleShape **rects;

    sfRectangleShape *loos_rect;
    sfTexture *lose_text;
    sfSprite *lose_spr;
    sfClock *time_lose;
} life_player_t;

typedef struct player_s {
    char *name;
    player_race_t race;
    life_player_t *life;
    bool attack;
    bool is_alive;

    sfVector2f position;
    sfVector2f last_pos;

    player_sprites_t *sprites;
    player_stats_t stats;
} player_t;

#endif /* !PLAYER_H_ */
