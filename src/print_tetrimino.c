/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCE-2-1-tetris-antoine.frankel
** File description:
** print_tetrimino
*/

#include "tetris.h"

int check_valid(char *tetris)
{
    if (tetris[0] < '0' || tetris[0] > '9') return -1;
    if (tetris[2] < '0' || tetris[2] > '9') return -1;
    if (tetris[4] < '0' || tetris[4] > '9') return -1;
    return 0;
}

char *trim_spaces(char *tetris)
{
    int i = 0;
    for (; tetris[i] != '\0'; i++) {
        if (tetris[i] == ' ' && tetris[i + 1] == '\n') {
            for (int j = i; tetris[j + 1] != '\0'; j++)
               tetris[j] = tetris[j + 1];
        }
    }
    tetris[i] = '\0';
    for (int j = i; j != 0; j--) {
        if (tetris[j] == '\n' && tetris[j - 1] == '\n') tetris[j] = '\0';
    }
}

int print2(struct dirent *entry, char *name, tetris_t *tetris_s, char *tetris)
{
    int i = 0;
    for (; entry->d_name[i] != '.'; i++) {
        name[i] = entry->d_name[i];
    }
    name[i] = '\0';
    if (my_strncmp(my_revstr(entry->d_name), "onimirtet.", 11) != 0 ||
    check_valid(tetris) == -1) {
        tetris_s->total -= 1;
        if (tetris_s->debug == 1)
            my_printf("Tetriminos '%s': error\n", name);
    } else {
        if (tetris_s->debug == 1)
            my_printf("Tetriminos '%s': size %c*%c, color %c", name, tetris[0],
            tetris[2], tetris[4]);
        tetris_s->color[tetris_s->t_nb] = tetris[4];
        tetris += 5;
        trim_spaces(tetris);
        tetris_s->tetriminos[tetris_s->t_nb] = my_strdup(tetris);
        if (tetris_s->debug == 1)
            my_printf("%s", tetris_s->tetriminos[tetris_s->t_nb]);
        tetris_s->t_nb++;
    }
}

void print_tetrimino(tetris_t *tetris_s)
{
    DIR * dirp;
    int i = 0, count = 0;
    struct dirent *entry;
    char *tetris = NULL, *path, *name = malloc(32);
    dirp = opendir("tetriminos/");
    while ((entry = readdir(dirp)) != NULL) {
        if (entry->d_type == DT_REG) {
            path = malloc(sizeof(char) * (12 + my_strlen(entry->d_name)));
            my_memset(path, 0, 12 + my_strlen(entry->d_name));
            my_strcat(path, "tetriminos/");
            my_strcat(path, entry->d_name);
            tetris = get_lines(path);
            print2(entry, name, tetris_s, tetris);
            my_memset(path, 0, my_strlen(path));
        }
    }
    tetris_s->t_nb = count;
    closedir(dirp);
}

void count_tetrimino(tetris_t *tetris)
{
    int file_count = 0;
    DIR * dirp;
    struct dirent *entry;
    tetris->t_nb = 0, tetris->total = 0;
    dirp = opendir("tetriminos/");
    if (!dirp) exit (84);
    while ((entry = readdir(dirp)) != NULL) {
        if (entry->d_type == DT_REG) {
            file_count++;
        }
    }
    tetris->total = file_count;
    tetris->tetriminos = malloc(sizeof(char *) * file_count);
    tetris->color = malloc(sizeof(char) * file_count);
    closedir(dirp);
    if (tetris->debug == 1)
        my_printf("Number of tetriminos: %d\n", file_count);
    print_tetrimino(tetris);
}
