/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Unit tests for map_is_valid
*/

#include <stdbool.h>
#include <criterion/criterion.h>
#include "file_manipulation.h"

Test(map_is_valid, valid_map)
{
    char const file_buffer[] = "#####\n#PXO#\n#####";
    bool actual = false;
    bool expected = true;

    actual = map_is_valid(file_buffer);
    cr_assert_eq(actual, expected);
}

Test(map_is_valid, unknown_char)
{
    char const file_buffer[] = "#####\n#PaO#\n#####";
    bool actual = false;
    bool expected = false;

    actual = map_is_valid(file_buffer);
    cr_assert_eq(actual, expected);
}