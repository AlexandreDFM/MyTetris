/*
** EPITECH PROJECT, 2022
** mouvement
** File description:
** Mouvement manager
*/

#include "tetris.h"

int inputs_manager(WINDOW *tetris, tetris_g_t *tetris_g, int input)
{
    if (input == 27) return 84;
    if (input == KEY_UP && tetris_g->xactual_tetri > 1) rotate_tetri(tetris, tetris_g);
    if (input == KEY_DOWN && tetris_g->yactual_tetri < tetris_g->height) tetris_g->yactual_tetri += 1;
    if (input == KEY_LEFT && tetris_g->xactual_tetri > 1) tetris_g->xactual_tetri -= 1;
    if (input == KEY_RIGHT && tetris_g->xactual_tetri < my_strlen(tetris_g->grid[0]) - tetris_g->actual_tetri->sizepiece) tetris_g->xactual_tetri += 1;
    return 1;
}

void max_mouvement(WINDOW *tetris, tetris_g_t *tetris_g)
{
    // if (tetris_g->yactual_tetri == )
}

void set_piece(tetris_g_t *tetris_g)
{
    coordtetri_t *tmptetris = tetris_g->actual_tetri->tetrimino;
    for (; tmptetris != NULL; tmptetris = tmptetris->next) {
        tetris_g->grid[tetris_g->yactual_tetri - 1 + tmptetris->y][tetris_g->xactual_tetri + tmptetris->x] = tmptetris->symbol;
    }
    tetris_g->actual_tetri = NULL;
}

void check_set_piece(WINDOW *tetris, tetris_g_t *tetris_g)
{
    // coordtetri_t *tmp1 = tetris_g->actual_tetri->tetrimino;
    // for (; tmp1 != NULL; tmp1 = tmp1->next) {
    //     if (tetris_g->yactual_tetri == tetris_g->height - tetris_g->actual_tetri->sizepiece) {
    //         set_piece(tetris_g);
    //         return;
    //     }
    // }
    coordtetri_t *tmp2 = tetris_g->actual_tetri->tetrimino;
    for (; tmp2 != NULL; tmp2 = tmp2->next) {
        if (tetris_g->grid[tetris_g->yactual_tetri + tmp2->y][tetris_g->xactual_tetri + tmp2->x] != ' ') {
            set_piece(tetris_g);
            return;
        }
    }
}
