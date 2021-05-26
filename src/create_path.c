/*
** EPITECH PROJECT, 2020
** My_Defense
** File description:
** create_path.c
*/

#include <my_defender.h>

void destroy_paths(path_t **paths)
{
    path_t *temp;
    path_t *my_list = *paths;

    if (*paths == NULL)
        return;
    for (; my_list->next; my_list = temp) {
        temp = my_list->next;
        free(my_list);
    }
    free(my_list);
    *paths = NULL;
}

void push_back_path(path_t **paths, sfVector2f pos)
{
    path_t *new_path = malloc(sizeof(path_t));
    path_t *temp = *paths;

    if (paths == NULL)
        return;
    while (temp->next != NULL)
        temp = temp->next;
    new_path->pos = pos;
    new_path->next = NULL;
    temp->next = new_path;
}

int is_path(char **map, int x, int y)
{
    if (x < 0 || y < 0)
        return (0);
    if (map[x][y] == 'x' || map[x][y] == 'F') {
        map[x][y] = 'd';
        return (1);
    }
    return (0);
}

sfVector2f get_next_pos(sfVector2f fpos, char **map)
{
    sfVector2i pos = (sfVector2i){fpos.x / 60, fpos.y / 60};

    if (is_path(map, pos.y + 1, pos.x))
        fpos.y += 60;
    if (is_path(map, pos.y - 1, pos.x))
        fpos.y -= 60;
    if (is_path(map, pos.y, pos.x + 1))
        fpos.x += 60;
    if (is_path(map, pos.y, pos.x - 1))
        fpos.x -= 60;
    return (fpos);
}

void create_paths(enemy_t *enemy, char **map, sfVector2f dest)
{
    sfVector2f pos = enemy->pos;
    char **dup_map = duplicate_map(map);

    enemy->path = malloc(sizeof(path_t));
    enemy->path->pos = enemy->pos;
    enemy->path->next = NULL;
    while (pos.x != dest.x || pos.y != dest.y) {
        pos = get_next_pos(pos, dup_map);
        push_back_path(&enemy->path, pos);
    }
    push_back_path(&enemy->path, dest);
    free_array(dup_map);
}