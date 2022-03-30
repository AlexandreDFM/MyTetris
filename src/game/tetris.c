/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** tetris
*/

#include "tetris.h"

void game(tetris_g_t *tetris_g, WINDOW *tetris)
{
    int input = 0;
    while (1) {
        clear();
        for (int y = 0; tetris_g->interface[y] != NULL; y++) {
            for (int x = 0; tetris_g->interface[y][x] != '\0'; x++) {
                switch (tetris_g->interface[y][x]) {
                case '1':
                    attron(COLOR_PAIR(1));
                    mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + y, COLS / 2 - tetris_g->width / 2 + x, "%c", ' ');
                    attroff(COLOR_PAIR(1));
                    break;
                case '2':
                    attron(COLOR_PAIR(2));
                    mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + y, COLS / 2 - tetris_g->width / 2 + x, "%c", ' ');
                    attroff(COLOR_PAIR(2));
                    break;
                case '3':
                    attron(COLOR_PAIR(3));
                    mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + y, COLS / 2 - tetris_g->width / 2 + x, "%c", ' ');
                    attroff(COLOR_PAIR(3));
                    break;
                case '4':
                    attron(COLOR_PAIR(4));
                    mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + y, COLS / 2 - tetris_g->width / 2 + x, "%c", ' ');
                    attroff(COLOR_PAIR(4));
                    break;
                case '5':
                    attron(COLOR_PAIR(5));
                    mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + y, COLS / 2 - tetris_g->width / 2 + x, "%c", ' ');
                    attroff(COLOR_PAIR(5));
                    break;
                case '6':
                    attron(COLOR_PAIR(6));
                    mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + y, COLS / 2 - tetris_g->width / 2 + x, "%c", ' ');
                    attroff(COLOR_PAIR(6));
                    break;
                case '7':
                    attron(COLOR_PAIR(7));
                    mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + y, COLS / 2 - tetris_g->width / 2 + x, "%c", ' ');
                    attroff(COLOR_PAIR(7));
                    break;
                default:
                    mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + y, COLS / 2 - tetris_g->width / 2 + x, "%c", tetris_g->interface[y][x]);
                    break;
                }
            }
            printw("\n");
        }
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

void tetris()
{
    WINDOW *tetris = initscr();
    tetris_g_t tetris_g;
    tetris_g.interface = my_strtwa(get_lines("./interface/interface"), "\n");
    tetris_g.height = 0, tetris_g.width = 0, tetris_g.highscore = 0,
    tetris_g.score = 0, tetris_g.lines = 0, tetris_g.level = 0,
    tetris_g.timermins = 0, tetris_g.timersecondes = 0;
    for (tetris_g.height; tetris_g.interface[tetris_g.height] != NULL; tetris_g.height++);
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