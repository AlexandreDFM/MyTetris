/*
** EPITECH PROJECT, 2022
** init_tetris_game
** File description:
** Functions to init the tetris game
*/

#include "tetris.h"

int get_bigger_size_tetri(tetris_g_t *tetris_g)
{
    tetriminos_t *tmp = tetris_g->tetriminos;
    int max_size = 0;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->sizepiece > max_size)
            max_size = tmp->sizepiece;
    }
    return max_size;
}

void init_tetris2(tetris_g_t *tetris_g, tetris_t *tetris_stats)
{
    tetris_g->level = tetris_stats->level <= 1 ? 1 : tetris_stats->level;
    tetris_g->tetriminos = create_list(tetris_stats->tetriminos,
    tetris_stats->color, tetris_stats->total);
    tetris_g->actual_tetri = NULL;
    tetris_g->next_tetri = NULL;
    tetris_g->nb_tetri = tetris_stats->total;
    tetris_g->interfaceleft =
    my_strtwa(get_lines("./interface/interface_1"), "\n");
    tetris_g->grid = create_grid(my_atoi(tetris_stats->col) + 2,
    my_atoi(tetris_stats->row) + 2);
    int i = get_bigger_size_tetri(tetris_g);
    tetris_g->xnext_tetri = 3 + my_strlen(tetris_g->grid[0]);
    tetris_g->ynext_tetri = 2;
    tetris_g->interfaceright = create_next_grid(i + 5, i + 4);
    tetris_g->height = 0, tetris_g->width = 0, tetris_g->highscore = 0,
    tetris_g->score = 0, tetris_g->lines = 0, tetris_g->speed = 1,
    tetris_g->timermins = 0, tetris_g->timersecondes = 0;
}

void init_tetris3(tetris_g_t *tetris_g, tetris_t *tetris_stats)
{
    for (int x = 0; tetris_g->interfaceleft[x] != NULL;
    x++, tetris_g->height++);
    int size = 0;
    for (int x = 0; tetris_g->grid[x] != NULL;
    x++, size++);
    if (size > tetris_g->height)
        tetris_g->height = size;
    for (int x = 0, size = 0; tetris_g->interfaceright[x] != NULL;
    x++, size++);
    if (size > tetris_g->height)
        tetris_g->height = size;
    tetris_g->width = my_strlen(tetris_g->interfaceleft[0]);
    tetris_g->width += my_strlen(tetris_g->grid[0]);
    tetris_g->width += my_strlen(tetris_g->interfaceright[0]);
}

void init_tetris4(tetris_g_t *tetris_g, tetris_t *tetris_stats)
{
    tetris_g->key_l = get_key(tetris_stats->key_l, tetris_stats);
    tetris_g->key_r = get_key(tetris_stats->key_r, tetris_stats);
    tetris_g->key_t = get_key(tetris_stats->key_t, tetris_stats);
    tetris_g->key_d = get_key(tetris_stats->key_d, tetris_stats);
    tetris_g->key_q = get_key(tetris_stats->key_q, tetris_stats);
    tetris_g->key_p = get_key(tetris_stats->key_p, tetris_stats);
}

void init_tetris(tetris_t *tetris_stats)
{
    tetris_g_t tetris_g;
    init_tetris2(&tetris_g, tetris_stats);
    init_tetris3(&tetris_g, tetris_stats);
    init_tetris4(&tetris_g, tetris_stats);
    WINDOW *tetris = initscr();
    create_highscore(&tetris_g);
    keypad(tetris, TRUE); nodelay(tetris, TRUE);
    start_color(); noecho();
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_BLACK, COLOR_RED);
    init_pair(3, COLOR_BLACK, COLOR_BLUE);
    init_pair(4, COLOR_BLACK, COLOR_YELLOW);
    init_pair(5, COLOR_BLACK, COLOR_GREEN);
    init_pair(6, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(7, COLOR_BLACK, COLOR_CYAN);
    curs_set(0);
    game(tetris, &tetris_g);
    endwin();
    delwin(tetris);
    check_highscore(&tetris_g);
}
