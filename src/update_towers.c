/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-trystan.lescoat
** File description:
** update_towers.c
*/

#include <my_defender.h>

void attack_tower(map_t *map, tower_t *tower, var_t *var)
{
    int size = tower->stat.radius;
    sfVector2f new_pos = {tower->pos.x - size + 30, tower->pos.y - size + 30};

    for (int j = 0; j < map->nb_e; j++)
        attack_enemy(tower, &map->enemies[j], var);
    sfCircleShape_setPosition(tower->circle, new_pos);
    sfCircleShape_setRadius(tower->circle, size);
}

void slow_tower(map_t *map, tower_t *tower, var_t *var)
{
    int size = tower->stat.radius;
    sfVector2f new_pos = {tower->pos.x - size + 30, tower->pos.y - size + 30};

    for (int j = 0; j < map->nb_e; j++)
        slow_enemy(tower, &map->enemies[j], var);
    sfCircleShape_setPosition(tower->circle, new_pos);
    sfCircleShape_setRadius(tower->circle, size);
}

void money_tower(map_t *map, tower_t *tower, var_t *var)
{
    if (get_seconds(tower->clock) > 10.0 - tower->stat.speed / 2) {
        sfMusic_stop(var->sound.money_sfx);
        sfMusic_play(var->sound.money_sfx);
        var->money.value += tower->stat.power;
        sfClock_restart(tower->clock);
    }
}

void heal_tower(map_t *map, tower_t *tower, var_t *var)
{
    if (var->life.value + tower->stat.power <= 100) {
        if (get_seconds(tower->clock) > 10.0 - tower->stat.speed / 5) {
            var->life.value += tower->stat.power;
            sfClock_restart(tower->clock);
        }
    }
}