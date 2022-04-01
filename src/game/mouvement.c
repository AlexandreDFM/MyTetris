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
