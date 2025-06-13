##
## EPITECH PROJECT, 2025
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

SRC 		= 		component/create_component.c						    \
					component/create_element.c						   		\
					component/destroy_component.c						    \
					component/rev_component.c								\
					game/change_scene.c										\
					game/clean_game.c							            \
					game/destroy_game.c							          	\
					game/init_game.c								       	\
					helpfull/arraylen.c										\
					helpfull/parse_user_input.c								\
					helpfull/my_str_to_word_array.c							\
					helpfull/is_in.c										\
					helpfull/free_tab.c										\
					layer/add_component_to_layer.c				    		\
					layer/clean_layer.c							            \
					layer/create_layer.c					          		\
					layer/destroy_layer.c							        \
					music/music_loader.c									\
					music/destroy_a_music.c									\
					music/destroy_all_music.c								\
					my_encapsulation/circle.c								\
					my_encapsulation/font.c									\
					my_encapsulation/image.c								\
					my_encapsulation/rectangleshape.c						\
					my_encapsulation/sprite.c								\
					my_encapsulation/text.c									\
					my_encapsulation/texture.c								\
					my_encapsulation/transformable.c						\
					my_encapsulation/vertexarray.c							\
					my_encapsulation/view.c									\
					ressource/add_ressource.c					     		\
					ressource/create_component_from_id_ressource.c			\
					ressource/create_a_ressource_in_the_game.c		  		\
					ressource/create_ressource.c						    \
					ressource/create_ressource_link.c						\
					ressource/destroy_ressource.c						    \
					ressource/destroy_all_ressource.c					    \
					ressource/find_a_ressouce_from_id.c						\
					ressource_loader/load_config_file.c						\
					scene/add_an_element_to_scene.c							\
					scene/clean_scene.c							           	\
					scene/destroy_scene.c							        \
					scene/destroy_tab_scene.c						  	    \
					scene/draw_component_of_scene.c				      		\
					scene/init_tab_scene.c									\
					type/find_type.c								        \
					window/change_the_mode_window.c				      		\
					window/create_window.c							        \
					window/destroy_window.c						          	\
					window/make_window.c									\
					button/add_button_to_menu.c								\
					button/manage_button.c									\
					button/add_button_to_menu.c								\
					create_button.c											\
					del_tab_button.c										\
					draw_button.c											\
					draw_shape.c											\
					update_sprite_rect.c									\
					create_object.c											\
					get_movement.c											\
					get_distance.c											\
					add_sprite_to_scene.c

OBJ			=		$(SRC:.c=.o)

NAME		=		libgraphic.a

HEADER	=	include/libgraphic.h			\
          	include/macro.h			  		\
          	include/struct.h		 	 	\
          	include/type_id.h				\
		  	include/my_encapsulation.h

CFLAGS		=		-Wall -Wextra -Wpedantic -lcsfml-audio -std=c2x \
	-D_POSIX_C_SOURCE=202311L

CPPFLAGS	=		-iquote include/.

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

debug: re clean

.PHONY: all				\
		re			    \
		fclean	  		\
		debug			\
		clean
