/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-trystan.lescoat
** File description:
** update_enemies.c
*/

#include <my_defender.h>

sfVector2f enemy_next_pos(enemy_t *enemy)
{
    path_t *temp = NULL;
    sfVector2f dist = points_distance(enemy->path->pos, enemy->path->next->pos);

    if (my_abs(dist.x) <= enemy->speed && my_abs(dist.y) <= enemy->speed) {
        if (enemy->path && enemy->path->next) {
            temp = enemy->path;
            enemy->path = enemy->path->next;
            free(temp);
        }
    } else {
        enemy->path->pos.x += normalized_int(dist.x) * enemy->speed;
        enemy->path->pos.y += normalized_int(dist.y) * enemy->speed;
    }
    return (enemy->path->pos);
}

void update_enemies(enemy_t *enemy, var_t *var)
{
    if (enemy->path && enemy->path->next)
        enemy->pos = enemy_next_pos(enemy);
    else if (enemy->hp > 0) {
        var->life.value -= 10;
        enemy->hp = 0;
    }
    if (enemy->rect.left < 180)
        enemy->rect.left += 60;
    else
        enemy->rect.left = 0;
    sfSprite_setPosition(enemy->sprite, enemy->pos);
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    sfClock_restart(enemy->clock);
}

void display_enemies(sfRenderWindow *window, map_t *map, var_t *var)
{
    var->nb_end = 0;
    for (int i = 0; i < map->nb_e; i++)
        if (get_seconds(map->enemies[i].clock) > 0.05)
            update_enemies(&map->enemies[i], var);
    for (int i = 0; i < map->nb_e; i++)
        if (map->enemies[i].hp > 0)
            sfRenderWindow_drawSprite(window, map->enemies[i].sprite, NULL);
}

void change_to_place_tile(map_t *map, tower_t tower)
{
    tile_t tile;

    for (int i = 0; i < map->nb_tile; i++) {
        tile = map->tiles[i];
        if (tile.pos.x == tower.pos.x && tile.pos.y == tower.pos.y)
            map->tiles[i].type = PLACE;
    }
}

void update_towers(map_t *map, var_t *var)
{
    int nb = 0;

    for (int i = 0; i < map->nb_obj; i++) {
        if (map->objects[i].stat.power == 0 && map->objects[i].type == TOWER) {
            change_to_place_tile(map, map->objects[i]);
            map->objects[i].type = D_TOWER;
        }
        if (map->objects[i].type == TOWER)
            map->objects[i].ptr(map, &map->objects[i], var);
    }
    for (int j = 0; j < map->nb_e; j++)
        if (map->enemies[j].hp <= 0)
            nb++;
    if (map->nb_e != 0 && nb == map->nb_e) {
        destroy_enemies(map->enemies, map->nb_e);
        var->wave.value += 1;
        var->nb_enemies = var->wave.value * rand_nbr(1, 3);
        map->nb_e = 0;
    }
}