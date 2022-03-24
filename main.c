/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** tetris
*/

#include "tetris.h"

void init(tetris_t *tetris)
{
    tetris->key_l = my_strdup("KEY_LEFT");
    tetris->key_r = my_strdup("KEY_RIGHT");
    tetris->key_t = my_strdup("KEY_UP");
    tetris->key_d = my_strdup("KEY_DOWN");
    tetris->key_q = my_strdup("q");
    tetris->key_p = my_strdup(" ");
    tetris->hide_n = 0;
    tetris->level = 1;
    tetris->row = my_strdup("20");
    tetris->col = my_strdup("10");
    static char *keys[5] = {"KEY_LEFT\0", "KEY_RIGHT\0", "KEY_UP\0",
    "KEY_DOWN\0"};
    static int key_nb[5] = {260, 261, 259, 258};
    tetris->keys = keys;
    tetris->key_nb = key_nb;
}

void check_flags(int ac, char **av, char **s_flags, char **l_flags)
{
    for (int i = 1; i < ac; i++) {
        if (is_present(s_flags, av[i], 1) != -1) {
            i += 2;
        } else if (is_present(l_flags, av[i], 2) != -1){
            i++;
        } else {
            exit(84);
        }
    }
}

void main(int ac, char **av)
{
    int key = 0;
    tetris_t tetris;
    static char *s_flags[9] = {"-L", "-l", "-r", "-t", "-d", "-q", "-p", "-w",
    "-D"};
    static char *l_flags[11] = {"--help", "--level=", "--key-left=",
    "--key-right=", "--key-turn=", "--key-drop=", "--key-quit=",
    "--key-pause=", "--map-size=", "--without-next", "--debug"};
    check_flags(ac, av, s_flags, l_flags);
    init(&tetris);
    parse_flags(ac, av, &tetris, 1);
    if (tetris.debug == 1)
        print_debug(&tetris);
    count_tetrimino(&tetris);
}
