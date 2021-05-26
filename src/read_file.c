/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-trystan.lescoat
** File description:
** read_file.c
*/

#include <my_defender.h>

char **duplicate_map(char **map)
{
    int len = my_strlen_array(map);
    char **dup_map = malloc(sizeof(char *) * (len + 1));

    dup_map[len] = NULL;
    for (int i = 0; map[i]; i++)
        dup_map[i] = my_strdup(map[i]);
    return (dup_map);
}

sfVector2f int_vec_to_float(sfVector2i int_vec)
{
    sfVector2f float_vec = (sfVector2f) {int_vec.x - 30, int_vec.y - 30};

    return (float_vec);
}

char *read_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat s;
    char *buff;

    if (fd < 0)
        return (NULL);
    if (stat(filepath, &s) < 0)
        return (NULL);
    buff = malloc(s.st_size + 1);
    if (buff == NULL)
        return (NULL);
    buff[s.st_size] = 0;
    if (read(fd, buff, s.st_size) < 0)
        return (NULL);
    if (close(fd) < 0)
        return (NULL);
    return (buff);
}

char **read_file_array(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat s;
    char *buff = NULL;
    char **array = NULL;

    if (fd < 0)
        return (NULL);
    if (stat(filepath, &s) < 0)
        return (NULL);
    buff = malloc(s.st_size + 1);
    if (buff == NULL)
        return (NULL);
    buff[s.st_size] = 0;
    if (read(fd, buff, s.st_size) < 0)
        return (NULL);
    if (close(fd) < 0)
        return (NULL);
    array = my_str_to_word_array(buff, "\n");
    free(buff);
    return (array);
}