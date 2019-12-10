/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Header file for pos struct
*/

#ifndef POS_H_
    #define POS_H_

    typedef struct position {
        unsigned int x;
        unsigned int y;
    } pos_t;

    void get_initial_player_pos(char **map, pos_t *, char player_symbol);
#endif