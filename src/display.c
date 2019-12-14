/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Functions to display the game
*/

#include <curses.h>
#include "my_sokoban.h"
#include "my.h"

void display_map(map_t *map)
{
    clear();
    for (unsigned int i = 0 ; map->map[i] ; i++) {
        addstr(map->map[i]);
        addstr("\n");
    }
    display_boxes(map->boxes);
    display_cursor_as_player(map->player);
    refresh();
}

void display_cursor_as_player(pos_t *player_pos)
{
    move(player_pos->y, player_pos->x);
    addch(PLAYER_CHAR);
    move(player_pos->y, player_pos->x);
}

void display_boxes(pos_t **boxes)
{
    for (unsigned int i = 0 ; boxes[i] ; i = i + 1) {
        move(boxes[i]->y, boxes[i]->x);
        addch(BOX_CHAR);
    }
}

void display_center_message(char const *message)
{
    unsigned int row = 0;
    unsigned int col = 0;

    getmaxyx(stdscr, row, col);
    mvprintw(row / 2, (col - my_strlen(message)) / 2, "%s", message);
    refresh();
}