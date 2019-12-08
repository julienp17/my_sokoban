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
        unsigned int nb_cols;
        unsigned int nb_rows;
    } map_t;

    map_t *get_map_from_file(char *filepath);
    map_t *create_map_from_file_buffer(char *file_buffer);
#endif