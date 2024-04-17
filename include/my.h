/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** task02
*/

#ifndef LIB_H_
    #define LIB_H_

    #define OK 0
    #define KO 84
    #define ERR -1

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>

    #include "rpg.h"

    #include "proto.h"
    #include "macro.h"

    #include <stdlib.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <string.h>
    #include <stdbool.h>
    #include <math.h>

int error_handling(int argc, char const *const *argv);
int my_putchar(char c);
int my_put_errchar(char c);
int my_putstr(char const *str);
int my_put_errstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strdup(char const *src);
char *my_strndup(char const *src, int n);
char *my_strcat(char *dest, char const *src);
int my_put_nbr(int nb);
int my_getnbr(char const *str);
char *my_strtok(char *str, char const *delimiter);
int my_arraylen(char const *const *array);
char **my_arraydup(char const *const *array);
int numeric(char c);
int alphabetic(char c);
int alpha_num(char c);

#endif /* LIB_H_ */
