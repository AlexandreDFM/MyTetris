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
    int key_l;
    int key_r;
    int key_t;
    int key_d;
    int key_q;
    int key_p;
    int width;
    int height;
    int speed;
    int highscore;
    int score;
    int lines;
    int level;
    int timermins;
    int timersecondes;
    int nb_tetri;
    int xactual_tetri;
    int yactual_tetri;
    int xnext_tetri;
    int ynext_tetri;
    char **interfaceleft;
    char **grid;
    char **interfaceright;
    clock_t begin;
    clock_t end;
    tetriminos_t *tetriminos;
    tetriminos_t *actual_tetri;
    tetriminos_t *next_tetri;
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

void init_tetris(tetris_t *tetris_stats);
void help(void);
void grid_check_full(tetris_g_t *tetris_g, int y);
void grid_check_lines(tetris_g_t *tetris_g);
char **my_strtwa(char const *str, char *limit);
char **create_char_tab(int x, int y);
tetriminos_t *create_list(char **tetriminos, char *color, int nbtetri);
coordtetri_t *create_tetri_coord(char **tetriminos, char color);
void rotate_tetri(WINDOW *tetris, tetris_g_t *tetris_g);
int inputs_manager(WINDOW *tetris, tetris_g_t *tetris_g, int input);
tetriminos_t *create_node(char *tetriminos, char color);
void check_set_piece(WINDOW *tetris, tetris_g_t *tetris_g);
void create_highscore(tetris_g_t *tetris_g);
void open_write(tetris_g_t *tetris_g);
void check_highscore(tetris_g_t *tetris_g);
void display_highscore(WINDOW *tetris, tetris_g_t *tetris_g);
void game(WINDOW *tetris, tetris_g_t *tetris_g);
void print_interfaces(WINDOW *tetris, tetris_g_t *tetris_g);
void link_nodes(tetriminos_t *link1, tetriminos_t *link2);
void link_nodes_coord(coordtetri_t *link1, coordtetri_t *link2);
void print_tetriminos(WINDOW *tetris, tetris_g_t *tetris_g);
void my_free_coordtetrimino(coordtetri_t *tetrimino);
int check_lose(tetris_g_t *tetris_g);
void my_print_next(WINDOW *tetris, tetris_g_t *tetris_g);
