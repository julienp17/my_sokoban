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

map_t *get_map_from_file(char *filepath)
{
    char *file_buffer = get_file_buffer(filepath);

    if (!file_buffer || !is_valid_map(file_buffer))
        return (NULL);
    return (create_map_from_file_buffer(file_buffer));
}

map_t *create_map_from_file_buffer(char *file_buffer)
{
    map_t *map = malloc(sizeof(*map));
    map->nb_cols = my_count_until_sep(file_buffer, '\n');
    map->nb_rows = my_count_char(file_buffer, '\n') + 1;
    map->map = malloc(sizeof(char *) * (map->nb_rows + 1));
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int k = 0;

    for (i = 0 ; i < map->nb_rows ; i++, k++) {
        map->map[i] = malloc(sizeof(char) * (map->nb_cols + 1));
        for (j = 0 ; j < map->nb_cols ; j++, k++) {
            map->map[i][j] = file_buffer[k];
        }
        map->map[i][j] = '\0';
    }
    map->map[i] = NULL;
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
        if (j >= len)
            return (false);
        i++;
    }
    return (true);
}