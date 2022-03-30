/*
** EPITECH PROJECT, 2022
** nodes_tetriminos
** File description:
** nodes_tetriminos
*/

#include "tetris.h"

int nb_tetrimino(tetris_t *tetris)
{
    int file_count = 0;
    DIR * dirp;
    struct dirent *entry;
    tetris->t_nb = 0;
    dirp = opendir("tetriminos/");
    while ((entry = readdir(dirp)) != NULL) {
        if (entry->d_type == DT_REG) {
            file_count++;
        }
    }
    tetris->tetriminos = malloc(sizeof(char *) * file_count);
    closedir(dirp);
    if (tetris->debug == 1)
        my_printf("Number of tetriminos: %d\n", file_count);
    return file_count;
}

tetriminos_t *create_node(char **tetriminos)
{
    tetriminos_t *obj = malloc(sizeof(tetriminos_t));
    obj->piece = tetriminos;
    obj->prev = NULL;
    obj->next = NULL;
    return obj;
}

void link_nodes(tetriminos_t *link1, tetriminos_t *link2)
{
    link1->next = link2;
    link2->prev = link1;
}

tetriminos_t *create_list(int nbtetri)
{
    for (int i = 0; i < nbtetri; i++) {
        create_node();
        if (i != 0)
    }
}
