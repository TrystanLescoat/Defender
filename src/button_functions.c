/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-trystan.lescoat
** File description:
** button_functions.c
*/

#include <my_defender.h>

void play_button(var_t *var)
{
    var->current = 3;
}

void score_button(var_t *var)
{
    var->current = 2;
}

void how_button(var_t *var)
{
    var->current = 1;
}

void back_button(var_t *var)
{
    if (var->current == 3)
        var->reset = 1;
    if (var->current != 0)
        var->current = 0;
    var->image = NULL;
}

void quit_button(var_t *var)
{
    var->quit = 1;
}