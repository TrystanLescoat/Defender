/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-trystan.lescoat
** File description:
** build_menu.c
*/

#include <my_defender.h>

void build_menu(var_t *var)
{
    var->menu = 0;
    if (var->image == NULL) {
        var->stat.power = 0;
        var->stat.cost_power = 0;
        var->stat.radius = 0;
        var->stat.cost_radius = 0;
        var->stat.speed = 0;
        var->stat.cost_speed = 0;
    }
}

void close_menu(var_t *var)
{
    var->menu = 5;
    if (var->image == NULL) {
        var->stat.power = 0;
        var->stat.cost_power = 0;
        var->stat.radius = 0;
        var->stat.cost_radius = 0;
        var->stat.speed = 0;
        var->stat.cost_speed = 0;
    }
}

void upgrade_power(var_t *var)
{
    int money = var->money.value;

    if (var->carried_stats && money >= var->carried_stats->cost_power) {
        var->money.value -= var->carried_stats->cost_power;
        var->carried_stats->power += 1;
        var->stat.power += 1;
        var->stat.cost_power *= 1.5;
        var->carried_stats->cost_power *= 1.5;
    }
}

void upgrade_radius(var_t *var)
{
    int money = var->money.value;

    if (var->carried_stats && money >= var->carried_stats->cost_radius) {
        var->money.value -= var->carried_stats->cost_radius;
        var->carried_stats->radius += 5;
        var->carried_stats->cost_radius *= 1.5;
        var->stat.radius += 5;
        var->stat.cost_radius *= 1.5;
    }
}

void upgrade_speed(var_t *var)
{
    int money = var->money.value;

    if (var->carried_stats && money >= var->carried_stats->cost_speed) {
        var->money.value -= var->carried_stats->cost_speed;
        var->carried_stats->speed += 1;
        var->carried_stats->cost_speed *= 1.5;
        var->stat.speed += 1;
        var->stat.cost_speed *= 1.5;
    }
}