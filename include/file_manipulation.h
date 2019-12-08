/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Header file for file manipulation
*/

#ifndef FILE_MANIPULATION_H_
    #define FILE_MANIPULATION_H_

    #include <stdbool.h>

    #define OPEN_FAILURE_MSG        "File cannot be opened\n"
    #define READ_FAILURE_MSG        "File cannot be read\n"

    char **get_map_from_file(char *filepath);
    char *get_file_buffer(char *filepath);
    unsigned int get_file_size(char const *filepath);
    char **create_map_from_file_buffer(char *file_buffer);
    bool map_is_valid(char const *file_buffer);
#endif