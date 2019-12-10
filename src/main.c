/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Main file for my_sokoban
*/

#include <stddef.h>
#include "usage.h"
#include "file_manipulation.h"
#include "map.h"
#include "my_sokoban.h"

int main(int ac, char **av)
{
    int exit_code = 0;
    map_t *map = NULL;

    exit_code = check_args(ac, av);
    if (exit_code == MY_EXIT_OPTION)
        return (MY_EXIT_SUCCESS);
    else if (exit_code == MY_EXIT_FAILURE)
        return (MY_EXIT_FAILURE);
    if ((map = get_map_from_file(av[1])) == NULL)
        return (MY_EXIT_FAILURE);
    play_game(map);
    return (MY_EXIT_SUCCESS);
}