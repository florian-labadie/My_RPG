/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-amazed-baptiste.blambert
** File description:
** proto
*/

#ifndef PROTO_H_
    #define PROTO_H_

    #include "my.h"

int launch_amazed(void);
int parse(amazed_t *amazed);
void check_commentary(char **line);
int display(amazed_t *amazed, recovery_t *rec);
int put_room(amazed_t *amazed, room_status_t *status, char *line);
int put_tunnel(amazed_t *amazed, char *line);
int init_matrix(amazed_t *amazed);
int get_room_pos(char **names, char *name);
int free_amazed(amazed_t *amazed, int ret);
int get_path(matrix_t *matrix, int *parent);
int robot_parcour(matrix_t *matrix, int robot_nbr);
int my_bfs(matrix_t *matrix);

#endif /* PROTO_H_ */
