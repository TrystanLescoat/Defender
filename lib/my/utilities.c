/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-trystan.lescoat
** File description:
** utilities.c
*/

int normalized_int(int nb)
{
    if (nb == 0)
        return (0);
    else if (nb > 0)
        return (-1);
    else
        return (1);
}