/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Count the number of times the given char appears in a 2d array
*/

unsigned int my_count_char_2D_array(char const **str, char const to_count)
{
    unsigned int count = 0;

    for (unsigned int i = 0 ; str[i] ; i++)
        for (unsigned int j = 0 ; str[i][j] ; j++)
            if (str[i][j] == to_count)
                count++;
    return (count);
}