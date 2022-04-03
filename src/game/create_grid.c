/*
** EPITECH PROJECT, 2022
** create_grid
** File description:
** Function to create game grid
*/

#include "tetris.h"

char **fill_grid(char **grid, int width, int height)
{
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            grid[y][x] = '1';
        }
    }
    for (int y = 1; y < height - 1; y++) {
        for (int x = 1; x < width - 1; x++) {
            grid[y][x] = ' ';
        }
    }
    return grid;
}

char **create_char_tab(int x, int y)
{
    char **array = malloc(sizeof(char *) * (y + 1));
    array[y] = NULL;
    for (int i = 0; i < y; i++) {
        array[i] = malloc(sizeof(char) * (x + 1));
        for (int j = 0; j < x; j++)
            array[i][j] = ' ';
        array[i][x] = '\0';
    }
    for (int i = 0; i < y; i++)
        my_memset(array[i], 32, x);
    return array;
}

char **create_grid(int width, int height)
{
    char **grid = malloc(sizeof(char *) * (height + 1));
    grid[height] = NULL;
    for (int y = 0; y < height; y++) {
        grid[y] = malloc(sizeof(char) * (width + 1));
        grid[y][width] = '\0';
    }
    grid = fill_grid(grid, width, height);
    return grid;
}

char **fill_next_grid(char **grid, int width, int height)
{
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            grid[y][x] = '1';
        }
    }
    for (int y = 0; y < height; y++)
        grid[y][0] = ' ';
    int posnext = width / 2 - 2;
    grid[0][posnext] = 'N';
    grid[0][posnext + 1] = 'E';
    grid[0][posnext + 2] = 'X';
    grid[0][posnext + 3] = 'T';
    for (int y = 1; y < height - 1; y++) {
        for (int x = 2; x < width - 1; x++) {
            grid[y][x] = ' ';
        }
    }
    return grid;
}

char **create_next_grid(int width, int height)
{
    char **grid = malloc(sizeof(char *) * (height + 1));
    grid[height] = NULL;
    for (int y = 0; y < height; y++) {
        grid[y] = malloc(sizeof(char) * (width + 2));
        grid[y][width] = '\0';
    }
    grid = fill_next_grid(grid, width, height);
    return grid;
}
