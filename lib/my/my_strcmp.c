/*
** EPITECH PROJECT, 2020
** Day06
** File description:
** my_strcmp.c
*/

int my_strcmp(char const *s1 , char const *s2)
{
    int size_s1 = 0;
    int size_s2 = 0;
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i = i + 1;
    size_s1 = s1[i];
    size_s2 = s2[i];
    if (size_s1 == size_s2)
        return (0);
    return (size_s1 - size_s2);
}
