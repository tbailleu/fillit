# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 08:32:57 by tbailleu          #+#    #+#              #
#    Updated: 2017/11/23 11:58:15 by tbailleu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS_DIR = ./
INCLUDES_DIR = .
FUNCTIONS = ft_memset   ft_memalloc   ft_memcpy  ft_memccpy    ft_memmove ft_memdel     ft_bzero   ft_atoi  \
			ft_strnew   ft_strdel     ft_strclr  ft_strlen     ft_strdup  ft_strcpy     ft_strncpy ft_strcmp \
			ft_strcat   ft_strncat    ft_strlcat ft_strchr     ft_strrchr ft_strstr     ft_strnstr ft_strncmp \
			ft_striter  ft_striteri   ft_strmap  ft_strmapi    ft_strequ  ft_strnequ    ft_strjoin ft_strsub   \
			ft_strtrim  ft_strsplit   ft_nbrlen  ft_strcnt_sep ft_itoa    ft_memcmp     ft_memchr  ft_lstnew    \
			ft_putchar  ft_putchar_fd ft_putstr  ft_putstr_fd  ft_putendl ft_putendl_fd ft_putnbr  ft_putnbr_fd  \
			ft_min      ft_max        ft_isspace ft_isalpha    ft_isdigit ft_isalnum    ft_isascii ft_isprint     \
			ft_isupper  ft_islower    ft_toupper ft_tolower    ft_lstmap  ft_lstiter    ft_lstdel  ft_lstadd       \
			ft_readfile ft_lstdelone  ft_sqrt    ft_strjoinfree           ft_strsubfree ft_calloc  ft_puttendl      \
			ft_putbin

FLAGS = -Wall -Werror -Wextra
BINS = $(patsubst %,%.o,$(FUNCTIONS))

$(NAME): $(BINS)
	@ar rc $(NAME) $^
	@ranlib $(NAME)
	
%.o: %.c
	@gcc $(FLAGS) -o $@ -c $< -I $(INCLUDES_DIR)

all: $(NAME)

clean:
	@/bin/rm -rf $(BINS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re