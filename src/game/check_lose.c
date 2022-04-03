/*
** EPITECH PROJECT, 2022
** check_lose
** File description:
** Function to check the lose
*/

#include "tetris.h"

int check_lose(tetris_g_t *tetris_g)
{
    if (tetris_g->actual_tetri == NULL) return 0;
    for (int x = 1; tetris_g->grid[2][x + 1] != '\0'; x++) {
        if (tetris_g->grid[2][x] != ' ') return 84;
    }
    return 0;
}
