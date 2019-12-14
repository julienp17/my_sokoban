/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** get_initial_positions
*/

#include <stdbool.h>
#include <stdlib.h>
#include "pos.h"
#include "my_sokoban.h"
#include "my.h"

pos_t *get_initial_player_pos(char **map, char symbol)
{
    for (unsigned int i = 0 ; map[i] ; i = i + 1)
        for (unsigned int j = 0 ; map[i][j] ; j = j + 1)
            if (map[i][j] == symbol) {
                map[i][j] = SPACE_CHAR;
                return (pos_create(j, i));
            }
    return (NULL);
}

pos_t **get_initial_boxes_pos(char **map, char symbol)
{
    unsigned int nb_boxes = my_count_char_str_array(map, symbol);
    pos_t **boxes_pos = malloc(sizeof(*boxes_pos) * (nb_boxes + 1));
    unsigned int boxes_index = 0;

    for (unsigned int i = 0 ; map[i] ; i = i + 1) {
        for (unsigned int j = 0 ; map[i][j] ; j = j + 1) {
            if (map[i][j] == symbol) {
                map[i][j] = SPACE_CHAR;
                boxes_pos[boxes_index] = pos_create(j, i);
                boxes_index++;
            }
        }
    }
    boxes_pos[boxes_index] = NULL;
    return (boxes_pos);
}