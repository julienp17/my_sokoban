/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Handles the player movement
*/

#include <stddef.h>
#include <curses.h>
#include "map.h"
#include "pos.h"
#include "move.h"

pos_t *get_initial_player_pos(char **map, char player_symbol)
{
    pos_t *player_pos = malloc(sizeof(pos_t *));

    for (unsigned int i = 0 ; map[i] ; i++) {
        for (unsigned int j = 0 ; map[i][j] ; j++)
            if (map[i][j] == player_symbol) {
                player_pos->y = i;
                player_pos->x = j;
            }
    }
    return (player_pos);
}

void check_player_move(int key, map_t *map, pos_t *player_pos)
{
    
}

