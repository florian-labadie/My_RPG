/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-amazed-baptiste.blambert
** File description:
** test_amazed
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout() ;
    cr_redirect_stderr() ;
    cr_redirect_stdin();
}

Test (amazed, check_amzed_is_ok, . init = redirect_all_std)
{
    int result = 0;
    FILE *file = cr_get_redirected_stdin();
    char *str = "9\n##start\n0 0 0\n1 7 5\n2 15 20\n3 15 66\n4 15 66\n##end\n5 15 66\n0-1\n0-2\n1-3\n2-4\n3-5\n4-5\n4-1\n2-5\n";

    fwrite(str, strlen(str), 1, file);
    fclose(file);
    result = launch_amazed();
    cr_assert_eq(result, 0);
}
