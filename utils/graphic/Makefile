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

all:		$(NAME)

$(NAME):	$(OBJ)
		$(AR) rc $(NAME) $(OBJ)
		cp $(NAME) ../
		cp $(HEADER) ../../include/

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) -f $(NAME) ../$(NAME)

re:	fclean all

debug:	all clean

tests_run:
	@echo "Hello, we are happy to say that we didn't have any tests"
#	@mkdir -p tests
#	@if [ ! -f tests/*.c ]; then \
#		echo "Error: tests/*.c not found"; \
#		exit 1; \
#	fi
#	@gcc -o unit_tests $(SRC) tests/*.c --coverage -lcriterion -Iinclude
#	./unit_tests

coverage: tests_run
	gcovr
	@find -name "*.gcda" -delete -o -name "*.gcno" -delete
	@find -name "unit_tests"	-delete

coding_style:
	coding-style . .
	@cat coding-style-reports.log
	@rm -f "coding-style-reports.log";
