/*
** EPITECH PROJECT, 2022
** my_print_next
** File description:
** Function to print tetriminos next
*/

#include "tetris.h"

void print_tetriminos(WINDOW *tetris, tetris_g_t *tetris_g)
{
    coordtetri_t *actual = tetris_g->actual_tetri->tetrimino;
    while (actual != NULL) {
        attron(COLOR_PAIR((int) actual->symbol - 48));
        mvwprintw(tetris, LINES / 2 - (tetris_g->height / 2)
        + tetris_g->yactual_tetri + actual->y,
        COLS / 2 - tetris_g->width / 2 +
        (my_strlen(tetris_g->interfaceleft[0]))
        + tetris_g->xactual_tetri + actual->x, "%c", ' ');
        attroff(COLOR_PAIR((int) actual->symbol - 48));
        actual = actual->next;
    }
}

void my_print_next(WINDOW *tetris, tetris_g_t *tetris_g)
{
    for (coordtetri_t *tmp = tetris_g->next_tetri->tetrimino;
    tmp; tmp = tmp->next) {
        attron(COLOR_PAIR((int) tmp->symbol - 48));
        mvwprintw(tetris, LINES / 2 - (tetris_g->height / 2)
        + tetris_g->ynext_tetri + tmp->y,
        COLS / 2 - tetris_g->width / 2 +
        (my_strlen(tetris_g->interfaceleft[0]))
        + tetris_g->xnext_tetri + tmp->x, "%c", ' ');
        attroff(COLOR_PAIR((int) tmp->symbol - 48));
    }
}
