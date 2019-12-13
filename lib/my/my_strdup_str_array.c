/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Returns a duplicate of a 2d char array
*/

#include <stddef.h>
#include <stdlib.h>

char **my_strdup_str_array(char **array)
{
    unsigned int row = 0;
    unsigned int col = 0;
    char **dup_array = NULL;

    for (row = 0 ; array[row] ; row++);
    dup_array = malloc(sizeof(char *) * (row + 1));
    for (row = 0 ; array[row] ; row++) {
        for (col = 0 ; array[row][col] ; col++);
        dup_array[row] = malloc(sizeof(char) * (col + 1));
        for (col = 0 ; array[row][col] ; col++)
            dup_array[row][col] = array[row][col];
        dup_array[row][col] = '\0';
    }
    dup_array[row] = NULL;
    return (dup_array);
}