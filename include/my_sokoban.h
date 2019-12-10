/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Header file for my_sokoban
*/

#ifndef MY_SOKOBAN_H
    #define MY_SOKOBAN_H

    #define WALL_CHAR       '#'
    #define PLAYER_CHAR     'P'
    #define TARGET_CHAR     'O'
    #define SPACE_CHAR      ' '

    void init_game(void);
    void display_window(map_t *map);
    void game_loop(map_t *map);
#endif