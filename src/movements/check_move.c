/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Booleans to check if a move can be made
*/

#include <stdbool.h>
#include <curses.h>
#include "my_sokoban.h"
#include "map.h"
#include "pos.h"
#include "move.h"

bool can_move(map_t *map, pos_t *pos, move_t *move)
{
    pos_t *target = pos;
    char target_char = 0;

    target->x = pos->x + move->x_offset;
    target->y = pos->y + move->y_offset;
    if (is_off_limits(target, map))
        return (FALSE);
    target_char = map->map[target->y][target->x];
    if (target_char == WALL_CHAR)
        return (FALSE);
    else if (target_char == BOX_CHAR)
        return ((can_move(map, target, move)) ? TRUE : FALSE);
    return (TRUE);
}

bool is_movement_key(int key)
{
    int movement_keys[] = {
        KEY_LEFT,
        KEY_RIGHT,
        KEY_UP,
        KEY_DOWN,
        0
    };

    for (unsigned int i = 0 ; movement_keys[i] ; i++)
        if (key == movement_keys[i])
            return (TRUE);
    return (FALSE);
}

bool is_off_limits(pos_t *pos, map_t *map)
{
    if (pos->x == 0 || pos->x > map->nb_cols - 1)
        return (TRUE);
    if (pos->y == 0 || pos->y > map->nb_rows - 1)
        return (TRUE);
    return (FALSE);
}