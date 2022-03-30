/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** tetris
*/

#include "tetris.h"

void color_printing(WINDOW *tetris, tetris_g_t *tetris_g, int y, int x)
{
    switch (tetris_g->interface[y][x]) {
        case '1': case '2': case '3': case '4': case '5': case '6': case '7':
            attron(COLOR_PAIR((int) (tetris_g->interface[y][x]) - 48));
            mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + y,
            COLS / 2 - tetris_g->width / 2 + x, "%c", ' ');
            attroff(COLOR_PAIR((int) tetris_g->interface[y][x] - 48));
            break;
        default:
            mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + y,
            COLS / 2 - tetris_g->width / 2 + x, "%c",
            tetris_g->interface[y][x]);
            break;
    }
}

void print_scores(WINDOW *tetris, tetris_g_t *tetris_g)
{
    mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + 10, COLS / 2 - tetris_g->width / 2 + 21, "%d", tetris_g->highscore);
    mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + 11, COLS / 2 - tetris_g->width / 2 + 21, "%d", tetris_g->score);
    mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + 13, COLS / 2 - tetris_g->width / 2 + 21, "%d", tetris_g->lines);
    mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + 14, COLS / 2 - tetris_g->width / 2 + 21, "%d", tetris_g->level);
    if (tetris_g->timermins < 10) {
        mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + 19, COLS / 2 - tetris_g->width / 2 + 17, "0");
        mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + 19, COLS / 2 - tetris_g->width / 2 + 18, "%d:", tetris_g->timermins);
    } else {
        mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + 19, COLS / 2 - tetris_g->width / 2 + 17, "%d:", tetris_g->timermins);
    }
    if (tetris_g->timersecondes < 10) {
        mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + 19, COLS / 2 - tetris_g->width / 2 + 20, "0");
        mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + 19, COLS / 2 - tetris_g->width / 2 + 21, "%d", tetris_g->timersecondes);
    } else {
        mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + 19, COLS / 2 - tetris_g->width / 2 + 20, "%d", tetris_g->timersecondes);
    }
}

void print_interfaces(WINDOW *tetris, tetris_g_t *tetris_g)
{
    for (int y = 0; tetris_g->interface[y] != NULL; y++) {
        for (int x = 0; tetris_g->interface[y][x] != '\0'; x++) {
            color_printing(tetris, tetris_g, y, x);
        }
        printw("\n");
    }
    print_scores(tetris, tetris_g);
}

void game(tetris_g_t *tetris_g, WINDOW *tetris)
{
    int input = 0;
    while (1) {
        clear();
        print_interfaces(tetris, tetris_g);
        refresh();
        input = wgetch(tetris);
        usleep(1000000);
        tetris_g->timersecondes += 1;
        if (tetris_g->timersecondes > 59) {
            tetris_g->timersecondes = 0;
            tetris_g->timermins += 1;
        }
    }
}

void init_tetris()
{
    WINDOW *tetris = initscr();
    tetris_g_t tetris_g;
    tetris_g.interface = my_strtwa(get_lines("./interface/interface"), "\n");
    tetris_g.height = 0, tetris_g.width = 0, tetris_g.highscore = 0,
    tetris_g.score = 0, tetris_g.lines = 0, tetris_g.level = 0,
    tetris_g.timermins = 0, tetris_g.timersecondes = 0;
    for (tetris_g.height; tetris_g.interface[tetris_g.height] != NULL;
    tetris_g.height++);
    tetris_g.width = my_strlen(tetris_g.interface[0]);
    // tetris_g.interface1 = get_lines("./interface/interface");
    keypad(tetris, TRUE);
    nodelay(tetris, TRUE);
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_BLACK, COLOR_RED);
    init_pair(3, COLOR_BLACK, COLOR_BLUE);
    init_pair(4, COLOR_BLACK, COLOR_YELLOW);
    init_pair(5, COLOR_BLACK, COLOR_GREEN);
    init_pair(6, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(7, COLOR_BLACK, COLOR_CYAN);
    curs_set(0);
    game(&tetris_g, tetris);
    endwin();
    free(tetris);
}
