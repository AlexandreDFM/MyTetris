/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** tetris
*/

#include "tetris.h"

void time_gestionnary(tetris_g_t *tetris_g)
{
    tetris_g->end = clock();
    if (((tetris_g->end - tetris_g->begin) / CLOCKS_PER_SEC)
    * tetris_g->speed > 1 ) {
        clear();
        refresh();
        tetris_g->begin = clock();
        tetris_g->yactual_tetri += 1;
        tetris_g->timersecondes += 1;
        if (tetris_g->timersecondes > 59) {
            tetris_g->timersecondes = 0;
            tetris_g->timermins += 1;
        }
    }
}

void rotate_tetri(WINDOW *tetris, tetris_g_t *tetris_g)
{
    int size = tetris_g->actual_tetri->sizepiece;
    char **tmptabpiece = create_char_tab(size + 1, size + 1);
    for (int y = 0; y <= size; y++) {
        for (int x = 0; x <= size; x++)
            tmptabpiece[y][x] = tetris_g->actual_tetri->tabpiece[y][x];
    }
    for (int y = 0, i = 0; i <= size; y++, i++) {
        for (int x = 0, j = size; j >= 0; x++, j--) {
            tetris_g->actual_tetri->tabpiece[y][x] = tmptabpiece[j][i];
        }
    }
    my_free_coordtetrimino(tetris_g->actual_tetri->tetrimino);
    tetris_g->actual_tetri->tetrimino =
    create_tetri_coord(tetris_g->actual_tetri->tabpiece,
    tetris_g->actual_tetri->color);
}

tetriminos_t *pick_tetri(WINDOW *tetris, tetris_g_t *tetris_g)
{
    int i = 0;
    int tetri = (rand() % tetris_g->nb_tetri - 1) + 1;
    tetriminos_t *tmp = tetris_g->tetriminos;
    tetriminos_t *actual = tmp;
    while (actual != NULL && i <= tetri) {
        tmp = actual;
        coordtetri_t *actual2 = actual->tetrimino;
        while (actual2 != NULL) {
            actual2 = actual2->next;
        }
        actual = actual->next;
        i++;
    }
    return create_node(tmp->piece, tmp->color);
}

void check_new_piece(WINDOW *tetris, tetris_g_t *tetris_g)
{
    if (tetris_g->next_tetri == NULL) {
        tetris_g->next_tetri = pick_tetri(tetris, tetris_g);
    }
    if (tetris_g->actual_tetri == NULL) {
        tetris_g->actual_tetri = tetris_g->next_tetri;
        tetris_g->next_tetri = pick_tetri(tetris, tetris_g);
        int i = 0; tetris_g->yactual_tetri = 1;
        for (i = 0; tetris_g->actual_tetri->piece[i] != '\n'; i++);
        tetris_g->xactual_tetri =
        (my_strlen(tetris_g->grid[0]) - 2) / 2 - i;
    }
}

void game(WINDOW *tetris, tetris_g_t *tetris_g)
{
    int input = 0; tetris_g->begin = clock();
    while (1) {
        if (LINES < tetris_g->height || COLS < tetris_g->width) {
            clear();
            mvwprintw(stdscr, LINES / 2, COLS / 2 - 10, "Wrong terminal size");
            refresh();
        } else {
            check_new_piece(tetris, tetris_g);
            time_gestionnary(tetris_g);
            print_interfaces(tetris, tetris_g);
            if (tetris_g->actual_tetri != NULL)
                print_tetriminos(tetris, tetris_g);
            input = wgetch(tetris);
            if (tetris_g->actual_tetri != NULL &&
            inputs_manager(tetris, tetris_g, input) == 84) return;
            grid_check_lines(tetris_g);
            check_set_piece(tetris, tetris_g);
            if (check_lose(tetris_g) == 84) return;
        }
    }
}
