/*
** EPITECH PROJECT, 2020
** Day07
** File description:
** my_strcat.c
*/

#include "../../include/my.h"
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int len1 = my_strlen(dest);
    int len2 = my_strlen(src);
    char *new_str = malloc(sizeof(char) * (len1 + len2 + 1));

    for (; dest[i]; i++) {
        new_str[i] = dest[i];
    }
    for (int j = 0; src[j]; j++) {
        new_str[i] = src[j];
        i = i + 1;
    }
    new_str[i] = 0;
    return (new_str);
}
