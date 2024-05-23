/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** map
*/

#ifndef MAP_H_
    #define MAP_H_

    #define LAYER_MAP "assets/map/layer_texture.png"
    #define MAP_P "assets/map/map_rpg.png"
    #define MAP_OBJ "assets/map/map_rpg_texture.png"
    #define FORGE_MAP "assets/map/forgeron.png"
    #define ALCHEMY_MAP "assets/map/alchemist.png"
    #define LAYER_MAP "assets/map/layer_texture.png"
    #define AMB_MUSIC "assets/music/ambiance_music.ogg"
    #define SHOP_MUSIC "assets/music/shop_music.ogg"
    #define BATTLE_MUSIC "assets/music/fight_music.ogg"
    #define PARTICLE "assets/map/portal_particles.png"
    #define FLAG "assets/map/flag_portal.png"
    #define BATTLE_MAP "assets/map/map_battelfiel.png"
    #define WIZZARD "assets/sprite/wizard_bf.png"
    #define ORK "assets/sprite/orc.png"
    #define NB_PARTICLE 15
    #define NB_ORK 15
    #define LIFE_RECT_SIZE ((sfVector2f){227, 21})

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>

typedef enum choice_map_s {
    VILLAGE,
    BATTLEFIELD,
    FORGE,
    ALCHEMY,
    NB_MAP
} choice_map_t;

typedef struct particle_s {
    sfTexture *particle_text;
    sfSprite **particule_spr;
    sfIntRect *particle_rect;
    sfClock *part_clock;
    sfTime time_clock;
} particle_t;

typedef struct flag_s {
    sfTexture *flag_text;
    sfSprite *flag_spr;
    sfText *write_flag;
    sfFont *flag_font;
    sfRectangleShape *flag_zone;
    bool is_flag;
    bool was_open;
    sfClock *flag_clock;
    int flag_pos;
} flag_t;

typedef struct house_s {
    sfTexture *house_texture;
    sfSprite *house;
    sfText *house_text;
    sfFont *house_font;

    sfMusic *house_music;
} house_t;

typedef struct entities_bf_s {
    sfTexture *wizzard_text;
    sfSprite *wizzard_spr;
    sfClock *wizz_clock;
    sfIntRect wizzard_rect;

    sfTexture *ork_text;
    sfSprite **ork_spr;
    sfIntRect ork_rect;
} entities_bf_t;

typedef struct map_s {
    choice_map_t choice_map;

    sfTexture *texture_obj;
    sfSprite *sprite_obj;
    sfImage *layers;

    sfTexture *battle_text;
    sfSprite *battle_spr;
    sfMusic *battle_music;

    sfMusic *game_sound;

    house_t **house;
    particle_t particle;
    flag_t flag;
    entities_bf_t *entities;

    sfTexture *texture_ground;
    sfSprite *sprite_ground;
    sfView *view;
    sfFloatRect rect;
} map_t;

#endif /* !MAP_H_ */
