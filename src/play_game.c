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
#include "move.h"

void play_game(map_t *map)
{
    init_game();
    game_loop(map);
    endwin();
}

void init_game(void)
{
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
}

void game_loop(map_t *map)
{
    pos_t *player_pos = get_initial_player_pos(map->map, PLAYER_CHAR);
    int key = 0;

    map->map[player_pos->y][player_pos->x] = SPACE_CHAR;
    while (key != 'q' && key != 27) {
        display_map(map, player_pos);
        key = getch();
        check_player_move(key, map, player_pos);
    }
    free(player_pos);
}