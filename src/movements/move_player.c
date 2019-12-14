/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Handles the player movement
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <curses.h>
#include "map.h"
#include "pos.h"
#include "move.h"
#include "my_sokoban.h"
#include "move.h"

void move_player(pos_t *player, pos_t **boxes, move_t *direction)
{
    pos_t *box_pos = NULL;

    player->x += direction->x_offset;
    player->y += direction->y_offset;
    box_pos = get_box_pos(player, boxes);
    if (box_pos)
        move_player(box_pos, boxes, direction);
}