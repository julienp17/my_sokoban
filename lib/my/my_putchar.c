/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Write a char to standard output
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}