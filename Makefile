##
## EPITECH PROJECT, 2025
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

SRC 		= 		main.c													\
					src/check_env.c											\
					src/creation_scene/error/create_backgound_error.c		\
					src/creation_scene/error/create_error_scene.c			\
					src/creation_scene/error/create_text_error.c			\
					src/creation_scene/game/create_game_scene.c				\
					src/handle_event.c										\
					src/init_program.c										\
					src/init_render_components.c							\
					src/loop.c												\
					src/player_movement.c									\
					src/print_help.c										\
					src/project.c											\
					src/raycast2d.c											\
					src/creation_scene/menu/init_pause_menu.c				\
					src/creation_scene/menu/init_start_menu.c				\
					src/save/save_game.c									\
					src/save/content_check.c								\
					src/save/name_check.c									\
					src/save/load_save.c									\
					src/animate_shotgun.c									\
					src/ui.c												\
					src/map_loader.c

OBJ			=		$(SRC:.c=.o)

NAME		=		wolf3d

CFLAGS		=		-Wall -Wextra -Wpedantic -std=c2x \
	-D_POSIX_C_SOURCE=202311L


CPPFLAGS	+=		-iquote include
CPPFLAGS	+=		-lcsfml-audio -lcsfml-graphics
CPPFLAGS	+=		-lcsfml-network -lcsfml-system -lcsfml-window -lm

DEBUG		=	-g3

LDLIBS +=	-lmy -lgraphic -lcsfml-audio -lcsfml-graphics -lcsfml-network
LDLIBS +=	-lcsfml-system -lcsfml-window -lm

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
	@find -name "coding-style-re./libgraphic.aports.log" -delete

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
	@echo "hi"

coverage: tests_run
	gcovr --exclude test/
	@find -name "*.gcda" -delete -o -name "*.gcno" -delete
	@find -name $(UT_NAME) -delete

coding_style: fclean
	coding-style . .
	@cat coding-style-reports.log
	@$(RM) "coding-style-reports.log";

.PHONY: all				\
		re				\
		fclean			\
		clean			\
		debug_comp		\
		debug			\
		tests_run 		\
		coverage 		\
		coding_style
