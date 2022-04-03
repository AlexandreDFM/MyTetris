/*
** EPITECH PROJECT, 2022
** grid_manager
** File description:
** Grid management
*/

#include "tetris.h"

void grid_go_down(tetris_g_t *tetris_g, int actualy)
{
    for (int y = actualy; y > 1; y--) {
        for (int x = 1; tetris_g->grid[y][x + 2] != '\0'; x++) {
            tetris_g->grid[y][x] = tetris_g->grid[y - 1][x];
        }
    }
}

void grid_check_full(tetris_g_t *tetris_g, int y)
{
    for (int x = 1; tetris_g->grid[y][x + 1] != '\0'; x++) {
        if (tetris_g->grid[y][x] == ' ') return;
    }
    for (int x = 1; tetris_g->grid[y][x + 1] != '\0'; x++) {
        tetris_g->grid[y][x] = ' ';
    }
    grid_go_down(tetris_g, y);
    tetris_g->score += 100 * tetris_g->level;
    tetris_g->lines += 1;
    if (tetris_g->lines % 10 == 0) {
        tetris_g->level += 1;
        tetris_g->speed += 1;
    }
}

void grid_check_lines(tetris_g_t *tetris_g)
{
    for (int y = 1; tetris_g->grid[y + 1] != NULL; y++) {
        if (tetris_g->grid[y][1] != ' ')
            grid_check_full(tetris_g, y);
    }
}
