/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_putarray
*/

#include "my.h"

int my_putarray(char const *const *array)
{
    if (!array)
        return 84;
    for (int i = 0; array[i] != NULL; i += 1)
        my_putstr(array[i]);
    return 0;
}
