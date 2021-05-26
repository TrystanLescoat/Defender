/*
** EPITECH PROJECT, 2020
** My_Defender
** File description:
** help_option.c
*/

#include <my_defender.h>

int print_help(void)
{
    my_printf("\n USAGE\n\n");
    my_printf("\t./my_defender [FILE | -m]\n\n");
    my_printf(" DESCRIPTION\n\n");
    my_printf("\tFILE\tpath to a map\n");
    my_printf("\t\texample maps can be found in the maps/ folder\n");
    my_printf("\n\t-m\tinformation on map requirements\n\n");
    return (0);
}

int print_map_info(void)
{
    my_printf("\n MAP REQUIREMENTS\n\n");
    my_printf("\tTILES\n\n");
    my_printf("\t\t- '#' represent walls\n");
    my_printf("\t\t- ' ' represent grass\n");
    my_printf("\t\t- 'S' represents where enemies spawn\n");
    my_printf("\t\t- 'F' represents the castle you need to protect\n");
    my_printf("\t\t- 'x' represent the path followed by enemies\n");
    my_printf("\t\t- 'O' represent where you can place towers\n");
    my_printf("\n\tAll other characters are invalid.\n");
    my_printf("\n\tSIZE\n\n");
    my_printf("\t\tThe map must be 17x31 (17 lines of 31 columns).\n");
    my_printf("\n\tPATH\n\n");
    my_printf("\t\tThe path can't split into different paths ");
    my_printf("(ie: an 'x' must not have more than 2 adjacent 'x').\n\n");
    return (0);
}

int get_options(int argc, char **argv)
{
    if (argc == 1 || (argc == 2 && !my_strcmp(argv[1], "-h")))
        return (print_help());
    else if (argc == 2 && !my_strcmp(argv[1], "-m"))
        return (print_map_info());
    return (1);
}