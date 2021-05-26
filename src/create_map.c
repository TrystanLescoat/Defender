/*
** EPITECH PROJECT, 2020
** Sokoban
** File description:
** object.c
*/

#include <my_defender.h>

void init_map(map_t *map, char **arr_map)
{
    int len = 0;

    map->max_x = (1080 / 60 - my_strlen_array(arr_map)) / 2;
    map->max_y = 0;
    for (int i = 0; arr_map[i]; i++) {
        len = my_strlen(arr_map[i]);
        if (len > map->max_y)
            map->max_y = len;
    }
    map->max_y = (1920 / 60 - map->max_y) / 2;
    map->nb_obj = 0;
    map->nb_tile = 0;
    map->nb_e = 0;
    map->arr_map = arr_map;
    for (int x = 0; arr_map[x]; x++)
        for (int y = 0; arr_map[x][y]; y++)
            add_elem(map, arr_map[x][y], x + map->max_x, y + map->max_y);
}

void init_tower(tower_t *tower, var_t *var)
{
    int size = var->stat.radius;
    sfVector2f new_pos = {tower->pos.x - size + 30, tower->pos.y - size + 30};
    sfColor color = (sfColor){255, 255, 255, 180};

    tower->sprite = sfSprite_create();
    tower->texture = var->image;
    tower->rect = (sfIntRect){0, 0, 60, 60};
    tower->type = TOWER;
    tower->stat.type = var->stat.type;
    tower->stat.power = var->stat.power;
    tower->stat.radius = size;
    tower->stat.speed = var->stat.speed;
    tower->ptr = var->ptr;
    tower->clock = sfClock_create();
    sfSprite_setTexture(tower->sprite, tower->texture, sfTrue);
    sfSprite_setPosition(tower->sprite, tower->pos);
    tower->circle = sfCircleShape_create();
    sfCircleShape_setPosition(tower->circle, new_pos);
    sfCircleShape_setRadius(tower->circle, size);
    sfCircleShape_setFillColor(tower->circle, color);
}

void add_tile(tile_t *tile, char type)
{
    tile->texture = sfTexture_createFromFile("assets/path.png", NULL);
    tile->rect = (sfIntRect){0, 0, 60, 60};
    tile->type = FLOOR;
    if (type == '#') {
        sfTexture_destroy(tile->texture);
        tile->texture = sfTexture_createFromFile("assets/wall.png", NULL);
        tile->type = WALL;
    }
    if (type == ' ') {
        sfTexture_destroy(tile->texture);
        tile->texture = sfTexture_createFromFile("assets/grass.png", NULL);
    }
    if (type == 'O') {
        sfTexture_destroy(tile->texture);
        tile->texture = sfTexture_createFromFile("assets/place.png", NULL);
        tile->type = PLACE;
    }
    sfSprite_setTextureRect(tile->sprite, tile->rect);
    sfSprite_setTexture(tile->sprite, tile->texture, sfTrue);
}

void add_object(tower_t *object, char type)
{
    object->texture = sfTexture_createFromFile("assets/path.png", NULL);
    object->sprite = sfSprite_create();
    object->rect = (sfIntRect){0, 0, 60, 60};
    object->circle = NULL;
    if (type == 'S')
        object->type = START;
    else if (type == 'F')
        object->type = DEST;
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setTextureRect(object->sprite, object->rect);
    sfSprite_setPosition(object->sprite, object->pos);
}

void add_elem(map_t *map, char type, int x, int y)
{
    tile_t tile;
    tower_t object;

    tile.sprite = sfSprite_create();
    tile.pos = (sfVector2f){y * 60, x * 60};
    add_tile(&tile, type);
    if (type == 'S' || type == 'F' || type == 'T') {
        object.pos = (sfVector2f){y * 60, x * 60};
        add_object(&object, type);
        map->objects[map->nb_obj] = object;
        map->nb_obj += 1;
    }
    sfSprite_setTexture(tile.sprite, tile.texture, sfTrue);
    sfSprite_setTextureRect(tile.sprite, tile.rect);
    sfSprite_setPosition(tile.sprite, tile.pos);
    map->tiles[map->nb_tile] = tile;
    map->nb_tile += 1;
}