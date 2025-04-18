##
## EPITECH PROJECT, 2024
## make lib
## File description:
## make lib
##

#
# HELP TO BUILD
#

CP			?=	cp

RM			?=	rm -rf

#
# BINARY CREATION
#

SRC 		= 		make_window.c				\
					create_button.c				\
					del_tab_button.c			\
					draw_button.c				\
					get_pos.c

OBJ			=		$(SRC:.c=.o)

NAME		=		libgraphic.a

HEADER	=	libgraphic.h

CFLAGS		=		-Wall -Wextra -Wpedantic

UT_SRC =	tests/graphics_test.c

UT_NAME	=	graphics_tests

UT_FLAGS	=	--coverage -lcriterion

all:		$(NAME)

$(NAME):	$(OBJ)
	$(AR) rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp $(HEADER) ../../include/
#	@ranlib $(LIB_NAME)

clean:
	$(RM) $(OBJ)
	@find -name "*~" -delete -o -name "#*#" -delete
	@find -name "*.gcda" -delete -o -name "*.gcno" -delete

fclean: clean
	$(RM) -f $(NAME) ../$(NAME) $(UT_NAME)
	@find -name "coding-style-reports.log" -delete

re:	fclean all

debug:	all clean

tests_run:
	$(CC) -o $(UT_NAME) $(UT_SRC) $(UT_FLAGS) $(CFLAGS)
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
		coding_style	\
		final_check
