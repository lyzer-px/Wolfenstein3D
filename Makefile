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

CFLAGS		=		-Wall -Wextra -Wpedantic -I include

CPPFLAGS	+=		-lcsfml-audio -lcsfml-graphics
CPPFLAGS	+=		-lcsfml-network -lcsfml-system -lcsfml-window -lm

DEBUG_FLAGS		=	-g3

LDLIBS +=	-lmy -lgraphic

LDFLAGS	+=	-Lutils/

all:		$(NAME)

$(NAME):	$(OBJ)
	@echo "\n"
	@make -C utils/my all
	@echo "\n"
	@make -C utils/graphic all
	@echo "\n"
	$(CC) $(OBJ) -o $(NAME)  $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

clean:
	@make -C utils/my clean
	@echo "\n"
	@make -C utils/graphic clean
	@echo "\n"
	$(RM) $(OBJ)

fclean: clean
	@echo "\n"
	@make -C utils/my fclean
	@echo "\n"
	@make -C utils/graphic fclean
	@echo "\n"
	$(RM) -f $(NAME)

re:	fclean all
	@echo "\n"
	@make -C utils/my re
	@echo "\n"
	@make -C utils/graphic re

debug_comp:		$(OBJ)
	$(CC) $(OBJ) -o $(NAME)  $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)	\
	$(DEBUG_FLAGS)

debug:	debug_comp clean
	@echo "\n"
	@make -C utils/my debug
	@echo "\n"
	@make -C utils/graphic debug

tests_run:
	@make -C utils/my tests_run
	@echo "\n"
	@make -C utils/graphic tests_run
	@echo "\n"
	@mkdir -p tests
	@if [ ! -f tests/*.c ]; then \
		echo "Error: tests/*.c not found"; \
		exit 1; \
	fi
	@gcc -o unit_tests $(SRC) tests/*.c --coverage -lcriterion -Iinclude
	./unit_tests

coverage: tests_run
	@echo "\n"
	@make -C utils/my coverage
	@echo "\n"
	@make -C utils/graphic coverage
	@echo "\n"
	gcovr
	@find -name "*.gcda" -delete -o -name "*.gcno" -delete
	@find -name "unit_tests"	-delete

coding_style: fclean
	coding-style . .
	@cat coding-style-reports.log
	@rm -f "coding-style-reports.log";
