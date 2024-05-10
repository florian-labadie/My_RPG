/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** read_dialogue_file
*/

#include "my.h"

char *read_one_dialogue(char *filepath)
{
    char *dialogue = NULL;
    FILE *dialogue_file = fopen(filepath, "r");
    long dialog_size = 0;

    if (!filepath || !dialogue_file)
        return NULL;
    fseek(dialogue_file, 0, SEEK_END);
    dialog_size = ftell(dialogue_file);
    dialogue = malloc(sizeof(char) * (dialog_size + 1));
    rewind(dialogue_file);
    if (fread(dialogue, sizeof(char), dialog_size, dialogue_file) !=
                                                        (size_t)dialog_size) {
            free(dialogue);
            return NULL;
        }
    fclose(dialogue_file);
    return dialogue;
}

static char *read_dialogue(FILE *dialogue_file, int len)
{
    char *dialogue = NULL;

    dialogue = malloc(sizeof(char) * (len + 1));
    dialogue[len] = '\0';
    if (fread(dialogue, sizeof(char), len,
            dialogue_file) != (size_t)len) {
        free(dialogue);
        return NULL;
    }
    fclose(dialogue_file);
    if (dialogue[0] == '\0')
        free(dialogue);
    return dialogue;
}

static int get_skip_dialogue(FILE *dialogue_file, int *actual_dialogue,
    int *dialogue_begin, int dialogue_number)
{
    if (*actual_dialogue == dialogue_number) {
        return 1;
    } else {
        *dialogue_begin = ftell(dialogue_file);
        *actual_dialogue += 1;
    }
    return OK;
}

char *read_many_dialogue(char *filepath, int dialogue_number)
{
    FILE *dialogue_file = fopen(filepath, "r");
    size_t len = 0;
    char *line = NULL;
    int dialogue_begin = 0;
    int dialogue_end = 0;
    int actual_dialogue = 0;

    if (!filepath || !dialogue_file)
        return NULL;
    while (getline(&line, &len, dialogue_file) != -1) {
        if (my_strncmp(line, "==", 2) == OK &&
            get_skip_dialogue(dialogue_file, &actual_dialogue,
                &dialogue_begin, dialogue_number) == 1)
            break;
        dialogue_end = ftell(dialogue_file);
    }
    free(line);
    fseek(dialogue_file, dialogue_begin, SEEK_SET);
    return read_dialogue(dialogue_file, dialogue_end - dialogue_begin);
}
