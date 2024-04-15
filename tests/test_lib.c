/*
** EPITECH PROJECT, 2023
** test
** File description:
** printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout() ;
    cr_redirect_stderr() ;
}

Test (lib, my_putchar_check, . init = redirect_all_std)
{
    my_putchar('A');
    cr_assert_stdout_eq_str("A");
}

Test (lib, my_putstr_check, . init = redirect_all_std)
{
    my_putstr("Hello");
    cr_assert_stdout_eq_str("Hello");
}

Test (lib, my_alpha_num_check, . init = redirect_all_std)
{
    char str[6] = "Hell0";
    int ret = 0;

    for (int i = 0; str[i] != '\0'; i++)
        ret = alpha_num(str[i]);
    cr_assert_eq(ret, OK);
}

Test (lib, my_alpha_num_err, . init = redirect_all_std)
{
    char str[6] = "H£l1o";
    int ret = 0;

    ret = alpha_num(str[1]);
    cr_assert_eq(ret, KO);
}

Test (lib, my_alpha_num_NULL, . init = redirect_all_std)
{
    char c = '\0';
    int ret = 0;

    ret = alpha_num(c);
    cr_assert_eq(ret, KO);
}

Test (lib, my_num_check, . init = redirect_all_std)
{
    char str[6] = "01287";
    int ret = 0;

    for (int i = 0; str[i] != '\0'; i++)
        ret = numeric(str[i]);
    cr_assert_eq(ret, OK);
}

Test (lib, my_num_err, . init = redirect_all_std)
{
    char str[6] = "1892O";
    int ret = 0;

    for (int i = 0; str[i] != '\0'; i++)
        ret = numeric(str[i]);
    cr_assert_eq(ret, KO);
}

Test (lib, my_num_NULL, . init = redirect_all_std)
{
    char c = '\0';
    int ret = 0;

    ret = numeric(c);
    cr_assert_eq(ret, KO);
}

Test (lib, my_alpha_check, . init = redirect_all_std)
{
    char str[6] = "Hello";
    int ret = 0;

    for (int i = 0; str[i] != '\0'; i++)
        ret = alphabetic(str[i]);
    cr_assert_eq(ret, OK);
}

Test (lib, my_alpha_err, . init = redirect_all_std)
{
    char str[6] = "Hel1o";
    int ret = 0;

    ret = alphabetic(str[3]);
    cr_assert_eq(ret, KO);
}

Test (lib, my_alpha_NULL, . init = redirect_all_std)
{
    char c = '\0';
    int ret = 0;

    ret = alphabetic(c);
    cr_assert_eq(ret, KO);
}

Test (lib, my_arraydup_len_NULL, . init = redirect_all_std)
{
    char **array = NULL;
    char **ret = NULL;
    int retlen = 0;

    
    ret = my_arraydup((char const *const *)array);
    retlen = my_arraylen((char const *const *)array);
    cr_assert_eq(ret, NULL);
    cr_assert_eq(retlen, 0);
}

Test (lib, my_arraydup, . init = redirect_all_std)
{
    char **array = malloc(sizeof(char*) * 2);
    char **ret = NULL;

    array[0] = "Hello";
    array[1] = "World";
    ret = my_arraydup((char const *const *)array);
    cr_assert_neq(ret, NULL);
    cr_assert_str_eq(ret[0], "Hello");
    cr_assert_str_eq(ret[1], "World");
}

Test (lib, my_getnbr, . init = redirect_all_std)
{
    char str[] = "12x";
    int ret = 0;

    ret = my_getnbr(str);
    cr_assert_eq(ret, 12);
}

Test (lib, my_getnbr_no_num, . init = redirect_all_std)
{
    char str[] = "Anything";
    int ret = 0;

    ret = my_getnbr(str);
    cr_assert_eq(ret, OK);
}

Test (lib, my_put_errchar, . init = redirect_all_std)
{
    my_put_errchar('I');
    cr_assert_stderr_eq_str("I");
}

Test (lib, my_put_errstr, . init = redirect_all_std)
{
    my_put_errstr("Invalid");
    cr_assert_stderr_eq_str("Invalid");
}

Test (lib, my_putnbr, . init = redirect_all_std)
{
    int nb = -1829203;
    int ret = 0;

    ret = my_put_nbr(nb);
    cr_assert_eq(ret, 8);
    cr_assert_stdout_eq_str("-1829203");
}

Test (lib, my_strcat_check, . init = redirect_all_std)
{
    char *str = "Hello,";
    char *ret = " World";

    str = my_strcat(str, ret);
    my_putstr(str);
    cr_assert_neq(str, NULL);
    cr_assert_stdout_eq_str("Hello, World");
}

Test (lib, my_strcat_NULL, . init = redirect_all_std)
{
    char *str = "Hello,";
    char *ret = NULL;

    str = my_strcat(str, ret);
    cr_assert_eq(str, NULL);
}

Test (lib, my_strcmp_check, . init = redirect_all_std)
{
    char *str = "Hello";
    char *cmp = "Hello";
    int ret = 0;

    ret = my_strcmp(str, cmp);
    cr_assert_eq(ret, 0);
}

Test (lib, my_strcmp_not_same, . init = redirect_all_std)
{
    char *str = "Hello,";
    char *cmp = "Goodbye";
    char *str2 = "Allo,";
    char *cmp2 = "Goodbye";
    int ret = 0;
    int ret2 = 0;

    ret = my_strcmp(str, cmp);
    ret2 = my_strcmp(str2, cmp2);
    cr_assert_eq(ret, -1);
    cr_assert_eq(ret2, -1);
}

Test (lib, my_strcmp_null, . init = redirect_all_std)
{
    char *str = "Hello,";
    char *cmp = NULL;
    int ret = 0;

    ret = my_strcmp(str, cmp);
    cr_assert_eq(ret, 84);
}

Test (lib, my_strcpy_null, . init = redirect_all_std)
{
    char *str = "Hello,";
    char *dest = NULL;
    char *ret = 0;

    ret = my_strcpy(str, dest);
    cr_assert_eq(ret, NULL);
}

Test (lib, my_strdup_null, . init = redirect_all_std)
{
    char *str = NULL;
    char *ret = 0;

    ret = my_strdup(str);
    cr_assert_eq(ret, NULL);
}

Test (lib, my_strlen, . init = redirect_all_std)
{
    char *str = "Hello";
    int ret = 0;

    ret = my_strlen(str);
    cr_assert_eq(ret, 5);
}

Test (lib, my_strlen_null, . init = redirect_all_std)
{
    char *str = NULL;
    int ret = 0;

    ret = my_strlen(str);
    cr_assert_eq(ret, 0);
}

Test (lib, my_strtok, . init = redirect_all_std)
{
    char str[14] = "Hello, World!";
    char *ret = NULL;

    ret = my_strtok(str, ",");
    my_putstr(ret);
    cr_assert_stdout_eq_str("Hello");
}

Test (lib, my_strtok_next, . init = redirect_all_std)
{
    char str[14] = "Hello, World!";
    char *ret = NULL;

    my_strtok(str, ",");
    ret = my_strtok(NULL, "!");
    my_putstr(ret);
    cr_assert_stdout_eq_str(" World");
}

Test (lib, my_strtok_end, . init = redirect_all_std)
{
    char str[14] = "Hello, World!";
    char *ret = NULL;

    my_strtok(str, ",");
    ret = my_strtok(NULL, "");
    my_putstr(ret);
    cr_assert_stdout_eq_str(" World!");
}

Test (lib, my_strtok_null, . init = redirect_all_std)
{
    char *str = NULL;
    char *ret = NULL;

    ret = my_strtok(str, ",");
    cr_assert_eq(ret, NULL);
}
