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
    #define LAYER_MAP "assets/map/layer_texture.png"
    #define AMB_MUSIC "assets/music/ambiance_music.ogg"
    #define PARTICLE "assets/map/portal_particles.png"
    #define FLAG "assets/map/flag_portal.png"
    #define NB_PARTICLE 15

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>

typedef enum choice_map_s {
    VILLAGE,
    BATTLEFIELD,
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

typedef struct map_s {
    choice_map_t choice_map;

    sfTexture *texture_obj;
    sfSprite *sprite_obj;
    sfImage *layers;

    sfMusic *game_sound;

    particle_t particle;
    flag_t flag;

    sfTexture *texture_ground;
    sfSprite *sprite_ground;
    sfView *view;
    sfFloatRect rect;
} map_t;

#endif /* !MAP_H_ */
