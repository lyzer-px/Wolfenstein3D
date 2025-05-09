##
## EPITECH PROJECT, 2024
## MAKEFILE
## File description:
## FILEMAKE
##

CC ?= gcc

SRC 	=	src/main.c 						\
			src/bs.c						\
			src/raycast2d.c					\
			src/inits.c

NAME	=	bswolf

VPATH	=	../include

C23		=	-std=c2x -D_POSIX_C_SOURCE=202311L

CFLAGS	+=	-Wall -Wextra -pedantic $(C23)

CSFMLIBS	=	-lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio

LDLIBS	=	-lm ${CSFMLIBS}

LDFLAGS	=	-Llib ${LDLIBS}

CPPFLAGS	+=	-iquote $(VPATH)

OBJ	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: CFLAGS += -g3

.PHONY: all clean fclean re debug
