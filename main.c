/*
** EPITECH PROJECT, 2023
** Projet-Graphic
** File description:
** main
*/

#include "my.h"

int main(int argc, char const *const *argv, char const *const *env)
{
    char *user = check_env(env);

    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        return my_putstr(fs_open_file("README.txt"));
    if (!user || error_handling(argc, argv) == KO)
        return KO;
    if (launch_rpg(user))
        return KO;
    return OK;
}
