/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Returns the length of the longest string in a string array
*/

#include "my.h"

unsigned int my_get_max_word_len_str_array(char **arr)
{
    unsigned int len = 0;
    unsigned int max_len = 0;

    for (unsigned int i = 0 ; arr[i] ; i++) {
        len = my_strlen(arr[i]);
        if (len > max_len)
            max_len = len;
    }
    return (max_len);
}