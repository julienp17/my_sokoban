/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Header file for my_sokoban
*/

#ifndef MY_SOKOBAN_H
    #define MY_SOKOBAN_H

    #include <stdbool.h>
    #include <curses.h>
    #include "map.h"
    #include "pos.h"

    #define WALL_CHAR       '#'
    #define PLAYER_CHAR     'P'
    #define BOX_CHAR        'X'
    #define TARGET_CHAR     'O'
    #define SPACE_CHAR      ' '

    #define RESET_KEY       ' '
    #define QUIT_KEY        'q'
    #define ESCAPE_KEY      27

    int play_game(map_t *map);
    void init_game(void);
    int game_loop(map_t *map);
    void check_player_move(int key, map_t *map);
    void check_reset(int key, map_t *map);

    void display_map(map_t *map);
    void display_cursor_as_player(pos_t *player_pos);
    void display_boxes(pos_t **boxes);
    void display_center_message(char const *message);

    int game_should_go_on(int key, map_t *map);
    bool boxes_can_be_moved(map_t *map);
    bool check_box_possible_moves(map_t *map, pos_t *pos);
    unsigned int get_box_possible_moves(map_t *map, pos_t *pos);
#endif