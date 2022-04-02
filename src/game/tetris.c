/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** tetris
*/

#include "tetris.h"

void print_tetriminos(WINDOW *tetris, tetris_g_t *tetris_g)
{
    coordtetri_t *actual = tetris_g->actual_tetri->tetrimino;
    while (actual != NULL) {
        attron(COLOR_PAIR((int) actual->symbol - 48));
        mvwprintw(tetris, LINES / 2 - (tetris_g->height / 2) + tetris_g->yactual_tetri + actual->y,
        COLS / 2 - tetris_g->width / 2 + (my_strlen(tetris_g->interfaceleft[0]))
        + tetris_g->xactual_tetri + actual->x, "%c", ' ');
        attroff(COLOR_PAIR((int) actual->symbol - 48));
        actual = actual->next;
    }
}

void time_gestionnary(tetris_g_t *tetris_g)
{
    tetris_g->end = clock();
    if ((tetris_g->end - tetris_g->begin) / CLOCKS_PER_SEC > 1 ) {
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
    tetris_g->actual_tetri->tetrimino =
    create_tetri_coord(tetris_g->actual_tetri->tabpiece,
    tetris_g->actual_tetri->color);
    tetris_g->xactual_tetri - size;
}

void pick_tetri(WINDOW *tetris, tetris_g_t *tetris_g)
{
    int i = 0;
    tetris_g->yactual_tetri = 1;
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
    tetris_g->actual_tetri = create_node(tmp->piece, tmp->color);
    for (i = 0; tetris_g->actual_tetri->piece[i] != '\n'; i++);
    tetris_g->xactual_tetri = (my_strlen(tetris_g->grid[0]) - 2) / 2 - i;
}

void game(WINDOW *tetris, tetris_g_t *tetris_g)
{
    int input = 0;
    tetris_g->begin = clock();
    while (1) {
        if (LINES < tetris_g->height || COLS < tetris_g->width) {
            clear();
            mvwprintw(stdscr, LINES / 2, COLS / 2 - 10, "Wrong terminal size");
            refresh();
        } else {
            if (tetris_g->actual_tetri == NULL) pick_tetri(tetris, tetris_g);
            time_gestionnary(tetris_g);
            print_interfaces(tetris, tetris_g);
            if (tetris_g->actual_tetri != NULL) print_tetriminos(tetris, tetris_g);
            input = wgetch(tetris);
            if (tetris_g->actual_tetri != NULL &&
            inputs_manager(tetris, tetris_g, input) == 84) return;
            grid_check_lines(tetris_g);
            check_set_piece(tetris, tetris_g);
        }
    }
}
