##
## EPITECH PROJECT, 2019
## my_sokoban
## File description:
## Project root Makefile
##

CC 			= 	gcc

MAIN		=	$(addprefix $(SRC_D), $(MAIN_F))
OBJ_M		=	$(MAIN:.c=.o)
MAIN_F		=	main.c

SRC			= 	$(addprefix $(SRC_D), $(SRC_F))
OBJ 		= 	$(SRC:.c=.o)
SRC_D 		= 	src/
SRC_F 		=	usage.c \
				play_game.c \
				display.c \
				end_conditions.c \
				file_manipulation/get_file_buffer.c \
				file_manipulation/get_map_from_file.c \
				movements/can_move.c \
				movements/move_keys.c \
				movements/move_player.c   \
				positions/get_initial_positions.c \
				positions/pos.c \

SRC_UT   	=	$(addprefix $(SRC_UT_D), $(SRC_UT_F))
OBJ_UT 	 	=	$(SRC_UT:.c=.o)
SRC_UT_D 	= 	tests/
SRC_UT_F 	=	test_check_args.c \
				test_is_valid_map.c \

INC			= 	-I./include/

CFLAGS		= 	-W -Wall -Wextra -Werror $(INC) $(LDFLAGS)

DBFLAGS		=	-g -g3 -ggdb

LDFLAGS 	=	-L./lib -lmy -lncurses

LDFLAGS_UT	= 	-lcriterion -lgcov --coverage

NAME 		= 	my_sokoban

NAME_UT 	= 	unit_tests

all: $(NAME)

$(NAME):	makelib $(OBJ) $(OBJ_M)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_M) $(CFLAGS)

makelib:
	make -C ./lib/my/ all

tests_run: clean makelib $(OBJ) $(OBJ_UT)
	echo -e "\e[1;32mCompiling $(NAME_UT) binary... \e[0m"
	$(CC) -o $(NAME_UT) $(SRC) $(SRC_UT) $(CFLAGS) $(LDFLAGS_UT)
	./$(NAME_UT)
	@rm -f $(SRC_UT_F:.c=.gcda)
	@rm -f $(SRC_UT_F:.c=.gcno)

clean:
	rm -f $(OBJ)
	rm -f *.gc*
	make -C ./lib/my clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_UT)
	make -C ./lib/my clean

re: fclean all