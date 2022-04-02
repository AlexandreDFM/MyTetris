/*
** EPITECH PROJECT, 2022
** my_color_print
** File description:
** Print interfaces in colors
*/

#include "tetris.h"

void color_printingleft(WINDOW *tetris, tetris_g_t *tetris_g, int y, int x)
{
    switch (tetris_g->interfaceleft[y][x]) {
        case '1': case '2': case '3': case '4': case '5': case '6': case '7':
            attron(COLOR_PAIR((int) (tetris_g->interfaceleft[y][x]) - 48));
            mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + y,
            COLS / 2 - tetris_g->width / 2 + x, "%c", ' ');
            attroff(COLOR_PAIR((int) tetris_g->interfaceleft[y][x] - 48));
            break;
        default:
            mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + y,
            COLS / 2 - tetris_g->width / 2 + x, "%c",
            tetris_g->interfaceleft[y][x]);
            break;
    }
}

void color_printinggrid(WINDOW *tetris, tetris_g_t *tetris_g, int y, int x)
{
    switch (tetris_g->grid[y][x]) {
        case '1': case '2': case '3': case '4': case '5': case '6': case '7':
            attron(COLOR_PAIR((int) (tetris_g->grid[y][x]) - 48));
            mvwprintw(tetris, LINES / 2 - (tetris_g->height / 2) + y,
            COLS / 2 - tetris_g->width / 2 +
            (my_strlen(tetris_g->interfaceleft[0])) + x, "%c", ' ');
            attroff(COLOR_PAIR((int) tetris_g->grid[y][x] - 48));
            break;
        default:
            mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + y,
            COLS / 2 - tetris_g->width / 2 +
            (my_strlen(tetris_g->interfaceleft[0])) + x, "%c",
            tetris_g->grid[y][x]);
            break;
    }
}

void color_printingright(WINDOW *tetris, tetris_g_t *tetris_g, int y, int x)
{
    switch (tetris_g->interfaceright[y][x]) {
        case '1': case '2': case '3': case '4': case '5': case '6': case '7':
            attron(COLOR_PAIR((int) (tetris_g->interfaceright[y][x]) - 48));
            mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + y,
            COLS / 2 - tetris_g->width / 2 +
            (my_strlen(tetris_g->interfaceleft[0]))
            + (my_strlen(tetris_g->grid[0])) + x, "%c", ' ');
            attroff(COLOR_PAIR((int) tetris_g->interfaceright[y][x] - 48));
            break;
        default:
            mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + y,
            COLS / 2 - tetris_g->width / 2 +
            (my_strlen(tetris_g->interfaceleft[0]))
            + (my_strlen(tetris_g->grid[0])) + x, "%c",
            tetris_g->interfaceright[y][x]);
            break;
    }
}

void print_scores(WINDOW *tetris, tetris_g_t *tetris_g)
{
    display_highscore(tetris, tetris_g);
    mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + 13,
    COLS / 2 - tetris_g->width / 2 + 21, "%d", tetris_g->lines);
    mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + 14,
    COLS / 2 - tetris_g->width / 2 + 21, "%d", tetris_g->level);
    if (tetris_g->timermins < 10) {
        mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + 19,
        COLS / 2 - tetris_g->width / 2 + 17, "0");
        mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + 19,
        COLS / 2 - tetris_g->width / 2 + 18, "%d:", tetris_g->timermins);
    } else {
        mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + 19,
        COLS / 2 - tetris_g->width / 2 + 17, "%d:", tetris_g->timermins);
    }
    if (tetris_g->timersecondes < 10) {
        mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + 19,
        COLS / 2 - tetris_g->width / 2 + 20, "0");
        mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + 19,
        COLS / 2 - tetris_g->width / 2 + 21, "%d", tetris_g->timersecondes);
    } else {
        mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + 19,
        COLS / 2 - tetris_g->width / 2 + 20, "%ld", tetris_g->timersecondes);
    }
}

void print_interfaces(WINDOW *tetris, tetris_g_t *tetris_g)
{
    for (int y = 0; tetris_g->interfaceleft[y] != NULL; y++) {
        for (int x = 0; tetris_g->interfaceleft[y][x] != '\0'; x++) {
            color_printingleft(tetris, tetris_g, y, x);
        }
        printw("\n");
    }
    for (int y = 0; tetris_g->grid[y] != NULL; y++) {
        for (int x = 0; tetris_g->grid[y][x] != '\0'; x++) {
            color_printinggrid(tetris, tetris_g, y, x);
        }
        printw("\n");
    }
    for (int y = 0; tetris_g->interfaceright[y] != NULL; y++) {
        for (int x = 0; tetris_g->interfaceright[y][x] != '\0'; x++) {
            color_printingright(tetris, tetris_g, y, x);
        }
        printw("\n");
    }
    print_scores(tetris, tetris_g);
}
