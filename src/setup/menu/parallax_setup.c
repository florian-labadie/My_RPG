/*
** EPITECH PROJECT, 2024
** parallax_setup.c
** File description:
** parallax
*/

#include "my.h"

static void define_font(parallax_t *parallax)
{
    sfVector2f text_pos;

    parallax->font = sfFont_createFromFile("assets/parallax/sewer.ttf");
    text_pos.x = 1920 / 3.2;
    text_pos.y = 1080 / 2.3;
    parallax->parallax_text = create_text(parallax->font,
    "Appuyez sur espace, pour commencer", 50, text_pos);
}

static void create_parallax_textures(parallax_t *parallax)
{
    parallax->textures[0] =
    sfTexture_createFromFile("assets/parallax/para/nature_3/1.png", NULL);
    parallax->textures[1] =
    sfTexture_createFromFile("assets/parallax/para/nature_3/2.png", NULL);
    parallax->textures[2] =
    sfTexture_createFromFile("assets/parallax/para/nature_3/3.png", NULL);
    parallax->textures[3] =
    sfTexture_createFromFile("assets/parallax/para/nature_3/4.png", NULL);
    parallax->textures[4] = NULL;
}

static void create_parallax_sprtie(parallax_t *parallax)
{
    parallax->sprites[0] = sfSprite_create();
    sfSprite_setTexture(parallax->sprites[0], parallax->textures[0], sfTrue);
    parallax->sprites[1] = sfSprite_create();
    sfSprite_setTexture(parallax->sprites[1], parallax->textures[1], sfTrue);
    parallax->sprites[2] = sfSprite_create();
    sfSprite_setTexture(parallax->sprites[2], parallax->textures[2], sfTrue);
    parallax->sprites[3] = sfSprite_create();
    sfSprite_setTexture(parallax->sprites[3], parallax->textures[3], sfTrue);
}

void init_parallax_speeds(parallax_t *parallax)
{
    parallax->speeds[0] = 0.025f;
    parallax->speeds[1] = 0.1f;
    parallax->speeds[2] = 0.2f;
    parallax->speeds[3] = 0.3f;
}

int init_parallax(parallax_t *parallax)
{
    parallax->background_texture =
    sfTexture_createFromFile("assets/parallax/para/nature_3/1.png", NULL);
    parallax->background_sprite = sfSprite_create();
    sfSprite_setTexture(parallax->background_sprite,
    parallax->background_texture, sfTrue);
    create_parallax_textures(parallax);
    create_parallax_sprtie(parallax);
    define_font(parallax);
    init_parallax_speeds(parallax);
    return OK;
}
