/*
** EPITECH PROJECT, 2022
** my_get_size_tetri
** File description:
** Get size Y and X
*/

#include "tetris.h"

int my_get_size_tetrix(coordtetri_t *actualtetri)
{
    coordtetri_t *tmp = actualtetri;
    int tmpx = actualtetri->x;
    int tmpy = actualtetri->y;
    int size_x = 1;
    int max_x = 0;
    for (; tmp != NULL; tmp = tmp->next) {
        if (max_x < size_x)
            max_x = size_x;
        if (tmp->y != tmpy) {
            tmpy = tmp->y;
            size_x = 0;
        }
        if (tmp->x > size_x) {
            size_x += 1;
            tmpx = tmp->x;
        }
    }
    return size_x;
}

int my_get_size_tetriy(coordtetri_t *actualtetri)
{
    coordtetri_t *tmp = actualtetri;
    int size_y = 1;
    int tmpy = actualtetri->y;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmpy != tmp->y) {
            size_y += 1;
            tmpy = tmp->y;
        }
    }
    return size_y;
}
