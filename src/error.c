/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** error.c
*/

#include <my_defender.h>

int nb_x_side(char **map, int i, int j, int nb_x)
{
    if (map[i + 1][j] == 'x' || map[i + 1][j] == 'S' || map[i + 1][j] == 'F')
        nb_x++;
    if (map[i - 1][j] == 'x' || map[i - 1][j] == 'S' || map[i - 1][j] == 'F')
        nb_x++;
    if (map[i][j + 1] == 'x' || map[i][j + 1] == 'S' || map[i][j + 1] == 'F')
        nb_x++;
    if (map[i][j - 1] == 'x' || map[i][j - 1] == 'S' || map[i][j - 1] == 'F')
        nb_x++;
    if (nb_x != 2)
        return (84);
    return (0);
}

int check_char_map(char c)
{
    if (c == ' ' || c == 'S' || c == 'F' || c == '#')
        return (0);
    if (c == 'x' || c == 'O' || c == '\n' || c == '\0')
        return (0);
    return (84);
}

int search_nb_x_side(char **map, int i, int nb_x)
{
    for (int j = 0; map[i][j]; j++) {
        nb_x = 0;
        if (check_char_map(map[i][j]) == 84)
            return (84);
        if (map[i][j] == 'x' && nb_x_side(map, i, j, nb_x) == 84)
            return (84);
    }
    return (0);
}

void nb_s_and_f(char **map, int i, int *nb_s, int *nb_f)
{
    for (int j = 0; map[i][j]; j++){
        if (map[i][j] == 'S')
            (*nb_s)++;
        if (map[i][j] == 'F')
            (*nb_f)++;
    }
}

int error_map(char **map)
{
    int nb_x = 0;
    int nb_s = 0;
    int nb_f = 0;

    if (my_strlen_array(map) != 17)
        return (84);
    for (int i = 0; map[i]; i++)
        if (my_strlen(map[i]) != 31)
            return (84);
    for (int i = 0; map[i]; i++) {
        if (search_nb_x_side(map, i, nb_x) == 84)
            return (84);
        nb_s_and_f(map, i, &nb_s, &nb_f);
    }
    if (nb_s != 1 || nb_f != 1)
        return (84);
    return (0);
}