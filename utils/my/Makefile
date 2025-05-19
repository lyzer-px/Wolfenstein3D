##
## EPITECH PROJECT, 2024
## make lib
## File description:
## make lib
##

#
# HELP TO BUILD
#

AR			?=	ar

CP			?=	cp

RM			?=	rm -rf

#
# BINARY CREATION
#

SRC 		= 	my_strcmp.c											\
				my_strncmp.c										\
				nb_to_str.c											\
				my_getnbr.c											\
				is_in.c												\
				free_tab.c											\
				my_strndup.c										\
				my_strdup.c											\
				my_libdup.c											\
				arraylen.c											\
				libcat.c											\
				my_str_to_word_array.c								\
				parse_user_input.c									\
				del_last_char.c										\
				my_strlen.c

OBJ			=		$(SRC:.c=.o)

NAME		=		libmy.a

HEADER	=	libmy.h

CFLAGS		=		-Wall -Wextra -Wpedantic -Werror

UT_SRC =	tests/my_test.c		\
			my_strlen.c

UT_NAME	=	my_tests

UT_FLAGS	=	--coverage -lcriterion

all:		$(NAME)

$(NAME):	$(OBJ)
	@$(AR) rc $(NAME) $(OBJ)
	@cp $(NAME) ../..
	@cp $(HEADER) ../../include/
	@cp $(HEADER) ../graphic/
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
		re				\
		fclean			\
		clean
