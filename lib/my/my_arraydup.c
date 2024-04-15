/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_arraydup
*/

#include "my.h"

char **my_arraydup(char const *const *array)
{
    char **tmp = NULL;

    if (!array)
        return NULL;
    tmp = malloc(sizeof(char *) * (my_arraylen(array) + 1));
    for (int i = 0; array[i] != NULL; i += 1) {
        tmp[i] = my_strdup(array[i]);
    }
    tmp[my_arraylen(array)] = NULL;
    return tmp;
}
