/*
** EPITECH PROJECT, 2022
** backup
** File description:
** Old version of fonctions
*/

#include "tetris.h"

void rotate_tetri2(WINDOW *tetris, tetris_g_t *tetris_g)
{
    int backspacecounter = 0, size = tetris_g->actual_tetri->sizepiece;
    char replace = ' ';
    char *tmp = my_strdup(tetris_g->actual_tetri->piece);
    for (int i = 0; tmp[i] != '\0'; i++) {
        for (int j = 0; j < size - 1; j++) {
            replace = tmp[j];
            tetris_g->actual_tetri->piece[j] = ' ';
            if (replace == '\n') {
                tetris_g->actual_tetri->piece[size * backspacecounter] = '\n';
                continue;
            } else {
                tetris_g->actual_tetri->piece[size - (j + 1)] = replace;
            }
        }
    }
    tetris_g->actual_tetri->tetrimino =
    create_tetri_coord(tetris_g->actual_tetri->tabpiece,
    tetris_g->actual_tetri->color);
    tetris_g->xactual_tetri - size;
    free(tmp);
}

coordtetri_t *create_tetri_coord2(char *tetriminos, char color)
{
    int x = 0, y = 0, i = 0;
    coordtetri_t *obj = create_node_coord(tetriminos[i], x, y);
    coordtetri_t *actual = NULL;
    coordtetri_t *tmp = obj;
    for (i = 1; tetriminos[i] != '\0'; i++) {
        if (tetriminos[i] == '\n') {
            x = 0;
            y += 1;
            continue;
        } else if (tetriminos[i] == ' ') {
            x++;
            continue;
        } else {
            actual = create_node_coord(color, x, y);
            link_nodes_coord(tmp, actual);
            tmp = actual;
        }
        x++;
    }
    return obj;
}
