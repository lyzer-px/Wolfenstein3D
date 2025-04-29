##
## EPITECH PROJECT, 2024
## make lib
## File description:
## make lib
##

#
# HELP TO BUILD
#

CC 			?=	gcc

CP			?=	cp

RM			?=	rm -rf

#
# BINARY CREATION
#

SRC 		= 		main.c											\
					src/handle_event.c								\
					src/init_program.c								\
					src/loop.c										\
					src/check_env.c									\
					src/project.c									\
					src/print_help.c

OBJ			=		$(SRC:.c=.o)

NAME		=		wolf3d

CFLAGS		=		-Wall -Wextra -Wpedantic -iquote include \
              -std=c99


CPPFLAGS	+=		-iquote include
CPPFLAGS	+=		-lcsfml-audio -lcsfml-graphics
CPPFLAGS	+=		-lcsfml-network -lcsfml-system -lcsfml-window -lm

DEBUG		=	-g3

LDLIBS +=	-lmy -lgraphic

LDFLAGS	+=	-L.

UT_SRC =	tests/wolfenstein_test.c		\
			tests/my_test.c					\
			utils/my/my_strlen.c

UT_NAME	=	unit_tests

UT_FLAGS	=	--coverage -lcriterion

all:		$(NAME)

$(NAME):	$(OBJ)
	@echo "\n"
	@make -C utils/my all
	@echo "\n"
	@make -C utils/graphic all
	@echo "\n"
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

clean:
	@make -C utils/my clean
	@echo "\n"
	@make -C utils/graphic clean
	@echo "\n"
	$(RM) $(OBJ)
	@find -name "*~" -delete -o -name "#*#" -delete
	@find -name "*.gcda" -delete -o -name "*.gcno" -delete


fclean: clean
	@echo "\n"
	@make -C utils/my fclean
	@echo "\n"
	@make -C utils/graphic fclean
	@echo "\n"
	$(RM) -f $(NAME)
	@find -name "coding-style-reports.log" -delete

re:	fclean all
	@echo "\n"
	@make -C utils/my re
	@echo "\n"
	@make -C utils/graphic re

debug_comp:		$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(DEBUG) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

debug:
	@echo "\n"
	@make -C utils/my debug
	@echo "\n"
	@make -C utils/graphic debug
	@make debug_comp
	@make clean

tests_run:
	$(CC) -o $(UT_NAME) $(UT_SRC) $(UT_FLAGS) $(CFLAGS) $(CPPFLAGS)
	./$(UT_NAME)

coverage: tests_run
	gcovr --exclude test/
	@find -name "*.gcda" -delete -o -name "*.gcno" -delete
	@find -name $(UT_NAME) -delete

coding_style: fclean
	coding-style . .
	@cat coding-style-reports.log
	@$(RM) -f "coding-style-reports.log";

.PHONY: all				\
		re				\
		fclean			\
		clean			\
		tests_run 		\
		coverage 		\
		coding_style
