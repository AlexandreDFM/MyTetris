/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** tetris
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
            COLS / 2 - tetris_g->width / 2 + (my_strlen(tetris_g->interfaceleft[0])) + x, "%c", ' ');
            attroff(COLOR_PAIR((int) tetris_g->grid[y][x] - 48));
            break;
        default:
            mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + y,
            COLS / 2 - tetris_g->width / 2 + (my_strlen(tetris_g->interfaceleft[0])) + x, "%c",
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
            COLS / 2 - tetris_g->width / 2 + (my_strlen(tetris_g->interfaceleft[0])) + (my_strlen(tetris_g->grid[0])) + x, "%c", ' ');
            attroff(COLOR_PAIR((int) tetris_g->interfaceright[y][x] - 48));
            break;
        default:
            mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + y,
            COLS / 2 - tetris_g->width / 2 + (my_strlen(tetris_g->interfaceleft[0])) + (my_strlen(tetris_g->grid[0])) + x, "%c",
            tetris_g->interfaceright[y][x]);
            break;
    }
}

void print_scores(WINDOW *tetris, tetris_g_t *tetris_g)
{
    mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + 10,
    COLS / 2 - tetris_g->width / 2 + 21, "%d", tetris_g->highscore);
    mvwprintw(tetris, LINES / 2 - tetris_g->height / 2 + 11,
    COLS / 2 - tetris_g->width / 2 + 21, "%d", tetris_g->score);
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

void print_tetriminos(WINDOW *tetris, tetris_g_t *tetris_g)
{
    coordtetri_t *actual = tetris_g->actual_tetri->tetrimino;
    while (actual != NULL) {
        attron(COLOR_PAIR((int) actual->symbol - 48));
        mvwprintw(tetris, LINES / 2 - (tetris_g->height / 2) + tetris_g->yactual_tetri + actual->y,
        COLS / 2 - tetris_g->width / 2 + (my_strlen(tetris_g->interfaceleft[0]))
        + tetris_g->xactual_tetri + actual->x, "%c", ' ');
        attroff(COLOR_PAIR((int) actual->symbol - 48));
        actual = actual->next;
    }
}

void time_gestionnary(tetris_g_t *tetris_g)
{
    tetris_g->end = clock();
    if ((tetris_g->end - tetris_g->begin) / CLOCKS_PER_SEC > 1 ) {
        clear();
        refresh();
        tetris_g->begin = clock();
        tetris_g->yactual_tetri += 1;
        tetris_g->timersecondes += 1;
        if (tetris_g->timersecondes > 59) {
            tetris_g->timersecondes = 0;
            tetris_g->timermins += 1;
        }
    }
}

void rotate_tetri2(WINDOW *tetris, tetris_g_t *tetris_g)
{
    int backspacecounter = 0, size = tetris_g->actual_tetri->sizepiece;
    char replace = ' ';
    char *tmp = my_strdup(tetris_g->actual_tetri->piece);
    for (int i = 0; tmp[i] != '\0'; i++) {
        for (int j = 0; j < size - 1; j++) {
            replace = tmp[j];
            tetris_g->actual_tetri->piece[j] = ' ';
            if (replace == '\n') {
                tetris_g->actual_tetri->piece[size * backspacecounter] = '\n';
                continue;
            } else {
                tetris_g->actual_tetri->piece[size - (j + 1)] = replace;
            }
        }
    }
    printf("%s", tetris_g->actual_tetri->piece);
    tetris_g->actual_tetri->tetrimino =
    create_tetri_coord(tetris_g->actual_tetri->piece, tetris_g->actual_tetri->color);
    tetris_g->xactual_tetri - size;
    free(tmp);
}

void rotate_tetri(WINDOW *tetris, tetris_g_t *tetris_g)
{
    int size = tetris_g->actual_tetri->sizepiece;
    char **tmptabpiece = create_char_tab(size + 1, size + 1);
    for (int y = 0; y <= size; y++) {
        for (int x = 0; x <= size; x++)
            tmptabpiece[y][x] = tetris_g->actual_tetri->tabpiece[y][x];
    }
    for (int y = 0, i = 0; i <= size; y++, i++) {
        for (int x = 0, j = size; j >= 0; x++, j--) {
            tetris_g->actual_tetri->tabpiece[y][x] = tmptabpiece[j][i];
        }
    }
    tetris_g->actual_tetri->tetrimino =
    create_tetri_coord(tetris_g->actual_tetri->tabpiece,
    tetris_g->actual_tetri->color);
    tetris_g->xactual_tetri - size;
}

