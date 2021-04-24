/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ducks.h"

int help()
{
    printf("USAGE\n    ./204ducks a\n");
    printf("DESCRIPTION\n");
    printf("    a      constant\n");
    exit(0);
}

int check_num(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] != '.' && (str[i] > '9' || str[i] < '0'))
            return (1);
    return (0);
}

int error(int ac, char **av)
{
    if (ac != 2)
        return (84);
    if (check_num(av[1]) && strcmp("-h", av[1]))
        return (84);
    if (atof(av[1]) < 0 || atof(av[1]) > 2.5)
        return (84);
    return (0);
}

int main(int ac, char **av)
{
    if (error(ac, av))
        return (84);
    if (strcmp("-h", av[1]) == 0)
        help();
    print(atof(av[1]));
    return (0);
}
