/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCE-2-1-tetris-antoine.frankel
** File description:
** tetris
*/

#pragma once

#include "my.h"
#include "printf.h"
#include <curses.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

// #define DT_REG 8

typedef struct tetris {
    char **tetriminos;
    char *color;
    int t_nb;
    int level;
    char *key_l;
    char *key_r;
    char *key_t;
    char *key_d;
    char *key_q;
    char *key_p;
    char *row;
    char *col;
    int hide_n;
    int debug;
    char **keys;
    int *key_nb;
    int total;
}tetris_t;

typedef struct coordtetri {
    char symbol;
    int x;
    int y;
    struct coordtetri *prev;
    struct coordtetri *next;
}coordtetri_t;

typedef struct tetriminos {
    int sizepiece;
    char *piece;
    char **tabpiece;
    char color;
    coordtetri_t *tetrimino;
    struct tetriminos *prev;
    struct tetriminos *next;
}tetriminos_t;

typedef struct tetris_g {
    int width;
    int height;
    int highscore;
    int score;
    int lines;
    int level;
    int timermins;
    int timersecondes;
    int nb_tetri;
    int xactual_tetri;
    int yactual_tetri;
    char **interfaceleft;
    char **grid;
    char **interfaceright;
    clock_t begin;
    clock_t end;
    tetriminos_t *tetriminos;
    tetriminos_t *actual_tetri;
}tetris_g_t;

char *my_itoa(int num);
char *my_strdup(char *src);
int my_atoi(char const *str);
void print_debug(tetris_t *tetris);
char *get_lines(char const *filepath);
void count_tetrimino(tetris_t *tetris);
int is_present(char **array, char *str, int check);
void *my_memset(void *dest, int value, int length);
void parse_flags(int ac, char **av, tetris_t *tetris, int i);
char **create_next_grid(int width, int height);
char **fill_next_grid(char **grid, int width, int height);
char **create_grid(int width, int height);
char **fill_grid(char **grid, int width, int height);
