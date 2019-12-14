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
#include "usage.h"
#include "my.h"

int play_game(map_t *map)
{
    int exit_code = 0;

    init_game();
    exit_code = game_loop(map);
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

int game_loop(map_t *map)
{
    int key = 0;
    int exit_code = 0;

    while ((exit_code = game_should_go_on(key, map)) == 42) {
        if (terminal_is_too_small(map)) {
            clear();
            display_center_message(TERM_TOO_SMALL_MSG);
            key = getch();
        } else {
            display_map(map);
            key = getch();
            check_player_move(key, map);
            check_reset(key, map);
        }
    }
    return (exit_code);
}

void check_player_move(int key, map_t *map)
{
    move_t *direction = NULL;

    if (!is_movement_key(key))
        return;
    direction = get_move_by_key(key);
    if (can_move(map, map->player, direction, true))
        move_player(map, direction);
    free(direction);
}

void check_reset(int key, map_t *map)
{
    if (key == RESET_KEY) {
        map->map = my_strcpy_str_array(map->map, map->org_map);
        map->player = get_initial_player_pos(map->map, PLAYER_CHAR);
        map->boxes = get_initial_entities_pos(map->map, BOX_CHAR);
    }
}