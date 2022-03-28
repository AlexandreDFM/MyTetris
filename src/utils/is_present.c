/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCE-2-1-tetris-antoine.frankel
** File description:
** is_present
*/

#include "tetris.h"

int is_present(char **array, char *str, int check)
{
    for (int i = 0; array[i] != NULL; i++) {
        if (check == 1 && my_strcmp(array[i], str) == 0) {
            return 1;
        }
        if (check == 2 && my_strncmp(array[i], str, my_strlen(array[i])) == 0){
            return 1;
        }
    }
    return -1;
}
