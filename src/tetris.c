/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** tetris
*/

#include "tetris.h"

void game(tetris_g_t *tetris_g, WINDOW *tetris, WINDOW * inputs)
{
    int input = 0;
    int oldinput = 0;
    int i = 0;
    while (1) {
        clear();
        i++;
        // for (int i = 0; tetris_g->interface[i] != NULL; i++)
        //     printw(tetris_g->interface[i]);
        mvwprintw(tetris, LINES/2 - 1, (COLS / 2), "%d█", i);
        mvwprintw(tetris, LINES/2, (COLS / 2), "%d", input);
        refresh();
        input = wgetch(tetris);
        input = input > 0 ? input : oldinput;
        oldinput = input > 0 ? input : oldinput;
        usleep(1000);
    }
}

void tetris()
{
    WINDOW *tetris = initscr();
    WINDOW *inputs = initscr();
    tetris_g_t tetris_g;
    tetris_g.interface = my_strtwa(get_lines("./interface/interface"), "\n");
    nodelay(tetris, TRUE);
    curs_set(0);
    game(&tetris_g, tetris, inputs);
    endwin();
    free(tetris);
}
