/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** destroy_menu
*/

#include "my.h"

static void destroy_background_menu(background_menu_t *background)
{
    sfClock_destroy(background->bg_anim_clock);
    sfSprite_destroy(background->background_sprite);
    sfTexture_destroy(background->background_texture);
    for (int i = 0; background->characters[i]; i++)
        sfSprite_destroy(background->characters[i]);
    sfTexture_destroy(background->characters_texture);
    free(background);
}

static void destroy_main_menu_button(main_menu_buttons_t *button)
{
    sfTexture_destroy(button->rectangle_text);
    sfFont_destroy(button->font);
    free(button->buttons_status);
    for (int i = 0; button->sprites[i]; i++) {
        sfSprite_destroy(button->sprites[i]);
        sfText_destroy(button->text[i]);
    }
    free(button->sprites);
    free(button->text);
    sfTexture_destroy(button->help_book);
    sfTexture_destroy(button->help_back);
    sfSprite_destroy(button->help_book_spr);
    sfSprite_destroy(button->help_back_spr);
    free(button);
}

static void destroy_main_menu(main_menu_t *main_menu)
{
    sfTexture_destroy(main_menu->wos_text);
    sfSprite_destroy(main_menu->wos_sprite);
    sfText_destroy(main_menu->wos);
    destroy_main_menu_button(main_menu->buttons);
    free(main_menu);
}

static void destroy_parallax_menu(parallax_t *parallax)
{
    sfSprite_destroy(parallax->background_sprite);
    sfTexture_destroy(parallax->background_texture);
    for (int i = 0; i < NB_PARALLAX; i++) {
        sfSprite_destroy(parallax->sprites[i]);
        sfTexture_destroy(parallax->textures[i]);
    }
    sfFont_destroy(parallax->font);
    sfText_destroy(parallax->parallax_text);
    free(parallax);
}

static void destroy_other_settings(settings_t *settings)
{
    for (int i = 0; i < 3; i++) {
        sfTexture_destroy(settings->extern_text[i]);
        sfSprite_destroy(settings->extern_sp[i]);
        sfTexture_destroy(settings->intern_text[i]);
        sfSprite_destroy(settings->intern_sp[i]);
        sfTexture_destroy(settings->fps_text[i]);
        sfSprite_destroy(settings->fps_sp[i]);
        sfText_destroy(settings->fps[i]);
    }
    for (int i = 0; i < 4; i++) {
        sfTexture_destroy(settings->book_text[i]);
        sfSprite_destroy(settings->book_sp[i]);
        sfText_destroy(settings->title[i]);
    }
    sfClock_destroy(settings->b_clock);
    sfText_destroy(settings->volume_text);
    sfFont_destroy(settings->font);
}

static void destroy_settings_menu(settings_t *settings)
{
    for (int i = 0; i < 2; i++) {
        sfSprite_destroy(settings->reso_sp[i]);
        sfTexture_destroy(settings->reso_text[i]);
        sfText_destroy(settings->reso[i]);
    }
    destroy_other_settings(settings);
    free(settings);
}

void destroy_menu(menu_t *menu)
{
    if (menu->menu_sound)
        sfMusic_destroy(menu->menu_sound);
    if (menu->click_button_sound)
        sfSound_destroy(menu->click_button_sound);
    if (menu->sound_buffer)
        sfSoundBuffer_destroy(menu->sound_buffer);
    if (menu->background)
        destroy_background_menu(menu->background);
    if (menu->main_menu)
        destroy_main_menu(menu->main_menu);
    if (menu->parallax)
        destroy_parallax_menu(menu->parallax);
    if (menu->setting)
        destroy_settings_menu(menu->settings);
    return;
}
