/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Header file for movement structure
*/

#ifndef MOVE_H_
    #define MOVE_H_

    #include <stdbool.h>
    #include "map.h"
    #include "pos.h"

    typedef struct movement {
        int key;
        int x_offset;
        int y_offset;
    } move_t;

    bool is_movement_key(int key);
    move_t *get_move_by_key(int key);

    bool can_move(map_t *map, pos_t *target, move_t *direction, bool is_player);
    bool target_is_box(pos_t *target, pos_t **boxes);
    bool is_off_limits(pos_t *pos, map_t *map);

    void move_player(map_t *map, move_t *direction);
    void move_box(pos_t *box_pos, pos_t **boxes, move_t *direction);
#endif