/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Usage file for my_sokoban
*/

#include <stdbool.h>
#include <curses.h>
#include "usage.h"
#include "my.h"

int check_args(int ac, char **av)
{
    if (ac != 2) {
        my_puterr(BAD_NB_ARGS_ERR_MSG);
        my_puterr(USAGE);
        return (MY_EXIT_FAILURE);
    }
    if (my_strcmp(av[1], "-h") == 0 || my_strcmp(av[1], "--help") == 0) {
        my_putstr(USAGE);
        return (MY_EXIT_OPTION);
    }
    return (MY_EXIT_SUCCESS);
}

bool terminal_is_too_small(map_t *map)
{
    unsigned int row = 0;
    unsigned int col = 0;

    getmaxyx(stdscr, row, col);
    return (row < map->max_row || col < map->max_col);
}