##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC		=	$(wildcard ./src/*.c) \
			$(wildcard ./src/*/*.c)

HEAD	=	$(wildcard ./include/*.h)

OBJ		=	$(SRC:.c=.o)

NAME	=	my_sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(HEAD) -lncurses -Wall -Wextra

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
