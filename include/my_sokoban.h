/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Header file for my_sokoban
*/

#ifndef MY_SOKOBAN_H
    #define MY_SOKOBAN_H

    #include <curses.h>
    #include "map.h"
    #include "pos.h"

    #define WALL_CHAR       '#'
    #define PLAYER_CHAR     'P'
    #define BOX_CHAR        'X'
    #define TARGET_CHAR     'O'
    #define SPACE_CHAR      ' '
    #define RESET_KEY       ' '

    void play_game(map_t *map);
    void init_game(void);
    void game_loop(map_t *map, char **org_map, pos_t *player_pos);
    void check_reset(int key, map_t *map, char **org_map, pos_t *player_pos);
#endif