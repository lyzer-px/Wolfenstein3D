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
					change_the_mode_window.c 	\
					create_window.c				\
					init_game.c					\
					add_an_element_to_scene.c	\
					destroy_tab_scene.c			\
					draw_composant_of_scene.c	\
					destroy_game.c				\
					init_tab_scene.c			\
					destroy_window.c			\
					rev_composant.c				\
					add_composant_to_layer.c	\
					create_composant.c			\
					change_the_mode_window.c

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
	cp $(NAME) ../..
	cp $(HEADER) ../../include/
#	@ranlib $(LIB_NAME)

clean:
	$(RM) $(OBJ)
	@find -name "*~" -delete -o -name "#*#" -delete
	@find -name "*.gcda" -delete -o -name "*.gcno" -delete

fclean: clean
	$(RM) -f $(NAME) ../../$(NAME) $(UT_NAME)
	@find -name "coding-style-reports.log" -delete

re:	fclean all

debug:	re clean

.PHONY: all				\
		re				\
		fclean			\
		clean
