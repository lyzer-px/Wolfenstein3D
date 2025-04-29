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

SRC 		= 		add_an_element_to_scene.c		\
					add_composant_to_layer.c		\
					change_the_mode_window.c		\
					clean_game.c					\
					clean_layer.c					\
					clean_scene.c					\
					create_composant.c				\
					create_layer.c					\
					create_window.c					\
					destroy_layer.c					\
					destroy_composant.c				\
					destroy_game.c					\
					destroy_scene.c					\
					destroy_tab_scene.c				\
					destroy_window.c				\
					draw_composant_of_scene.c		\
					init_game.c						\
					init_tab_scene.c				\
					make_window.c					\
					rev_composant.c

OBJ			=		$(SRC:.c=.o)

NAME		=		libgraphic.a

HEADER	=	libgraphic.h

CFLAGS		=		-Wall -Wextra -Wpedantic

UT_SRC =	tests/graphics_test.c

UT_NAME	=	graphics_tests

UT_FLAGS	=	--coverage -lcriterion

all:		$(NAME)

$(NAME):	$(OBJ)
	@$(AR) rc $(NAME) $(OBJ)
	@cp $(NAME) ../..
	@cp $(HEADER) ../../include/
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
