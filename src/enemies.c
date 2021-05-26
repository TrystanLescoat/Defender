/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-trystan.lescoat
** File description:
** create_enemies.c
*/

#include <my_defender.h>

void attack_enemy(tower_t *tower, enemy_t *enemy, var_t *var)
{
    sfVector2f new_pos = enemy->pos;

    if (enemy->hp <= 0)
        return;
    new_pos.x += 30;
    new_pos.y += 30;
    if (get_seconds(tower->clock) > 1.0 - tower->stat.speed / 5) {
        if (circle_point_collision(tower->circle, new_pos)) {
            sfMusic_stop(var->sound.hit_sfx);
            sfMusic_play(var->sound.hit_sfx);
            enemy->hp -= tower->stat.power;
            sfClock_restart(tower->clock);
        }
        if (enemy->hp <= 0)
            var->money.value += enemy->gold;
    }
}

void slow_enemy(tower_t *tower, enemy_t *enemy, var_t *var)
{
    if (enemy->hp <= 0 || enemy->speed <= 1)
        return;
    if (get_seconds(tower->clock) > 2.0 - tower->stat.speed / 5) {
        if (circle_point_collision(tower->circle, enemy->pos)) {
            enemy->speed -= tower->stat.power;
            sfClock_restart(tower->clock);
        }
    }
    if (enemy->speed < 1)
        enemy->speed = 1;
}

void set_enemy_values(var_t *var, enemy_t *enemy)
{
    enemy->rect = (sfIntRect){0, 0, 60, 60};
    enemy->sprite = sfSprite_create();
    enemy->texture = sfTexture_createFromFile("assets/enemy.png", NULL);
    enemy->type = ENEMY;
    enemy->speed = 2 + var->wave.value / 2;
    enemy->gold = var->wave.value * 4;
    enemy->hp = 9 + float_compute_power_rec(1.5, var->wave.value - 1);
    enemy->clock = sfClock_create();
}

void add_enemy(map_t *map, var_t *var)
{
    enemy_t enemy;

    for (int i = 0; i < map->nb_obj; i++) {
        if (map->objects[i].type == START)
            enemy.pos = map->objects[i].pos;
        if (map->objects[i].type == DEST)
            map->dest = map->objects[i].pos;
    }
    set_enemy_values(var, &enemy);
    create_paths(&enemy, map->arr_map, map->dest);
    sfSprite_setTexture(enemy.sprite, enemy.texture, sfTrue);
    sfSprite_setTextureRect(enemy.sprite, enemy.rect);
    sfSprite_setPosition(enemy.sprite, enemy.pos);
    map->enemies[map->nb_e] = enemy;
    map->nb_e += 1;
}