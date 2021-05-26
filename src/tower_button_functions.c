/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-trystan.lescoat
** File description:
** button_functions.c
*/

#include <my_defender.h>

void money_button(var_t *var)
{
    if (var->image != NULL)
        sfTexture_destroy(var->image);
    var->cost = 100;
    var->menu = 2;
    var->ptr = money_tower;
    var->stat.power = 1;
    var->stat.cost_power = 20;
    var->stat.radius = 0;
    var->stat.cost_radius = 0;
    var->stat.speed = 1;
    var->stat.cost_speed = 20;
    var->stat.type = MONEY;
    var->carried_stats = NULL;
    var->image = sfTexture_createFromFile("assets/elec_tower.png", NULL);
    sfSprite_setTexture(var->m_sprite, var->image, sfTrue);
}

void heal_button(var_t *var)
{
    if (var->image != NULL)
        sfTexture_destroy(var->image);
    var->cost = 400;
    var->menu = 4;
    var->ptr = heal_tower;
    var->stat.power = 1;
    var->stat.cost_power = 20;
    var->stat.radius = 0;
    var->stat.cost_radius = 0;
    var->stat.speed = 1;
    var->stat.cost_speed = 20;
    var->stat.type = HEAL;
    var->carried_stats = NULL;
    var->image = sfTexture_createFromFile("assets/glue_tower.png", NULL);
    sfSprite_setTexture(var->m_sprite, var->image, sfTrue);
}

void attack_button(var_t *var)
{
    if (var->image != NULL)
        sfTexture_destroy(var->image);
    var->cost = 50;
    var->menu = 1;
    var->ptr = attack_tower;
    var->stat.power = 1;
    var->stat.cost_power = 20;
    var->stat.radius = 60;
    var->stat.cost_radius = 20;
    var->stat.speed = 1;
    var->stat.cost_speed = 20;
    var->stat.type = ATTACK;
    var->carried_stats = NULL;
    var->image = sfTexture_createFromFile("assets/fire_tower.png", NULL);
    sfSprite_setTexture(var->m_sprite, var->image, sfTrue);
}

void slow_button(var_t *var)
{
    if (var->image != NULL)
        sfTexture_destroy(var->image);
    var->cost = 200;
    var->menu = 3;
    var->ptr = slow_tower;
    var->stat.power = 1;
    var->stat.cost_power = 20;
    var->stat.radius = 60;
    var->stat.cost_radius = 20;
    var->stat.speed = 1;
    var->stat.cost_speed = 20;
    var->stat.type = SLOW;
    var->carried_stats = NULL;
    var->image = sfTexture_createFromFile("assets/ice_tower.png", NULL);
    sfSprite_setTexture(var->m_sprite, var->image, sfTrue);
}