void pick_tetri(WINDOW *tetris, tetris_g_t *tetris_g)
{
    int i = 0;
    tetris_g->yactual_tetri = 1;
    int tetri = (rand() % tetris_g->nb_tetri - 1) + 1;
    tetriminos_t *tmp = tetris_g->tetriminos;
    tetriminos_t *actual = tmp;
    while (actual != NULL && i <= tetri) {
        tmp = actual;
        coordtetri_t *actual2 = actual->tetrimino;
        while (actual2 != NULL) {
            actual2 = actual2->next;
        }
        actual = actual->next;
        i++;
    }
    tetris_g->actual_tetri = create_node(tmp->piece, tmp->color);
    for (i = 0; tetris_g->actual_tetri->piece[i] != '\n'; i++);
    tetris_g->xactual_tetri = (my_strlen(tetris_g->grid[0]) - 2) / 2 - i;
}

void game(WINDOW *tetris, tetris_g_t *tetris_g)
{
    int input = 0;
    tetris_g->begin = clock();
    while (1) {
        if (LINES < tetris_g->height || COLS < tetris_g->width) {
            clear();
            mvwprintw(stdscr, LINES / 2, COLS / 2 - 10, "Wrong terminal size");
            refresh();
        } else {
            if (tetris_g->actual_tetri == NULL) pick_tetri(tetris, tetris_g);
            time_gestionnary(tetris_g);
            print_interfaces(tetris, tetris_g);
            if (tetris_g->actual_tetri != NULL) print_tetriminos(tetris, tetris_g);
        }
        input = wgetch(tetris);
        if (inputs_manager(tetris, tetris_g, input) == 84) return 84;
    }
}

void init_tetris(tetris_t *tetris_stats)
{
    tetris_g_t tetris_g;
    tetris_g.level = tetris_stats->level <= 1 ? 1 : tetris_stats->level;
    tetris_g.tetriminos = create_list(tetris_stats->tetriminos, tetris_stats->color, tetris_stats->total);
    tetris_g.actual_tetri = NULL;
    tetris_g.nb_tetri = tetris_stats->total;
    tetriminos_t *tmp = tetris_g.tetriminos;
    tetriminos_t *actual = tmp;
    while (actual != NULL) {
        // for (int y = 0; actual->piece[y] != '\0'; y++) {
        //     printf("%c", actual->piece[y]);
        // }
        coordtetri_t *actual2 = actual->tetrimino;
        while (actual2 != NULL) {
            printf("Symbol : %c X : %d Y : %d\n", actual2->symbol, actual2->x, actual2->y);
            actual2 = actual2->next;
        }
        actual = actual->next;
    }
    // return;
    WINDOW *tetris = initscr();
    tetris_g.interfaceleft = my_strtwa(get_lines("./interface/interface_1"), "\n");
    tetris_g.grid = create_grid(37, 29);
    tetris_g.interfaceright = create_next_grid(10, 10);
    tetris_g.height = 0, tetris_g.width = 0, tetris_g.highscore = 0,
    tetris_g.score = 0, tetris_g.lines = 0,
    tetris_g.timermins = 0, tetris_g.timersecondes = 0;
    for (int x = 0; tetris_g.interfaceleft[x] != NULL;
    x++, tetris_g.height++);
    int size = 0;
    for (int x = 0; tetris_g.grid[x] != NULL;
    x++, size++);
    if (size > tetris_g.height)
        tetris_g.height = size;
    for (int x = 0, size = 0; tetris_g.interfaceright[x] != NULL;
    x++, size++);
    if (size > tetris_g.height)
        tetris_g.height = size;
    tetris_g.width = my_strlen(tetris_g.interfaceleft[0]);
    tetris_g.width += my_strlen(tetris_g.grid[0]);
    tetris_g.width += my_strlen(tetris_g.interfaceright[0]);
    keypad(tetris, TRUE);
    nodelay(tetris, TRUE);
    start_color();
    noecho();
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_BLACK, COLOR_RED);
    init_pair(3, COLOR_BLACK, COLOR_BLUE);
    init_pair(4, COLOR_BLACK, COLOR_YELLOW);
    init_pair(5, COLOR_BLACK, COLOR_GREEN);
    init_pair(6, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(7, COLOR_BLACK, COLOR_CYAN);
    curs_set(0);
    game(tetris, &tetris_g);
    endwin();
    delwin(tetris);
}
