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

SRC 		= 		arraylen.c								\
					my_strcmp.c								\
					my_strlen.c								\
					file_to_str.c

OBJ			=		$(SRC:.c=.o)

NAME		=		libmy.a

HEADER	=	libmy.h

CFLAGS		=		-Wall -Wextra -Wpedantic

UT_SRC =	tests/my_test.c		\
			my_strlen.c

UT_NAME	=	my_tests

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
