/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** game_should_go_on
*/

#include <stdlib.h>
#include <stdbool.h>
#include "my_sokoban.h"
#include "my.h"
#include "move.h"

int game_should_go_on(int key, map_t *map)
{
    if (key == QUIT_KEY || key == ESCAPE_KEY)
        return (0);
    if (all_storage_are_filled(map->storage, map->boxes))
        return (0);
    if (!all_boxes_can_be_moved(map))
        return (1);
    return (42);
}

bool all_storage_are_filled(pos_t **storage, pos_t **boxes)
{
    bool filled = true;

    for (unsigned int i = 0 ; storage[i] && filled ; i++)
        filled = storage_is_filled(storage[i], boxes);
    return (filled);
}

bool storage_is_filled(pos_t *storage_pos, pos_t **boxes)
{
    for (unsigned int i = 0 ; boxes[i] ; i++)
        if (is_on_same_pos(storage_pos, boxes[i]))
            return (true);
    return (false);
}

bool all_boxes_can_be_moved(map_t *map)
{
    bool can_move = false;

    for (unsigned int i = 0 ; map->boxes[i] && !can_move ; i++)
        can_move = box_can_move(map, map->boxes[i]);
    return (can_move);
}

bool box_can_move(map_t *map, pos_t *pos)
{
    int x_keys[] = {KEY_LEFT, KEY_RIGHT, 0};
    int y_keys[] = {KEY_UP, KEY_DOWN, 0};
    int x_possible_moves = 0;
    int y_possible_moves = 0;

    for (unsigned int i = 0 ; x_keys[i] != 0 ; i++) {
        if (can_move(map, pos, get_move_by_key(x_keys[i]), false))
            x_possible_moves += 1;
        if (can_move(map, pos, get_move_by_key(y_keys[i]), false))
            y_possible_moves += 1;
    }
    if (x_possible_moves <= 1 && y_possible_moves <= 1)
        return (FALSE);
    return (TRUE);
}