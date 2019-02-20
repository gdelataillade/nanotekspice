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
			./src/Components/C4071.cpp	 \
			./src/Components/Input.cpp	\
			./src/Components/Output.cpp	\
			./src/Components/C4081.cpp	\
			./src/Components/C4011.cpp	\
			./src/Components/C4030.cpp	\
			./src/Components/C4001.cpp	\
			./src/Components/C4069.cpp	\
			./src/Components/Clock.cpp	\
			./src/Components/True.cpp		\
			./src/Components/False.cpp

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
tests_run :
				make -C ./tests
				./tests/unit_tests

.PHONY		:	all clean fclean re
