##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## go go
##

SRC 	=	src/my_hunter.c	\
			src/display.c	\
			src/option_h.c	\
			src/event.c	\
			src/util.c	\
			src/mini_printf.c	\
			src/move.c	\
			src/display2.c

OBJ 	= 	$(SRC:.c=.o)

NAME 	=	my_hunter

all: 	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-window -lcsfml-system

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : 	fclean all
