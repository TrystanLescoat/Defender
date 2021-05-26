/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-trystan.lescoat
** File description:
** object.c
*/

#include <my_defender.h>

void create_buttons_array(buttons_t *buttons)
{
    buttons->size = 0;
}

sfRectangleShape *create_rect(sfVector2f pos, sfVector2f size)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setOutlineColor(rect, sfBlack);
    sfRectangleShape_setOutlineThickness(rect, 1.0);
    sfRectangleShape_setFillColor(rect, sfBlack);
    return (rect);
}

void add_graphics(char *info, button_t *button)
{
    sfVector2f pos = sfRectangleShape_getPosition(button->rect);
    char **graphics = my_str_to_word_array(info, "=, ");

    button->inactive = sfTexture_createFromFile(graphics[1], NULL);
    button->hover = sfTexture_createFromFile(graphics[2], NULL);
    button->click = sfTexture_createFromFile(graphics[3], NULL);
    button->sprite = sfSprite_create();
    sfSprite_setPosition(button->sprite, pos);
    sfSprite_setTexture(button->sprite, button->inactive, sfTrue);
    free_array(graphics);
}

void add_button(buttons_t *buttons, char *info, void (*ptr)(var_t *var))
{
    button_t button;
    char **attr = my_str_to_word_array(info, "=, ");
    sfVector2f pos = (sfVector2f){my_getnbr(attr[4]), my_getnbr(attr[5])};
    sfVector2f size = (sfVector2f){my_getnbr(attr[6]), my_getnbr(attr[7])};

    button.rect = create_rect(pos, size);
    button.ptr = ptr;
    buttons->all[buttons->size] = button;
    buttons->size += 1;
    free_array(attr);
}