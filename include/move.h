/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Header file for movement structure
*/

#ifndef MOVE_H_
    #define MOVE_H_

    #include "pos.h"

    typedef struct movement {
        int key;
        int x_offset;
        int y_offset;
        void (*movement)(pos_t *);
    } move_t;

    void move_left(pos_t *pos);
    void move_right(pos_t *pos);
    void move_up(pos_t *pos);
    void move_down(pos_t *pos);
#endif