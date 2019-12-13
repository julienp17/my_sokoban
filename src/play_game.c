/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Displays the map
*/

#include <stdbool.h>
#include <stdlib.h>
#include <curses.h>
#include "display.h"
#include "map.h"
#include "my_sokoban.h"
#include "pos.h"
#include "move.h"
#include "usage.h"
#include "my.h"

int play_game(map_t *map)
{
    int exit_code = 0;
    pos_t *player_pos = malloc(sizeof(*player_pos));
    char **org_map = my_strdup_str_array(map->map);

    set_initial_player_pos(map->map, player_pos, PLAYER_CHAR);
    map->map[player_pos->y][player_pos->x] = SPACE_CHAR;
    init_game();
    exit_code = game_loop(map, org_map, player_pos);
    endwin();
    return (exit_code);
}

void init_game(void)
{
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
}

int game_loop(map_t *map, char **org_map, pos_t *player_pos)
{
    int key = 0;

    while (game_should_go_on(key, map)) {
        if (terminal_is_too_small(map)) {
            clear();
            display_center_message(TERM_TOO_SMALL_MSG);
            key = getch();
        } else {
            display_map(map, player_pos);
            key = getch();
            check_player_move(key, map, player_pos);
            check_reset(key, map, org_map, player_pos);
        }
    }
    free(player_pos);
    return (!boxes_can_be_moved(map));
}

void check_reset(int key, map_t *map, char **org_map, pos_t *player_pos)
{
    if (key == RESET_KEY) {
        map->map = my_strcpy_str_array(map->map, (char const **)org_map);
        set_initial_player_pos(org_map, player_pos, PLAYER_CHAR);
        map->map[player_pos->y][player_pos->x] = SPACE_CHAR;
    }
}