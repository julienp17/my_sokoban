/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** get_pos
*/

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include "my_sokoban.h"
#include "pos.h"
#include "my.h"

pos_t *pos_create(int x, int y)
{
    pos_t *pos = malloc(sizeof(*pos));

    pos->x = x;
    pos->y = y;
    return (pos);
}

bool is_on_same_pos(pos_t *pos_1, pos_t *pos_2)
{
    return (pos_1->x == pos_2->x && pos_1->y == pos_2->y);
}