/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** check_env
*/

#include "my.h"

char *check_env(char const *const *env)
{
    int count = 0;
    char *user = NULL;

    for (int i = 0; env[i] != NULL; i += 1) {
        if (my_strncmp(env[i], "LOGNAME=", 8) == OK)
            user = my_strdup(&env[i][8]);
        if (my_strncmp(env[i], "XAUTHORITY=", 11) == OK)
            count += 1;
        if (my_strncmp(env[i], "DISPLAY=", 8) == OK)
            count += 1;
    }
    if (count != 2 || !user)
        return NULL;
    return user;
}
