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

void get_initial_player_pos(char **map, pos_t *player_pos, char player_symbol)
{
    for (unsigned int i = 0 ; map[i] ; i++) {
        for (unsigned int j = 0 ; map[i][j] ; j++) {
            if (map[i][j] == player_symbol) {
                player_pos->y = i;
                player_pos->x = j;
            }
        }
    }
}

void check_player_move(int key, map_t *map, pos_t *player_pos)
{
    move_t *direction = NULL;

    if (!is_movement_key(key))
        return;
    direction = get_move_by_key(key);
    if (can_move(map, player_pos, direction))
        move_player(map->map, player_pos, direction);
    free(direction);
}

void move_player(char **map, pos_t *player_pos, move_t *direction)
{
    char target_char = 0;

    player_pos->x += direction->x_offset;
    player_pos->y += direction->y_offset;
    target_char = map[player_pos->y][player_pos->x];
    if (target_char == BOX_CHAR)
        move_box(map, player_pos, direction);
}

void move_box(char **map, pos_t *box_pos, move_t *direction)
{
    unsigned int nb_boxes = 0;
    char target_char = map[box_pos->y][box_pos->x];

    while (target_char == BOX_CHAR) {
        nb_boxes++;
        box_pos->x += direction->x_offset;
        box_pos->y += direction->y_offset;
        target_char = map[box_pos->y][box_pos->x];
    }
    for (unsigned int i = 0 ; i < nb_boxes ; i++) {
        map[box_pos->y][box_pos->x] = BOX_CHAR;
        box_pos->x -= direction->x_offset;
        box_pos->y -= direction->y_offset;
        map[box_pos->y][box_pos->x] = SPACE_CHAR;
    }
}