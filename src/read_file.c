/*
** EPITECH PROJECT, 2023
** Projet-Elementary Programming in c
** File description:
** buffer
*/

#include "my.h"

char *buffer_file(struct stat *s, char *buffer, int fd)
{
    int read_size;

    buffer = malloc(sizeof(char) * (s->st_size + 1));
    if (buffer == NULL) {
        my_putstr("Memory allocation error for the buffer\n");
        return NULL;
    }
    read_size = read(fd, buffer, s->st_size);
    if (read_size == -1) {
        my_putstr("Error reading file\n");
        return NULL;
    }
    buffer[read_size] = '\0';
    return buffer;
}

char *fs_open_file(char const *filepath)
{
    int fd;
    char *buffer = NULL;
    struct stat s;

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        my_putstr("Error opening file\n");
        return NULL;
    }
    if (stat(filepath, &s) == -1) {
        my_putstr("Error retrieving file size\n");
        return NULL;
    }
    buffer = buffer_file(&s, buffer, fd);
    if (buffer == NULL)
        return NULL;
    close(fd);
    return buffer;
}
