/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Count the number of times the given char appears in a 2d array
*/

unsigned int my_count_char_str_array(char **arr, char const to_count)
{
    unsigned int count = 0;

    for (unsigned int i = 0 ; arr[i] ; i++)
        for (unsigned int j = 0 ; arr[i][j] ; j++)
            if (arr[i][j] == to_count)
                count++;
    return (count);
}