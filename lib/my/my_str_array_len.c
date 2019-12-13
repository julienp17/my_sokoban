/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Returns the nuber of rows in a string array
*/

unsigned int my_str_array_len(char **arr)
{
    unsigned int len = 0;

    while (arr[len])
        len++;
    return (len);
}