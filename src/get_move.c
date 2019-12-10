/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Returns a movement structure based off a key
*/

#include <curses.h>
#include "move.h"

move_t *get_move_by_key(int key)
{
    move_t *moves[] = {
        {KEY_LEFT, -1, 0, &move_left},
        {KEY_RIGHT, 1, 0, &move_right},
        {KEY_UP, 0, -1, &move_up},
        {KEY_DOWN, 0, 1, &move_down},
        NULL
    };
    for (unsigned int i = 0 ; moves[i] ; i++)
        if (moves[i]->key == key)
            return (moves);
    return (NULL);
}

void move_left(pos_t *pos)
{
    pos->x--;
}

void move_right(pos_t *pos)
{
    pos->x++;
}

void move_up(pos_t *pos)
{
    pos->y--;
}

void move_down(pos_t *pos)
{
    pos->y++;
}