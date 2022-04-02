/*
** EPITECH PROJECT, 2022
** Highscore
** File description:
** Functions to display and create highscore
*/

#include "tetris.h"

void create_highscore(tetris_g_t *tetris_g)
{
    char *highscore = get_lines("./highscore/highscore");
    tetris_g->highscore = my_atoi(highscore);
}

void open_write(tetris_g_t *tetris_g)
{
    char *newscore = my_itoa(tetris_g->score);
    int fd = open("./highscore/highscore", O_WRONLY);
    write(fd, newscore, my_strlen(newscore));
    write(fd, "\n", 1);
}

void check_highscore(tetris_g_t *tetris_g)
{
    if (tetris_g->highscore < tetris_g->score)
        open_write(tetris_g);
}

void display_highscore(WINDOW *tetris, tetris_g_t *tetris_g)
{
    if (tetris_g->highscore > tetris_g->score) {
        mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + 10,
        COLS / 2 - tetris_g->width / 2 + 21, "%d", tetris_g->highscore);
    } else {
        mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + 10,
        COLS / 2 - tetris_g->width / 2 + 21, "%d", tetris_g->score);
    }
    mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + 11,
    COLS / 2 - tetris_g->width / 2 + 21, "%d", tetris_g->score);
}
