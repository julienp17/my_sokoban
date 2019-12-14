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

void move_player(map_t *map, move_t *direction)
{
    pos_t *box_pos = NULL;

    map->player->x += direction->x_offset;
    map->player->y += direction->y_offset;
    box_pos = get_box_pos(map->player, map->boxes);
    if (box_pos) {
        box_pos->x += direction->x_offset;
        box_pos->y += direction->y_offset;
    }
}