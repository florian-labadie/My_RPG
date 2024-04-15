/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_put_errchar
*/

#include <unistd.h>

int my_put_errchar(char c)
{
    write(2, &c, 1);
    return 84;
}
