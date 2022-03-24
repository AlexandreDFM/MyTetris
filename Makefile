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
		print_tetrimino.c					\
		help.c								\
		parse_flags.c 						\
		print_debug.c						\
		utils/my_read.c						\
		utils/my_memset.c 					\
		utils/my_strcpy.c					\
		utils/my_strdup.c					\
		utils/my_atoi.c						\
		utils/my_itoa.c						\
		utils/is_present.c					\

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
