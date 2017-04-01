##
## Makefile for rush in /home/ethan/rush/
##
## Made by Ethan MARGAILLAN
## Login   <ethan.margaillan@epitech.eu>
##
## Started on  Fri Mar 31 21:03:49 2017 Ethan MARGAILLAN
## Last update Sat Apr  1 18:59:06 2017 Ethan MARGAILLAN
##

CC			=	gcc

CFLAGS		=	-Wall -Wextra -O2

CPPFLAGS	=	-I./include

LDFLAGS		=	-lm -lc_graph_prog_full

SRC			=	src/parallax/draw.c		\
				src/parallax/event.c	\
				src/parallax/init.c		\
				src/scroller/draw.c		\
				src/scroller/init.c		\
				src/switcher/draw.c		\
				src/switcher/init.c		\
				src/init.c				\
				src/main.c				\
				src/rand.c				\
				src/switch.c			\
				src/window.c

OBJ			=	$(SRC:.c=.o)

NAME		=	scroller

$(NAME):	$(OBJ)
			$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

all:		$(NAME)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all
