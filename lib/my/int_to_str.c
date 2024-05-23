/*
** EPITECH PROJECT, 2024
** B-MUL-100-BDX-1-1-myradar-baptiste.blambert
** File description:
** int_to_str
*/

#include "../../include/my.h"
#include <stdio.h>

static int num_len(int num)
{
    int length = 0;

    if (num <= 0) {
        length = 1;
        num = -num;
    }
    while (num > 0) {
        num /= 10;
        length++;
    }
    return length;
}

char *int_to_str(int num)
{
    int length = num_len(num);
    char *str = malloc(length + 1);
    int is_negative = 0;

    if (str == NULL) {
        return NULL;
    }
    str[length] = '\0';
    is_negative = num < 0;
    if (is_negative) {
        num = -num;
    }
    for (int i = length - 1; i >= 0; i -= 1) {
        str[i] = (num % 10) + '0';
        num /= 10;
    }
    if (is_negative) {
        str[0] = '-';
    }
    return str;
}
