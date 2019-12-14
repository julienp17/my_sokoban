/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Booleans to check if a move can be made
*/

#include <stdbool.h>
#include <stdlib.h>
#include "my_sokoban.h"
#include "map.h"
#include "pos.h"
#include "move.h"
#include "my.h"

bool can_move(map_t *map, pos_t *pos, move_t *direction, bool is_player)
{
    pos_t *target = pos_create(pos->x + direction->x_offset,
                                pos->y + direction->y_offset);
    pos_t *box_pos = NULL;

    if (is_off_limits(target, map))
        return (FALSE);
    if (map->map[target->y][target->x] == WALL_CHAR)
        return (FALSE);
    box_pos = get_box_pos(target, map->boxes);
    if (box_pos)
        return ((is_player) ? can_move(map, box_pos, direction, false) : FALSE);
    free(target);
    return (TRUE);
}

pos_t *get_box_pos(pos_t *target, pos_t **boxes)
{
    for (unsigned int i = 0 ; boxes[i] ; i = i + 1)
        if (is_on_same_pos(target, boxes[i]))
            return (boxes[i]);
    return (NULL);
}

bool is_off_limits(pos_t *pos, map_t *map)
{
    return (pos->x > ((int)my_strlen(map->map[pos->y]) - 1)
            || pos->y > ((int)map->max_row));
}