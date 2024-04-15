/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** my_arraylen
*/

#include "my.h"

int my_arraylen(char const *const *array)
{
    int len = 0;

    if (!array)
        return 0;
    while (array[len] != NULL) {
        len += 1;
    }
    return len;
}
