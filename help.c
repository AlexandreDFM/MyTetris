/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCE-2-1-tetris-antoine.frankel
** File description:
** help
*/

#include "tetris.h"

void help(void)
{
    my_printf("Usage: ./tetris [options]\n"
    "Options:\n  --help Display this help\n"
    "  -L --level={num} Start Tetris at level num (def: 1)\n"
    "  -l --key-left={K} Move the tetrimino LEFT using the K key "
    "(def: left arrow)\n"
    "  -r --key-right={K} Move the tetrimino RIGHT using the K key "
    "(def: right arrow)\n"
    "  -t --key-turn={K} TURN the tetrimino clockwise 90d using the K key "
    "(def: top arrow)\n"
    "  -d --key-drop={K} DROP the tetrimino using the K key "
    "(def: down arrow)\n"
    "  -q --key-quit={K} QUIT the game using the K key (def: ‘q’ key)\n"
    "  -p --key-pause={K} PAUSE/RESTART the game using the K key "
    "(def: space bar)\n"
    "  --map-size={row,col} Set the numbers of rows and columns of the map "
    "(def: 20,10)\n"
    "  -w --without-next Hide next tetrimino (def: false)\n"
    "  -D --debug Debug mode (def: false)\n");
    exit (0);
}