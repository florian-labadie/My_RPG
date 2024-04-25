/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** blanck_line
*/

#include "my.h"

int check_blankline(char *line)
{
    for (int i = 0; line[i] != '\0'; i += 1) {
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
            return ERR;
    }
    return OK;
}
