/*
** EPITECH PROJECT, 2022
** mouvement
** File description:
** Mouvement manager
*/

#include "tetris.h"

int x_check_right(WINDOW * tetris, tetris_g_t *tetris_g)
{
    coordtetri_t *tmp = tetris_g->actual_tetri->tetrimino;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tetris_g->grid[tetris_g->yactual_tetri +
        tmp->y][tetris_g->xactual_tetri + tmp->x + 1] != ' ') {
            return 0;
        }
    }
    return 1;
}

int x_check_left(WINDOW * tetris, tetris_g_t *tetris_g)
{
    coordtetri_t *tmp = tetris_g->actual_tetri->tetrimino;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tetris_g->grid[tetris_g->yactual_tetri +
        tmp->y][tetris_g->xactual_tetri + tmp->x - 1] != ' ') {
            return 0;
        }
    }
    return 1;
}

int inputs_manager(WINDOW *tetris, tetris_g_t *tetris_g, int input)
{
    if (input == tetris_g->key_q) return 84;
    if (input == tetris_g->key_t && x_check_right(tetris, tetris_g))
        rotate_tetri(tetris, tetris_g);
    if (input == tetris_g->key_d && tetris_g->yactual_tetri < tetris_g->height)
        tetris_g->yactual_tetri += 1;
    if (input == tetris_g->key_l && x_check_left(tetris, tetris_g))
        tetris_g->xactual_tetri -= 1;
    if (input == tetris_g->key_r && x_check_right(tetris, tetris_g))
        tetris_g->xactual_tetri += 1;
    return 1;
}

void set_piece(tetris_g_t *tetris_g)
{
    coordtetri_t *tmptetris = tetris_g->actual_tetri->tetrimino;
    for (; tmptetris != NULL; tmptetris = tmptetris->next) {
        tetris_g->grid[tetris_g->yactual_tetri - 1
        + tmptetris->y][tetris_g->xactual_tetri + tmptetris->x] =
        tmptetris->symbol;
    }
    tetris_g->actual_tetri = NULL;
}

void check_set_piece(WINDOW *tetris, tetris_g_t *tetris_g)
{
    coordtetri_t *tmp2 = tetris_g->actual_tetri->tetrimino;
    for (; tmp2 != NULL; tmp2 = tmp2->next) {
        if (tetris_g->grid[tetris_g->yactual_tetri +
        tmp2->y][tetris_g->xactual_tetri + tmp2->x] != ' ') {
            set_piece(tetris_g);
            return;
        }
    }
}
