/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-trystan.lescoat
** File description:
** object.c
*/

#include <my_defender.h>

void display_buttons(sfRenderWindow *win, buttons_t *buttons)
{
    for (int i = 0; i < buttons->size; i++)
        sfRenderWindow_drawSprite(win, buttons->all[i].sprite, NULL);
}

void destroy_buttons(buttons_t *buttons)
{
    for (int i = 0; i < buttons->size; i++) {
        sfRectangleShape_destroy(buttons->all[i].rect);
        sfTexture_destroy(buttons->all[i].click);
        sfTexture_destroy(buttons->all[i].hover);
        sfTexture_destroy(buttons->all[i].inactive);
        sfSprite_destroy(buttons->all[i].sprite);
    }
}