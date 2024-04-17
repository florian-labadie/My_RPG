##
## EPITECH PROJECT, 2023
## Makefiles
## File description:
## solostumper
##

MAIN =		main.c						\

SRC =		src/error_handling.c		\
			src/read_file.c				\
			src/check_env.c				\
			src/launch.c				\
			src/rpg_loop.c				\
			src/destroy.c				\
			src/fct_générique/create_button.c	\
			src/fct_générique/create_text.c	\
			src/setup/background_menu_setup.c	\
			src/setup/setup_menu.c	\
			src/setup/menu_button.c	\
			src/manager/background_menu_manager.c	\

SRCTEST = 	tests/test_lib.c			\

OBJ = $(SRC:.c=.o)	$(MAIN:.c=.o)

OBJTEST = $(SRCTEST:.c=.o)

NAME =		my_rpg

NAMETEST = 	unit_tests

CFLAGS = -Wall -Wextra -std=c99 -g3

CPPFLAGS	=	-I./include

LDFLAGS = -L./lib/my

LDLIBS 	=	-lmy -lm

GRAPHICS	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

CC = gcc

all: buildlib $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(LDFLAGS) -o $@ $(OBJ) $(LDLIBS) $(GRAPHICS)

buildlib:
	make -C ./lib/my

buildlibtest: buildlib
	make -C ./lib/my CFLAGS='$(CFLAGS) --coverage'

buildtest: CFLAGS += --coverage
buildtest: buildlibtest $(OBJTEST)
	$(CC) $(CPPFLAGS) $(LDFLAGS) -o $(NAMETEST) $(OBJTEST) $(SRC) $(LDLIBS)	\
	--coverage -lcriterion

clean:
	rm -f $(OBJ)
	find . -name "*~" -delete
	find . -name "#*#" -delete
	find . -name "vgcore*" -delete
	find . -name "*.gcno" -delete
	find . -name "*.gcda" -delete
	find . -name "*.gcov" -delete
	find . -name "coding-style-reports.log" -delete
	find . -name "*.cor" -delete

fclean: clean cleantest
	rm -f $(NAME)
	make fclean -C ./lib/my

cleantest:
		rm -f $(NAMETEST)
		rm -f $(OBJTEST)

re: fclean all

valgrind: buildlib $(OBJ)
	$(CC) -g3 $(LDFLAGS) -o $(NAME) $(OBJ) $(LDLIBS)

unit_tests: buildtest

tests_run: unit_tests
		./unit_tests

.PHONY: all clean fclean re valgrind unit_tests tests_run cleantest
		buildlibtest buildtest buildlib
