/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Displays the map
*/

#include <stdbool.h>
#include <curses.h>
#include <string.h>
#include "map.h"

void play_game(map_t *map)
{
    int row = 0;
    int col = 0;
    int ch = 0;
    char *message = "bonjour";

    (void)map;
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    while ((ch = getch()) != 'q') {
        getmaxyx(stdscr, row, col);
        mvprintw(row / 2, (col - strlen(message) / 2) / 2, "%s", message);
        mvprintw(row-2,0,"This screen has %d rows and %d columns\n",row,col);
        if (row < 20 && col < 50)
            mvprintw(row / 2, (col - strlen(message) / 2) / 2, "Window too small!\n");
        refresh();
    }
    endwin();
}

void game_loop(map_t *map)
{
    (void)map;
    return;
}

void display_window(map_t *map)
{
    for (unsigned int i = 0 ; map->map[i] ; i++) {
        addstr(map->map[i]);
        addstr("\n");
    }
    refresh();
}