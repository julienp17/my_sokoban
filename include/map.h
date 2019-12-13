/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Header file for map
*/

#ifndef MAP_H_
    #define MAP_H_

    typedef struct map {
        char **map;
        char **org_map;
        unsigned int max_row;
        unsigned int max_col;
    } map_t;

    map_t *get_map_from_file(char *filepath);
#endif