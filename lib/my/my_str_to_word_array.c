/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Returns a word array with sep not included
*/
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "my.h"

char **my_str_to_word_array(char *file_buffer, char const sep)
{
    unsigned int nb_rows = my_count_char(file_buffer, sep) + 1;
    unsigned int nb_cols = 0;
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int k = 0;
    char **arr = malloc(sizeof(char *) * (nb_rows + 1));

    for (i = 0 ; i < nb_rows ; i = i + 1, k = k + 1) {
        nb_cols = my_count_until_sep(file_buffer, sep);
        arr[i] = malloc(sizeof(char) * (nb_cols + 1));
        for (j = 0 ; j < nb_cols ; j = j + 1, k = k + 1)
            arr[i][j] = file_buffer[k];
        arr[i][j] = '\0';
    }
    arr[i] = NULL;
    return (arr);
}
