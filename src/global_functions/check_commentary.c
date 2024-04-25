/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-robotfactory-florian.labadie
** File description:
** check_commentary
*/

#include "my.h"

void check_commentary(char **line)
{
    for (int i = 0; (*line)[i] != '\0'; i += 1) {
        if ((*line)[i] == COMMENT_CHAR && (*line)[i + 1] == COMMENT_CHAR)
            i += 2;
        if ((*line)[i] == COMMENT_CHAR && (*line)[i + 1] != COMMENT_CHAR) {
            (*line)[i] = '\0';
            return;
        }
    }
}
