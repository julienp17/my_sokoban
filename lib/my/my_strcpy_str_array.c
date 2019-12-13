/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Copies a 2d array into another
*/

#include <stddef.h>

char **my_strcpy_str_array(char **dest, char const **src)
{
    unsigned int row = 0;
    unsigned int col = 0;

    while (src[row]) {
        col = 0;
        while (src[row][col]) {
            dest[row][col] = src[row][col];
            col++;
        }
        dest[row][col] = '\0';
        row++;
    }
    dest[row] = NULL;
    return (dest);
}