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

    pos_t *get_initial_player_pos(char **map, char player_symbol);
#endif