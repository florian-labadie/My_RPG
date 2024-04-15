/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-amazed-baptiste.blambert
** File description:
** letter_check
*/

#include "my.h"

int numeric(char c)
{
    if (!c)
        return KO;
    if (c >= '0' && c <= '9')
        return OK;
    return KO;
}

int alphabetic(char c)
{
    if (!c)
        return KO;
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return OK;
    return KO;
}

int alpha_num(char c)
{
    if (!c)
        return KO;
    if (alphabetic(c) == OK || numeric(c) == OK)
        return OK;
    return KO;
}
