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

SRC 		= 		arraylen.c												\
					parse_user_input.c										\
					my_str_to_word_array.c									\
					is_in.c													\
					free_tab.c												\
					add_an_element_to_scene.c								\
					add_composant_to_layer.c				    			\
					add_ressource.c							          		\
					change_the_mode_window.c				      			\
					clean_game.c							            	\
					clean_layer.c							            	\
					clean_scene.c							            	\
					create_composant.c						        		\
					create_composant_from_id_ressource.c					\
					create_layer.c					          				\
					create_a_ressource_in_the_game.c		  				\
					create_element.c						          		\
					create_ressource.c						        		\
					create_ressource_link.c					      			\
					create_window.c							          		\
					destroy_all_ressource.c					      			\
					destroy_composant.c						        		\
					destroy_game.c							          		\
					destroy_layer.c							          		\
					destroy_ressource.c						        		\
					destroy_scene.c							          		\
					destroy_tab_scene.c						        		\
					destroy_window.c						          		\
					draw_composant_of_scene.c				      			\
					find_a_ressouce_from_id.c				      			\
					find_type.c								            	\
					init_game.c								            	\
					init_tab_scene.c										\
					make_window.c							            	\
					load_config_file.c										\
					rev_composant.c

OBJ			=		$(SRC:.c=.o)

NAME		=		libgraphic.a

HEADER	=	libgraphic.h		\
          macro.h			  	\
          struct.h		 	 	\
          type_id.h

CFLAGS		=		-Wall -Wextra -Wpedantic -Werror

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
	$(RM) $(NAME) ../../$(NAME) $(UT_NAME)
	@find -name "coding-style-reports.log" -delete

re:	fclean all

debug:	re clean

.PHONY: all				\
		re			    \
		fclean	  		\
		clean
