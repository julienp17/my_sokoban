/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Header file for usage
*/

#ifndef USAGE_H_
    #define USAGE_H_

    #include <stdbool.h>
    #include "map.h"

    #define MY_EXIT_SUCCESS       0
    #define MY_EXIT_OPTION        192
    #define MY_EXIT_FAILURE       84

    #define BAD_NB_ARGS_ERR_MSG  "Incorrect numbers of arguments (must be 1)\n"
    #define USAGE                                                              \
    "Usage\n"                                                                  \
    "    ./my_sokoban map\n"                                                   \
    "DESCRIPTION\n"                                                            \
    "    map file representing the warehouse map, containing '#' for walls,\n" \
    "\t'P' for the player, 'X' for boxes, and '0' for storage locations.\n"
    #define TERM_TOO_SMALL_MSG  "Terminal too small, please resize !"
    #define UNKNOWN_CHAR_IN_MAP_ERR_MSG "Unknown char in map\n"

    int check_args(int ac, char **av);
    bool terminal_is_too_small(map_t *map);
#endif