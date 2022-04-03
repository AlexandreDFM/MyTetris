/*
** EPITECH PROJECT, 2022
** link_nodes
** File description:
** Function to link nodes
*/

#include "tetris.h"

void link_nodes(tetriminos_t *link1, tetriminos_t *link2)
{
    link1->next = link2;
    link2->prev = link1;
}

void link_nodes_coord(coordtetri_t *link1, coordtetri_t *link2)
{
    link1->next = link2;
    link2->prev = link1;
}
