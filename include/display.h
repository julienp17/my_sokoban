/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Header file for displaying the game
*/

#ifndef DISPLAY_H_
    #define DISPLAY_H_

    #include "map.h"
    #include "pos.h"

    void display_map(map_t *map, pos_t *player_pos);
    void display_cursor_as_player(pos_t *player_pos);
    void display_center_message(char const *message);
#endif