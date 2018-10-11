# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/22 14:16:52 by rqueverd           #+#    #+#              #
#    Updated: 2018/10/09 16:29:00 by rqueverd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl
HEADER = ft_ssl.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = misc_sha256.c misc_main.c errors.c prepare_padding.c main.c read_file.c fnc_md5.c stage_md5.c fnc_sha256.c verif.c
OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C libft/
	@echo "\033[32;40mCompilation des sources"
	@$(CC) $(CFLAGS)  -I libft/ -c $(SRCS)
	@$(CC) -o $(NAME) $(OBJECTS) -lm -L libft/ -lft $(FLAGSFDF)
	@echo "Termine !"
clean:
	@echo "\033[32;40mSuppresion des objets du."
	@make -C libft/ clean
	@rm -rf $(OBJECTS)
	@echo "Termine !"
fclean: clean
	@echo "Nettoyage complet"
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "Termine !"
re: fclean all
.PHONY: clean fclean re all%