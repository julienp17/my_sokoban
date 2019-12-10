/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Header file for libmy.a
*/

#ifndef MY_H_
    #define MY_H_

    void my_putchar(char);
    void my_putstr(char *);
    void my_puterr(char *);

    int my_strcmp(char const *, char const *);
    unsigned int my_count_char(char const *, char const);
    unsigned int my_count_char_2D_array(char const **arr, char const to_count);
    unsigned int my_count_until_sep(char const *, char const);
    unsigned int my_strlen(char const *str);

    char **my_strdup_2D_array(char **array);
    char **my_strcpy_2D_array(char **dest, char const **src);
#endif
