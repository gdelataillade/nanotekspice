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
						./src/Components/C4071.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME		=	nanotekspice

CC		=	g++

INCLUDE		=	-I./include/

CPPFLAGS	=	$(INCLUDE) -std=c++17 -Wall -g

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
