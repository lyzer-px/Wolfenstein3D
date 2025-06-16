##
## EPITECH PROJECT, 2025
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
				file_to_str.c										\
				my_str_to_word_array.c								\
				parse_user_input.c									\
				del_last_char.c										\
				my_strlen.c											\
				concat_array.c										\
				print_error.c										\
				write_in_file.c										\
				mini_dprintf.c										\
				round_number.c										\
				str_is_same.c										\
				my_atoi.c											\
				print_array.c										\
				str_to_array.c										\
				char_in_str.c										\
				encrypt_file.c

OBJ			=		$(SRC:.c=.o)

NAME		=		libmy.a

HEADER	=	libmy.h

CFLAGS		=		-Wall -Wextra -Wpedantic -std=c2x \
	-D_POSIX_C_SOURCE=202311L

UT_SRC =	tests/my_test.c		\
			my_strlen.c

UT_NAME	=	my_tests

UT_FLAGS	=	--coverage -lcriterion

all:		$(NAME)

$(NAME):	$(OBJ)
	@$(AR) rc $(NAME) $(OBJ)
	@cp $(NAME) ../..
	@cp $(HEADER) ../../include/
	@cp $(NAME) ../graphic/
	@cp $(HEADER) ../graphic/include/
#	@ranlib $(LIB_NAME)

clean:
	$(RM) $(OBJ)
	@find -name "*~" -delete -o -name "#*#" -delete
	@find -name "*.gcda" -delete -o -name "*.gcno" -delete

fclean: clean
	$(RM) $(NAME) ../../$(NAME) $(UT_NAME) ../graphic/$(NAME)
	@find -name "coding-style-reports.log" -delete

re:	fclean all

debug:	re clean

.PHONY: all				\
		re				\
		fclean			\
		debug			\
		clean
