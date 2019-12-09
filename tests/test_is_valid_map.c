/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Unit tests for is_valid_map
*/

#include <stdbool.h>
#include <criterion/criterion.h>
#include "file_manipulation.h"

Test(is_valid_map, valid_map)
{
    char const file_buffer[] = "#####\n#PXO#\n#####";
    bool actual = false;
    bool expected = true;

    actual = is_valid_map(file_buffer);
    cr_assert_eq(actual, expected);
}

Test(is_valid_map, unknown_char)
{
    char const file_buffer[] = "#####\n#PaO#\n#####";
    bool actual = false;
    bool expected = false;

    actual = is_valid_map(file_buffer);
    cr_assert_eq(actual, expected);
}