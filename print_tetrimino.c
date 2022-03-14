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
}

void print_tetrimino(void)
{
    char *tetris = NULL;
    char *path;
    char *name = malloc(32);
    DIR * dirp;
    int i= 0;
    struct dirent *entry;
    dirp = opendir("tetriminos/");
    while ((entry = readdir(dirp)) != NULL) {
        if (entry->d_type == DT_REG) {
            path = malloc(sizeof(char) * (12 + my_strlen(entry->d_name)));
            my_memset(path, 0, 12 + my_strlen(entry->d_name));
            my_strcat(path, "tetriminos/");
            my_strcat(path, entry->d_name);
            tetris = get_lines(path);
            for (i = 0; entry->d_name[i] != '.'; i++) {
                name[i] = entry->d_name[i];
            }
            name[i] = '\0';
            if (my_strncmp(my_revstr(entry->d_name), "onimirtet.", 11) != 0 || check_valid(tetris) == -1) {
                my_printf("Tetriminos :  Name %s :  Error\n", name);
            } else {
                my_printf("Tetriminos :  Name %s :  Size %c*%c :  Color %c", name, tetris[0], tetris[2], tetris[4]);
                tetris += 5;
                my_printf("%s", tetris);
            }
            my_memset(path, 0, my_strlen(path));
        }
    }
    closedir(dirp);
}

void count_tetrimino(void)
{
    int file_count = 0;
    DIR * dirp;
    struct dirent *entry;
    dirp = opendir("tetriminos/");
    while ((entry = readdir(dirp)) != NULL) {
        if (entry->d_type == DT_REG) {
            file_count++;
        }
    }
    closedir(dirp);
    my_printf("Tetriminos :  %d\n", file_count);
    print_tetrimino();
}
