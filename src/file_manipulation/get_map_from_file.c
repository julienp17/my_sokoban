/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Get the map from file
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "file_manipulation.h"
#include "my_sokoban.h"
#include "my.h"
#include "map.h"
#include "usage.h"

map_t *get_map_from_file(char *filepath)
{
    char *file_buffer = get_file_buffer(filepath);
    map_t *map = NULL;

    if (!file_buffer || !is_valid_map(file_buffer))
        return (NULL);
    map = map_create_from_file_buffer(file_buffer);
    free(file_buffer);
    return (map);
}

map_t *map_create_from_file_buffer(char *file_buffer)
{
    map_t *map = malloc(sizeof(*map));

    map->map = my_str_to_word_array(file_buffer, '\n');
    map->org_map = my_strdup_str_array(map->map);
    map->max_row = my_str_array_len(map->map);
    map->max_col = my_get_max_word_len_str_array(map->map);
    map->player = get_initial_player_pos(map->map, PLAYER_CHAR);
    map->boxes = get_initial_entities_pos(map->map, BOX_CHAR);
    map->storage = get_initial_entities_pos(map->map, STORAGE_CHAR);
    return (map);
}

bool is_valid_map(char const *file_buffer)
{
    char const allowed_chars[] = "\n #XOP";
    unsigned int len = my_strlen(allowed_chars);
    unsigned int i = 0;
    unsigned int j = 0;

    while (file_buffer[i]) {
        j = 0;
        while (j < len && file_buffer[i] != allowed_chars[j])
            j++;
        if (j >= len) {
            my_puterr(UNKNOWN_CHAR_IN_MAP_ERR_MSG);
            return (false);
        }
        i++;
    }
    return (true);
}