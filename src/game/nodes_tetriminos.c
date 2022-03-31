/*
** EPITECH PROJECT, 2022
** nodes_tetriminos
** File description:
** nodes_tetriminos
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

coordtetri_t *create_node_coord(char symbol, int x, int y)
{
    coordtetri_t *obj = malloc(sizeof(tetriminos_t));
    obj->symbol = symbol;
    obj->x = x;
    obj->y = y;
    obj->prev = NULL;
    obj->next = NULL;
    return obj;
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

coordtetri_t *create_tetri_coord(char **tetriminos, char color)
{
    int x = 0, y = 0;
    coordtetri_t *obj = create_node_coord(tetriminos[y][x], x, y);
    coordtetri_t *actual = NULL;
    coordtetri_t *tmp = obj;
    x += 1;
    for (y = 0; tetriminos[y] != NULL; y++) {
        for (; tetriminos[y][x] != '\0'; x++) {
            if (tetriminos[y][x] == '\n') {
                break;
            } else if (tetriminos[y][x] == ' ') {
                continue;
            } else {
                actual = create_node_coord(color, x, y);
                link_nodes_coord(tmp, actual);
                tmp = actual;
            }
        }
        x = 0;
    }
    return obj;
}

char **create_char_tab(int x, int y)
{
    char **array = malloc(sizeof(char *) * (y + 1));
    array[y] = NULL;
    for (int i = 0; i < y; i++) {
        array[i] = malloc(sizeof(char) * (x + 1));
        for (int j = 0; j < x; j++)
            array[i][j] = '*';
        array[i][x] = '\0';
    }
    for (int i = 0; i < y; i++)
        my_memset(array[i], 32, x);
    return array;
}

char *create_matrice_piece(char *tetriminos, int *sizepiece)
{
    int tmp = 0, width = 0, height = 1, size = 0;
    for (int i = 0; tetriminos[i] != '\0'; i++) {
        tmp = i;
        for (int j = 0; tetriminos[j] != '\n'; j++, tmp++);
        if (tmp - i > width) width = tmp - i;
        i += tmp;
    }
    for (int i = 0; tetriminos[i] != '\0'; i++)
        if (tetriminos[i] == '\n') width += 1;
    if (height > width) size = height;
    else size = width;
    char *new_piece = malloc(sizeof(char) * (((size + 1) * (size + 1)) + 1));
    my_memset(new_piece, 32, (size * size));
    new_piece[size * size] = '\0';
    for (int i = 0; tetriminos[i] != '\0'; i++)
        new_piece[i] = tetriminos[i];
    *sizepiece = size;
    return new_piece;
}

tetriminos_t *create_node(char *tetriminos, char color)
{
    tetriminos_t *obj = malloc(sizeof(tetriminos_t));
    char *tmppiece = create_matrice_piece(tetriminos, &obj->sizepiece);
    char **tabpiece = create_char_tab(obj->sizepiece + 1, obj->sizepiece + 1);
    printf("Size : %d\n", obj->sizepiece);
    int counter = 0;
    for (int y = 0; y < obj->sizepiece + 1; y++, counter++) {
        for (int x = 0; x < obj->sizepiece + 1 && tmppiece[counter] != '\n'; x++, counter++) {
            tabpiece[y][x] = tetriminos[counter];
        }
    }
    // for (int y = 0; tabpiece[y]; y++)
    //     printf("%s\n", tabpiece[y]);
    obj->piece = create_matrice_piece(tetriminos, &obj->sizepiece);
    obj->tabpiece = tabpiece;
    obj->color = color;
    obj->tetrimino = create_tetri_coord(tabpiece, color);
    obj->prev = NULL;
    obj->next = NULL;
    return obj;
}


tetriminos_t *create_list(char **tetriminos, char *color, int nbtetri)
{
    printf("Tetriminos : %s Color : %c Nbtetri : %d\n", tetriminos[0], color[0], nbtetri);
    tetriminos_t *obj = create_node(tetriminos[0], color[0]);
    tetriminos_t *actual = NULL;
    tetriminos_t *tmp = obj;
    for (int i = 1; i < nbtetri; i++) {
        printf("Tetriminos : %s Color : %c Nbtetri : %d\n", tetriminos[i], color[i], nbtetri);
        actual = create_node(tetriminos[i], color[i]);
        link_nodes(tmp, actual);
        tmp = actual;
    }
    return obj;
}
