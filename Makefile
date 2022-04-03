##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## file making
##

NAME    = tetris

CC    = gcc

RM    = rm -f

SRC    = main.c								\
		src/print_tetrimino.c				\
		src/help.c							\
		src/parse_flags.c 					\
		src/print_debug.c					\
		src/game/tetris.c					\
		src/game/create_grid.c				\
		src/game/grid_manager.c				\
		src/game/nodes_tetriminos.c			\
		src/game/check_lose.c				\
		src/game/mouvement.c				\
		src/game/highscore.c				\
		src/game/my_color_print.c			\
		src/game/init_tetris_game.c			\
		src/game/link_nodes.c				\
		src/game/my_free_tetrimino.c		\
		src/game/my_get_size_tetri.c		\
		src/game/my_print_tetriminos.c		\
		src/utils/my_read.c					\
		src/utils/my_memset.c 				\
		src/utils/my_strcpy.c				\
		src/utils/my_strdup.c				\
		src/utils/my_atoi.c					\
		src/utils/my_itoa.c					\
		src/utils/my_strtwa.c				\
		src/utils/is_present.c				\

OBJ    = $(SRC:.c=.o)

CFLAGS += -pedantic -I./include -g3

LIBFLAG    = -L ./lib/my/ -lmy -I ./include -g3 -lncurses
all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./lib/my
	@$(CC) $(SRC) -o $(NAME) $(LIBFLAG) -lm

clean:
	@$(RM) $(OBJ)
	@make -C ./lib/my fclean

fclean:
	@$(RM) $(NAME)
	@$(RM) $(OBJ)

re: fclean all
