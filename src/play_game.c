/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Displays the map
*/

#include <stdlib.h>
#include <curses.h>
#include "map.h"
#include "my_sokoban.h"
#include "pos.h"

void init_game(void);
void display_window(map_t *map);
void game_loop(map_t *map);
pos_t *get_initial_player_pos(char **map, char player_symbol);

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
    int ch = 0;

    map->map[player_pos->y][player_pos->x] = SPACE_CHAR;
    while (ch != 'q' && ch != 27) {
        display_window(map);
        move(player_pos->y, player_pos->x);
        addch(PLAYER_CHAR);
        move(player_pos->y, player_pos->x);
        ch = getch();
        if (ch == KEY_LEFT && player_pos->x > 0)
            player_pos->x--;
        if (ch == KEY_RIGHT && player_pos->x < map->nb_cols - 1)
            player_pos->x++;
        if (ch == KEY_DOWN && player_pos->y < map->nb_rows - 1)
            player_pos->y++;
        if (ch == KEY_UP && player_pos->y > 0)
            player_pos->y--;
        clear();
    }
    return;
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

void display_window(map_t *map)
{
    for (unsigned int i = 0 ; map->map[i] ; i++) {
        addstr(map->map[i]);
        addstr("\n");
    }
    refresh();
}