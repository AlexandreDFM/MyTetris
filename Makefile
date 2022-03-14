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
		my_read.c							\
		my_memset.c 						\

OBJ    = $(SRC:.c=.o)

CFLAGS += -Wall -pedantic -I./include -g3

LIBFLAG    = -L ./lib/my/ -lmy -I ./include -g3
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
