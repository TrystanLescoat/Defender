##
## EPITECH PROJECT, 2020
## libmy.a
## File description:
## Makefile
##

CC = gcc

CFLAGS = -W -Wall -Wextra -Wno-unused-variable -Wno-unused-parameter

LDFLAGS = -I./include -L./lib/my -lmy

CSFML = -lm -l csfml-graphics -l csfml-system -l csfml-window -l csfml-audio

SCR = $(wildcard lib/my/*.c)

OBJ = $(SCR:.c=.o)

LIB = lib/my/libmy.a

SRC = $(wildcard src/*.c)

NAME = my_defender

all:	$(NAME)

$(NAME):	$(LIB)
	$(CC) -o $(NAME) $(SRC) $(LDFLAGS) $(CSFML)

$(LIB): $(OBJ)
	$(AR) rsc $(LIB) $(OBJ)

clean:
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) '#*#'

fclean: clean
	$(RM) -f $(NAME)
	$(RM) *.o
	$(RM) $(LIB)

re:	fclean all
