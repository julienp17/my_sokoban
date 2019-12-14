/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Header file for pos struct
*/

#ifndef POS_H_
    #define POS_H_

    typedef struct position {
        int x;
        int y;
    } pos_t;

    pos_t *pos_create(int x, int y);
    bool is_on_same_pos(pos_t *pos_1, pos_t *pos_2);
    pos_t *get_box_pos(pos_t *target, pos_t **boxes);
    pos_t *get_initial_player_pos(char **map, char symbol);
    pos_t **get_initial_entities_pos(char **map, char symbol);
#endif