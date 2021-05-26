/*
** EPITECH PROJECT, 2020
** Day05
** File description:
** math_functions.c
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 0)
        return (1);
    if (nb == 0 || p < 0)
        return (0);
    return (nb * my_compute_power_rec(nb, p - 1));
}

float float_compute_power_rec(float nb, int p)
{
    if (p == 0)
        return (1);
    if (nb == 0 || p < 0)
        return (0);
    return (nb * float_compute_power_rec(nb, p - 1));
}

float my_abs(float nb)
{
    if (nb < 0)
        nb *= -1;
    return (nb);
}