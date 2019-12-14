/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Booleans to check if a move can be made
*/

#include <stdbool.h>
#include <stdlib.h>
#include <curses.h>
#include "my_sokoban.h"
#include "map.h"
#include "pos.h"
#include "move.h"
#include "my.h"

bool can_move(map_t *map, pos_t *target, move_t *direction, bool is_player)
{
    pos_t *next_target = NULL;

    if (is_off_limits(target, map))
        return (FALSE);
    if (map->map[target->y][target->x] == WALL_CHAR)
        return (FALSE);
    if ((next_target = get_box_pos(target, map->boxes)) != NULL) {
        if (!is_player)
            return (FALSE);
        next_target->x = next_target->x + direction->x_offset;
        next_target->y = next_target->y + direction->y_offset;
        return (can_move(map, next_target, direction, false));
    }
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
    return (pos->x > (int)my_strlen(map->map[pos->y])
            || pos->y > (int)map->max_row);
}