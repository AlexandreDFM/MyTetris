/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCE-2-1-tetris-antoine.frankel
** File description:
** parse flags
*/

#include "tetris.h"

char *retrieve_int(char *str, char *str2)
{
    if (!str2 && my_strlen(str) == 2) exit(84);
    char *tmp, *tmp2 = malloc(2);
    int i = 0, j = 0;
    if (my_strlen(str) == 2) {
        if (my_strlen(str2) > 1) {
            tmp2[0] = (char) my_atoi(str2);
            tmp2[1] = '\0';
            return tmp2;
        } else return str2;
    } else {
        for (; str[i] != '='; i++, j++);
        str += ++i;
        if (my_strlen(str) == 0) exit(84);
        if (my_strlen(str) > 1) {
            tmp2[0] = (char) my_atoi(str);
            tmp2[1] = '\0';
            return tmp2;
        } else
            tmp = malloc(sizeof(char) * my_strlen(str));
            tmp = my_strncpy(tmp, str, my_strlen(str));
            return tmp;
    }
}

void get_size(char *str, tetris_t *tetris)
{
    int i = 0, j = 0;
    str += 11;
    for (; str[i] != ','; i++, j++);
    tetris->row = malloc(sizeof(char) * (j + 1));
    tetris->row = my_strncpy(tetris->row, str, j);
    tetris->row[my_strlen(tetris->row)] = '\0';
    str += j + 1;
    for (j = 0; str[i] != '\0'; i++, j++);
    tetris->col = malloc(sizeof(char) * (j + 1));
    tetris->col = my_strncpy(tetris->col, str, j);
    tetris->col[my_strlen(tetris->col)] = '\0';
}

void parse_flags2(char **av, int i, tetris_t *tetris)
{
    if (my_strcmp(av[i], "-p") == 0 || my_strncmp(av[i], "--key-pause=",
        10) == 0) tetris->key_p = retrieve_int(av[i], av[i + 1]);
    if (my_strncmp(av[i], "--map-size=", 10) == 0)
        get_size(av[i], tetris);
    if (my_strncmp(av[i], "--help", 7) == 0)
        help();
}

int get_level(char *str, char *str2)
{
    int i = 0;
    if (my_strlen(str) == 2) {
        return my_atoi(str2);
    } else {
        for (; str[i] != '='; i++);
        str += ++i;
        return my_atoi(str);
    }
}

void parse_flags(int ac, char **av, tetris_t *tetris, int i)
{
    for (; i < ac; i++) {
        if (my_strcmp(av[i], "-D") == 0 || my_strcmp(av[i], "--debug") == 0)
            tetris->debug = 1;
        if (my_strcmp(av[i], "-w") == 0 || my_strcmp(av[i],
        "--without_next") == 0) tetris->hide_n = 1;
        if (my_strcmp(av[i], "-L") == 0 || my_strncmp(av[i],
        "--level=", 10) == 0) tetris->level = get_level(av[i], av[i + 1]);
        if (my_strcmp(av[i], "-l") == 0 || my_strncmp(av[i], "--key-left=",
        10) == 0) tetris->key_l = retrieve_int(av[i], av[i + 1]);
        if (my_strcmp(av[i], "-r") == 0 || my_strncmp(av[i], "--key-right=",
        10) == 0) tetris->key_r = retrieve_int(av[i], av[i + 1]);
        if (my_strcmp(av[i], "-t") == 0 || my_strncmp(av[i], "--key-turn=",
        10) == 0) tetris->key_t = retrieve_int(av[i], av[i + 1]);
        if (my_strcmp(av[i], "-d") == 0 || my_strncmp(av[i], "--key-drop=",
        10) == 0) tetris->key_d = retrieve_int(av[i], av[i + 1]);
        if (my_strcmp(av[i], "-q") == 0 || my_strncmp(av[i], "--key-quit=",
        10) == 0) tetris->key_q = retrieve_int(av[i], av[i + 1]);
        parse_flags2(av, i , tetris);
    }
}
