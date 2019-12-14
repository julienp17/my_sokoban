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

int game_should_go_on(int key, map_t *map)
{
    if (key == QUIT_KEY || key == ESCAPE_KEY)
        return (0);
    // if (!boxes_can_be_moved(map))
    //     return (0);
    if (my_count_char_str_array((map->map), TARGET_CHAR) == 0)
        return (1);
    return (42);
}

// bool boxes_can_be_moved(map_t *map)
// {
//     pos_t *box_pos = malloc(sizeof(*box_pos));
//     bool can_move = false;

//     for (unsigned int row = 0 ; map->map[row] && !can_move; row++) {
//         for (unsigned int col = 0 ; map->map[row][col] && !can_move; col++) {
//             if (map->map[row][col] == BOX_CHAR) {
//                 box_pos->y = row;
//                 box_pos->x = col;
//                 can_move = check_box_possible_moves(map, box_pos);
//             }
//         }
//     }
//     free(box_pos);
//     return (can_move);
// // }

// bool check_box_possible_moves(map_t *map, pos_t *pos)
// {
//     int x_keys[] = {KEY_LEFT, KEY_RIGHT, 0};
//     int y_keys[] = {KEY_UP, KEY_DOWN, 0};
//     int x_possible_moves = 0;
//     int y_possible_moves = 0;

//     for (unsigned int i = 0 ; x_keys[i] != 0 ; i++) {
//         if (box_can_move(map, pos, get_move_by_key(x_keys[i])))
//             x_possible_moves += 1;
//         if (box_can_move(map, pos, get_move_by_key(y_keys[i])))
//             y_possible_moves += 1;
//     }
//     if (x_possible_moves <= 1 && y_possible_moves <= 1)
//         return (FALSE);
//     return (TRUE);
// }