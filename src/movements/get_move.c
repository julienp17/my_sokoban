/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Returns a movement structure based off a key
*/

#include <stdlib.h>
#include <curses.h>
#include "move.h"

move_t *get_move_by_key(int key)
{
    move_t *move = malloc(sizeof(*move));
    move_t moves[] = {
        {KEY_LEFT, -1, 0},
        {KEY_RIGHT, 1, 0},
        {KEY_UP, 0, -1},
        {KEY_DOWN, 0, 1},
        {0, 0, 0}
    };

    for (unsigned int i = 0 ; moves[i].key != 0 ; i++) {
        if (moves[i].key == key) {
            move->key = moves[i].key;
            move->x_offset = moves[i].x_offset;
            move->y_offset = moves[i].y_offset;
        }
    }
    return (move);
}