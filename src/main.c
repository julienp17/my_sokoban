/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Main file for my_sokoban
*/

#include <stddef.h>
#include "usage.h"
#include "file_manipulation.h"

int main(int ac, char **av)
{
    int exit_code = 0;
    char **map = NULL;

    exit_code = check_args(ac, av);
    if (exit_code == MY_EXIT_OPTION)
        return (MY_EXIT_SUCCESS);
    else if (exit_code == MY_EXIT_FAILURE)
        return (MY_EXIT_FAILURE);
    map = get_map_from_file(av[1]);
    (void)map;
    return (MY_EXIT_SUCCESS);
}