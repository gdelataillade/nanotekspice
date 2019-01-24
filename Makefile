##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Standard Makefile for compile the project.
##

SRC_CLASS	=	

SRC		=	$(SRC_CLASS)	\
			./src/main.cpp \
                        ./src/Parser.cpp \
                        ./src/Circuit.cpp \
                        ./src/Component.cpp	\
						./src/Factory.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME		=	nanotekspice

CC		=	g++

INCLUDE		=	-I./include/		\
				-I./include/Components

CPPFLAGS	=	$(INCLUDE) -std=c++17 -Wall -Wextra -g

$(NAME)		:	$(OBJ)
			$(CC) -o $(NAME) $(OBJ)
			@echo "COMPILATION: OK"

.SILENT		:

all		:	$(NAME)

clean		:
			@rm -f $(OBJ)
			@echo "CLEAN: OK"

fclean		:	clean
			@rm -f $(NAME)
                        @echo "FCLEAN: OK"

re		:	fclean all

.PHONY		:	all clean fclean re
