/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** map
*/

#ifndef MAP_H_
    #define MAP_H_
    #define MAP_P "assets/map/map_rpg.png"
    #define MAP_OBJ "assets/map/map_rpg_texture.png"

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>

typedef struct map_s {
    sfTexture *texture_obj;
    sfSprite *sprite_obj;

    sfTexture *texture_ground;
    sfSprite *sprite_ground;
    sfView *view;
    sfFloatRect rect;
    sfVector2f move_vect;
} map_t;

#endif /* !MAP_H_ */
