/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** villager.h
*/



#ifndef VILLAGER_H_
    #define VILLAGER_H_

    #include "rpg.h"

    #define RICH_MAN_P "assets/sprite/rich_v.png"
    #define WOMAN_P "assets/sprite/woman_v.png"
    #define OLD_LADY_P "assets/sprite/old_v.png"
    #define WORKER_P "assets/sprite/worker_v.png"

typedef struct villager_s {
    sfTexture **v_text;
    sfSprite **v_sp;
} villager_t;

#endif
