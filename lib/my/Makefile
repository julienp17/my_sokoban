##
## EPITECH PROJECT, 2019
## my_sokoban
## File description:
## Libmy Makefile
##

CC 			= 	gcc

SRC			=	my_putchar.c                    \
				my_putstr.c                     \
				my_puterr.c                     \
				my_strcmp.c                     \
				my_count_char.c                 \
				my_count_char_str_array.c       \
				my_count_until_sep.c            \
				my_strlen.c                     \
				my_strdup_str_array.c           \
				my_strcpy_str_array.c           \
				my_get_max_word_len_str_array.c \
				my_str_to_word_array.c          \
				my_str_array_len.c              \

OBJ			=	$(SRC:.c=.o)

CFLAGS		=	-W -Wall -Wextra -Werror

DBFLAGS		=	-g -g3 -ggdb

HEADER		=	my.h

NAME		=	libmy.a

all:		$(OBJ)
			ar rc $(NAME) $(OBJ)
			cp $(NAME) ../
			cp $(HEADER) ../../include

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)
			rm -f ../$(NAME)
			rm -f ../../include/$(HEADER)

re:			fclean all

.phony:		re fclean clean
