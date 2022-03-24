/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCE-2-1-tetris-antoine.frankel
** File description:
** print_debug
*/

#include "tetris.h"

int get_key(char *str, tetris_t *tetris)
{
    if (my_strlen(str) == 1) return (int) str[0];
    else {
        int i = 0;
        for (; i < 4 && my_strcmp(str, tetris->keys[i]) != 0; i++);
        return tetris->key_nb[i];
    }
}

void print_debug(tetris_t *tetris)
{
    my_printf("Key left: %s (%d)\n", tetris->key_l,
    get_key(tetris->key_l,tetris));
    my_printf("Key right: %s (%d)\n", tetris->key_r,
    get_key(tetris->key_r,tetris));
    my_printf("Key turn: %s (%d)\n", tetris->key_t,
    get_key(tetris->key_t,tetris));
    my_printf("Key drop: %s (%d)\n", tetris->key_d,
    get_key(tetris->key_d,tetris));
    my_printf("Key quit: %s (%d)\n", tetris->key_q,
    get_key(tetris->key_q,tetris));
    my_printf("Key pause: %s (%d)\n", tetris->key_p,
    get_key(tetris->key_p,tetris));
    my_printf("Next: %s\n", tetris->hide_n == 1 ? "No" : "Yes");
    my_printf("Level: %d\n", tetris->level);
    my_printf("Size: %s*%s\n\n", tetris->row, tetris->col);
}
