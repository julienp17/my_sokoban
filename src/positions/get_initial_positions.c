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

pos_t **get_initial_entities_pos(char **map, char symbol)
{
    unsigned int nb_entities = my_count_char_str_array(map, symbol);
    pos_t **entities_pos = malloc(sizeof(*entities_pos) * (nb_entities + 1));
    unsigned int entities_index = 0;

    for (unsigned int i = 0 ; map[i] ; i = i + 1) {
        for (unsigned int j = 0 ; map[i][j] ; j = j + 1) {
            if (map[i][j] == symbol) {
                map[i][j] = SPACE_CHAR;
                entities_pos[entities_index] = pos_create(j, i);
                entities_index++;
            }
        }
    }
    entities_pos[entities_index] = NULL;
    return (entities_pos);
}