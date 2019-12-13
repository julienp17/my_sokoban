/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Get the map from file
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "file_manipulation.h"
#include "my.h"
#include "map.h"
#include "usage.h"

map_t *get_map_from_file(char *filepath)
{
    char *file_buffer = get_file_buffer(filepath);
    map_t *map = NULL;

    if (!file_buffer || !is_valid_map(file_buffer))
        return (NULL);
    map = malloc(sizeof(*map));
    map->map = my_str_to_word_array(file_buffer, '\n');
    map->org_map = my_strdup_str_array(map->map);
    map->max_row = my_str_array_len(map->map);
    map->max_col = my_get_max_word_len_str_array(map->map);
    free(file_buffer);
    return (map);
}

char *get_file_buffer(char *filepath)
{
    int fd = 0;
    unsigned int file_size = get_file_size(filepath);
    char *buffer = malloc(sizeof(char) * (file_size + 1));

    if ((fd = open(filepath, O_RDONLY)) == -1) {
        my_puterr(OPEN_FAILURE_MSG);
        return (NULL);
    }
    if (read(fd, buffer, file_size) == -1) {
        my_puterr(READ_FAILURE_MSG);
        return (NULL);
    }
    buffer[file_size] = '\0';
    close(fd);
    return (buffer);
}

unsigned int get_file_size(char const *filepath)
{
    struct stat stats;

    if (stat(filepath, &stats) != 0)
        return (-1);
    return (stats.st_size);
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