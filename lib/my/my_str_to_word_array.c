/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** my_str_to_word_array.c
*/

#include <stdlib.h>
#include "../../include/my.h"

int is_delim(char c, char const *delim)
{
    for (int i = 0; delim[i]; i++)
        if (c == delim[i])
            return (-1);
    return (0);
}

void shift_int(char const *str, char const *delim, int *i)
{
    for (; is_delim(str[*i], delim) == -1; (*i) += 1);
}

int len_words(char const *str, char const *delim, int *i)
{
    int len = 0;

    for (; str[*i] && is_delim(str[*i], delim) == 0; (*i) += 1)
        len++;
    for (; is_delim(str[*i], delim) == -1 && str[*i]; (*i) += 1);
    return (len);
}

void make_array(char **array, char const *str, char const *delim)
{
    int i = 0;
    int x = 0;
    int y = 0;

    while (str[i]) {
        if (is_delim(str[i], delim) == -1) {
            array[x][y] = 0;
            x++;
            y = 0;
            shift_int(str, delim, &i);
        } else {
            array[x][y] = str[i];
            y++;
            i++;
        }
    }
}

char **my_str_to_word_array(char const *str, char *delim)
{
    char **array;
    int len_temp = 0;
    int words = 1;
    int n = 0;

    for (int i = 0; str[i]; i++) {
        if (is_delim(str[i], delim) == -1) {
            words++;
            shift_int(str, delim, &i);
        }
    }
    array = malloc(sizeof(char *) * (words + 1));
    array[words] = NULL;
    for (int i = 0; i < words; i++) {
        len_temp = len_words(str, delim, &n) + 1;
        array[i] = malloc(sizeof(char *) * (len_temp + 1));
        array[i][len_temp - 1] = 0;
        array[i][len_temp] = 0;
    }
    make_array(array, str, delim);
    return (array);
}
