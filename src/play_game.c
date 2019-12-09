/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Displays the map
*/

#include <stdbool.h>
#include <stdlib.h>
#include <curses.h>
#include "map.h"
#include "my_sokoban.h"
#include "pos.h"

void init_game(void);
void display_window(map_t *map);
void game_loop(map_t *map, pos_t *player_pos);
pos_t *get_initial_player_pos(char **map, char player_symbol);

void play_game(map_t *map)
{
    pos_t *player_pos = get_initial_player_pos(map->map, PLAYER_CHAR);

    init_game();
    game_loop(map, player_pos);
    endwin();
}

void init_game(void)
{
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
}

pos_t *get_initial_player_pos(char **map, char player_symbol)
{
    pos_t *player_pos = malloc(sizeof(pos_t *));

    for (unsigned int i = 0 ; map[i] ; i++) {
        for (unsigned int j = 0 ; map[i][j] ; j++)
            if (map[i][j] == player_symbol) {
                player_pos->y = i;
                player_pos->x = j;
            }
    }
    return (player_pos);
}

void game_loop(map_t *map, pos_t *player_pos)
{
    int ch = 0;

    while (ch != 'q' && ch != 27) {
        display_window(map);
        ch = getch();
        if (ch == KEY_LEFT) {
            map->map[player_pos->y][player_pos->x] = SPACE_CHAR;
            player_pos->x--;
            map->map[player_pos->y][player_pos->x] = PLAYER_CHAR;
        }
        clear();
    }
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