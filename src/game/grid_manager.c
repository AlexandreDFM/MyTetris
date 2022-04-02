/*
** EPITECH PROJECT, 2022
** grid_manager
** File description:
** Grid management
*/

#include "tetris.h"

void grid_check_full(tetris_g_t *tetris_g, int y)
{
    for (int x = 1; tetris_g->grid[y][x + 3] != '\0'; x++) {
        if (tetris_g->grid[y][x] == ' ') return;
    }
    for (int x = 1; tetris_g->grid[y][x + 3] != '\0'; x++) {
        tetris_g->grid[y][x] = ' ';
    }
}

void grid_check_lines(tetris_g_t *tetris_g)
{
    for (int y = 1; tetris_g->grid[y + 1] != NULL; y++) {
        if (tetris_g->grid[y][1] != ' ')
            grid_check_full(tetris_g, y);
    }
}
