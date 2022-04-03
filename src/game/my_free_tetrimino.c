/*
** EPITECH PROJECT, 2022
** my_free_tetrimino
** File description:
** Fonction to free coordtetrimino
*/

#include "tetris.h"

void my_free_coordtetrimino(coordtetri_t *tetrimino)
{
    coordtetri_t *tmp = tetrimino;
    while (tetrimino != NULL) {
        tmp = tetrimino;
        tetrimino = tetrimino->next;
        free(tmp);
    }
}
