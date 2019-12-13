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
    unsigned int my_count_char_str_array(char const **arr, char const to_count);
    unsigned int my_count_until_sep(char const *, char const);
    unsigned int my_strlen(char const *str);
    unsigned int my_str_array_len(char **arr);
    unsigned int my_get_max_word_len_str_array(char **arr);

    char **my_strdup_str_array(char **array);
    char **my_strcpy_str_array(char **dest, char **src);
    char **my_str_to_word_array(char *file_buffer, char const sep);
#endif
