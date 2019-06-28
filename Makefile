NAME=minishell


ifeq ($(shell uname),Darwin)
CFLAGS 		= 		 -Wall -Werror -Wextra -g -Iincludes  -l termcap 
else
CFLAGS 		= 		 -Wall -Wextra -g -Iincludes  -l ncurses
endif


all:
	make -C libft/
	gcc  $(CFLAGS) front/*.c front/*/*.c builtins/*.c back/*.c back/*/*.c  libft/libft.a -o $(NAME)

clean:
	make clean -C libft/
	rm -rf srcs/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: re
	# bash tests/42ShellTester.sh $(PWD)/$(NAME) --hard --reference "bash" --filter "tilde-expansion"
	bash tests/42ShellTester.sh $(PWD)/$(NAME) --hard --reference "bash" --filter $(NAME)
	bash test.sh

valgrind: re
	valgrind --track-origins=yes --show-leak-kinds=all --track-fds=yes 		\
				--show-reachable=no --leak-check=full ./minishell tests/tests_sh/test_echo.sh

.PHONY: all re clean fclean test valgrind