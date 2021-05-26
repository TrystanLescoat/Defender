/*
** EPITECH PROJECT, 2020
** B-PSU-100-MPL-1-1-myprintf-maya.hill
** File description:
** my_putnbr_base.c
*/

#include <stdlib.h>
#include "../../include/my_printf.h"
#include "../../include/my.h"

void my_putnbr_base(unsigned int nbr, char *base)
{
    char *str;
    int size = 0;
    int len = my_strlen(base);

    if (nbr == 0)
        my_putchar('0');
    if (len == 0)
        return;
    for (unsigned int i = nbr; i > 0; i = i / len, size++);
    str = malloc(sizeof(char) * (size + 1));
    str[size] = 0;
    size--;
    for (; nbr > 0; nbr = nbr / len, size--)
        str[size] = base[nbr % len];
    my_putstr(str);
    free(str);
}