# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 08:32:57 by tbailleu          #+#    #+#              #
#    Updated: 2017/11/24 18:57:35 by tbailleu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS_DIR = ./fill_it/
INCLUDES_DIR = ./fill_it ./libft
LIB = ./libft/libft.a
FUNCTIONS = main \
			checker \
			map \
			transform \
			uint192_t

FLAGS = -Wall -Werror -Wextra
BINS = $(patsubst %,$(SRCS_DIR)%.o,$(FUNCTIONS))
INCLUDE = $(patsubst %,-I %,$(INCLUDES_DIR))

$(NAME): lib $(BINS)
	@gcc $(FLAGS) -o $(NAME) $(BINS) $(LIB) $(INCLUDES)

lib:
	@make -C libft/

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $< $(INCLUDES)

all: $(NAME)

clean:
	@make -C libft/ clean
	@/bin/rm -rf $(BINS)

fclean: clean
	@make -C libft/ fclean
	@find . -type f -name $(NAME) -delete

re: fclean all

rec: all clean

norm:
	$(eval NORM_FILE = $(shell find . -type f -name "*.c" -o -type f -name "*.h"))
	$(eval NORM_ERRNB = $(shell norminette $(NORM_FILE) | grep -c -E '^(Error|Warning)'))
	@if [ $(NORM_ERRNB) -eq 0 ]; then\
		echo '\033[0;32mNorme: OK 😃';\
	else\
		echo '\033[0;31m'$(NORM_ERRNB) 'Error found 😱\033[1;34m';\
		norminette $(NORM_FILE) | grep -B 1 -E '^(Error|Warning)';\
	fi

.PHONY: all clean fclean re norm rec
