##
## EPITECH PROJECT, 2019
## cpp_d13_2018
## File description:
## Makefile
##

SRC_CLASS	=	../src/Parser.cpp \
				../src/Circuit.cpp \
				../src/Component.cpp	\
			../src/Components/C4071.cpp	 \
			../src/Components/Input.cpp	\
			../src/Components/Output.cpp	\
			../src/Components/C4081.cpp	\
			../src/Components/C4011.cpp	\
			../src/Components/C4030.cpp	\
			../src/Components/C4001.cpp	\
			../src/Components/C4069.cpp	\
			../src/Components/Clock.cpp	\
			../src/Components/True.cpp		\
			../src/Exception.cpp \
			../src/Components/False.cpp

SRC		=	$(SRC_CLASS)	\
				./src/gate.cpp


NAME	=	unit_tests

CXX	=	g++

INCLUDE	=	-I../include/

CXXFLAGS	=	$(INCLUDE) -Wall -fprofile-arcs -ftest-coverage -fPIC
LDFLAGS = --coverage -lcriterion 

OBJ = $(SRC:.cpp=.o)

$(NAME):	$(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)
	@echo "COMPILATION: OK"

.SILENT:

all:	$(NAME)

clean:
	@rm -f $(OBJ)
	@echo "CLEAN: OK"

fclean:	clean
	@rm -f $(NAME)
	@echo "FCLEAN: OK"

re:	fclean all

.PHONY:	all clean fclean re
