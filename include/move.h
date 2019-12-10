/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Header file for movement structure
*/

#ifndef MOVE_H_
    #define MOVE_H_

    #include "map.h"
    #include "pos.h"

    typedef struct movement {
        int key;
        int x_offset;
        int y_offset;
    } move_t;

    move_t *get_move_by_key(int key);
    bool is_movement_key(int key);
    bool can_move(map_t *map, pos_t *pos, move_t *move);
    bool is_off_limits(pos_t *pos, map_t *map);
    void check_player_move(int key, map_t *map, pos_t *player_pos);
    void move_player(char **map, pos_t *player_pos, move_t *direction);
    void move_box(char **map, pos_t *box_pos, move_t *direction);
#endif