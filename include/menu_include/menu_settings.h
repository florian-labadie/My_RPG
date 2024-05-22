/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** settings
*/

#ifndef SETTINGS_H_
    #define SETTINGS_H_

    #define MAX_PAGES 1

    #define OPEN_BOOK_P "assets/book_animation/book_1.png"
    #define NEXT_PAGE_P "assets/book_animation/book_2.png"
    #define PREVIOUS_PAGE_P "assets/book_animation/book_3.png"
    #define CLOSE_BOOK_P "assets/book_animation/book_4.png"
    #define RIGHT_ARROW_P "assets/book_animation/right_arrow.png"
    #define LEFT_ARROW_P "assets/book_animation/left_arrow.png"
    #define PLUS_SIGN_P "assets/book_animation/plus_sign.png"
    #define MINUS_SIGN_P "assets/book_animation/minus_sign.png"
    #define HOME_SIGN_P "assets/book_animation/home_button.png"
    #define TIT_SOUND_P "assets/book_animation/title_sound.png"
    #define TIT_FPS_P "assets/book_animation/title_fps.png"
    #define TIT_KEY_P "assets/book_animation/title_keybindings.png"
    #define TIT_RESO_P "assets/book_animation/title_resolution.png"
    #define GAMERIA_FONT "assets/Font/GAMERIA.ttf"
    #define FPS_30_P "assets/book_animation/30_fps.png"
    #define FPS_45_P "assets/book_animation/45_fps.png"
    #define FPS_60_P "assets/book_animation/60_fps.png"
    #define D_ARROW_P "assets/book_animation/direct_flèches.png"
    #define D_ZQSD_P "assets/book_animation/direct_zqsd.png"
    #define FULL_SREEN_P "assets/book_animation/full_screen.png"
    #define SPLIT_SCREEN_P "assets/book_animation/split_screen.png"

    #define OPEN_BOOK_R ((sfIntRect) {-50, 0, 252, 297})
    #define TURN_PAGE_R ((sfIntRect) {-9, 0, 251, 297})
    #define CLOSE_BOOK_R ((sfIntRect) {-9, 0, 252, 297})


typedef struct settings_s {
    sfTexture **book_text;
    sfTexture **extern_text;
    sfTexture **intern_text;
    sfTexture **title_text;
    sfTexture **fps_text;
    sfTexture **reso_text;
    sfSprite **reso_sp;
    sfSprite **fps_sp;
    sfSprite **title_sp;
    sfSprite **book_sp;
    sfSprite **extern_sp;
    sfSprite **intern_sp;
    sfSprite *minus_sp;
    sfSprite *plus_sp;


    sfBool arrow_bool_r;
    sfBool arrow_bool_l;

    sfClock *b_clock;

    int current_page;

    sfSprite *title_sprite;
    sfText *title[4];
    sfText *fps[3];
    sfText *reso[2];

    sfText *volume_text;
    sfFont *font;
    char volume_str[4];
} settings_t;

typedef struct keyboard_s {
    sfKeyCode code[4];
} keyboard_t;

#endif /* !SETTINGS_H_ */
