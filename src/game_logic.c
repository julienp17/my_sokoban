/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Handle the game logic
*/

#include <stdbool.h>
#include <stdlib.h>
#include <curses.h>
#include "my_sokoban.h"
#include "map.h"
#include "pos.h"
#include "move.h"
#include "my.h"

static void update_max_moves(map_t *map, pos_t *box_pos,
                            unsigned int *max_moves);

bool game_should_go_on(int key, map_t *map)
{
    if (key == QUIT_KEY || key == ESCAPE_KEY)
        return (FALSE);
    if (no_boxes_can_be_moved(map))
        return (FALSE);
    if (my_count_char_2D_array((char const **)(map->map), TARGET_CHAR) == 0)
        return (FALSE);
    return (TRUE);
}

bool no_boxes_can_be_moved(map_t *map)
{
    pos_t *box_pos = malloc(sizeof(*box_pos));
    unsigned int max_moves = 0;

    for (unsigned int row = 0 ; map->map[row] ; row++) {
        for (unsigned int col = 0 ; map->map[row][col] ; col++) {
            if (map->map[row][col] == BOX_CHAR) {
                box_pos->y = row;
                box_pos->x = col;
                update_max_moves(map, box_pos, &max_moves);
            }
        }
    }
    free(box_pos);
    return ((max_moves <= 2) ? TRUE : FALSE);
}

static void update_max_moves(map_t *map, pos_t *box_pos,
                            unsigned int *max_moves)
{
    unsigned int moves = get_box_possible_moves(map, box_pos);

    if (moves > (*max_moves))
        (*max_moves) = moves;
}

unsigned int get_box_possible_moves(map_t *map, pos_t *pos)
{
    int keys[] = {KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN, 0};
    unsigned int possible_moves = 0;

    for (unsigned int i = 0 ; keys[i] != 0 ; i++)
        if (can_move(map, pos, get_move_by_key(keys[i])))
            possible_moves++;
    return (possible_moves);
}