/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Unit tests for check_args
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "usage.h"
#include "my.h"

Test(check_args, not_enough_arguments, .init = cr_redirect_stderr)
{
    int ac = 1;
    char *av[] = {"./my_sokoban"};
    int actual_error_code = 0;
    int expected_error_code = MY_EXIT_FAILURE;
    char *expected_stdout = BAD_NB_ARGS_ERR_MSG USAGE;

    actual_error_code = check_args(ac, av);
    cr_assert_eq(actual_error_code, expected_error_code);
    cr_assert_stderr_eq_str(expected_stdout);
}

Test(check_args, too_many_arguments, .init = cr_redirect_stderr)
{
    int ac = 4;
    char *av[] = {"./my_sokoban", "a", "b", "c"};
    int actual_error_code = 0;
    int expected_error_code = MY_EXIT_FAILURE;

    actual_error_code = check_args(ac, av);
    cr_assert_eq(actual_error_code, expected_error_code);
    cr_assert_stderr_eq_str(BAD_NB_ARGS_ERR_MSG USAGE);
}

Test(check_args, help_option_short, .init = cr_redirect_stdout)
{
    int ac = 2;
    char *av[] = {"./my_sokoban", "-h"};
    int actual_error_code = 0;
    int expected_error_code = MY_EXIT_OPTION;

    actual_error_code = check_args(ac, av);
    cr_assert_eq(actual_error_code, expected_error_code);
    cr_assert_stdout_eq_str(USAGE);
}

Test(check_args, help_option_long, .init = cr_redirect_stdout)
{
    int ac = 2;
    char *av[] = {"./my_sokoban", "--help"};
    int actual_error_code = 0;
    int expected_error_code = MY_EXIT_OPTION;

    actual_error_code = check_args(ac, av);
    cr_assert_eq(actual_error_code, expected_error_code);
    cr_assert_stdout_eq_str(USAGE);
}

Test(check_args, correct_arguments)
{
    int ac = 2;
    char *av[] = {"./my_sokoban", "my_map.txt"};
    int actual_error_code = 0;
    int expected_error_code = MY_EXIT_SUCCESS;

    actual_error_code = check_args(ac, av);
    cr_assert_eq(actual_error_code, expected_error_code);
}