.PHONY: all test clean test
NAME=21sh

all:
	make -C libft/
	gcc  -lncurses -Wall -Wextra -Werror libft/libft.a front/*.c back/*.c back/$(NAME)/*.c -o $(NAME)

clean:
	make clean -C libft/
	rm -rf srcs/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

test:
	bash ~/42ShellTester/42ShellTester.sh /Users/hugohow-choong/42/minishell_21sh_42sh/$(NAME) --reference "bash" --filter $(NAME) > error | cat
	cat error | less