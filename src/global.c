/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-trystan.lescoat
** File description:
** global.c
*/

#include <my_defender.h>

void create_global(global_t *global, int value, sfVector2f pos, char *img)
{
    global->pos = pos;
    global->img = sfTexture_createFromFile(img, NULL);
    global->sprite = sfSprite_create();
    global->value = value;
    global->clock = sfClock_create();
    sfSprite_setPosition(global->sprite, global->pos);
    global->pos.x += 230;
    global->pos.y += 20;
    global->font = sfFont_createFromFile("assets/font.TTF");
    global->text = create_text(global->text, global->pos, global->font, 40);
    sfSprite_setTexture(global->sprite, global->img, sfTrue);
}

void destroy_global(global_t *global)
{
    sfClock_destroy(global->clock);
    sfTexture_destroy(global->img);
    sfSprite_destroy(global->sprite);
    sfFont_destroy(global->font);
    sfText_destroy(global->text);
}