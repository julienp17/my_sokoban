/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Header file for map
*/

#ifndef MAP_H_
    #define MAP_H_

    #include "pos.h"

    typedef struct map {
        char **map;
        char **org_map;
        unsigned int max_row;
        unsigned int max_col;
        pos_t *player;
        pos_t **boxes;
        pos_t **storage;
    } map_t;

    map_t *get_map_from_file(char *filepath);
    map_t *map_create_from_file_buffer(char *file_buffer);
    void map_destroy(map_t *map);
    bool is_valid_map(char const *file_buffer);
#endif