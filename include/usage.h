/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Header file for usage
*/

#ifndef USAGE_H_
    #define USAGE_H_

    #define MY_EXIT_SUCCESS         0
    #define MY_EXIT_OPTION          192
    #define MY_EXIT_FAILURE         84

    #define USAGE \
    "Usage\n" \
    "    ./my_sokoban map\n" \
    "DESCRIPTION\n" \
    "    map file representing the warehouse map, containing '#' for walls,\n" \
    "        'P' for the player, 'X' for boxes, and '0' for storage locations.\n"

    int check_args(int ac, char **av);
#endif