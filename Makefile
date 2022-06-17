# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anne-sophie <anne-sophie@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 09:16:18 by anne-sophie       #+#    #+#              #
#    Updated: 2022/06/17 09:17:39 by anne-sophie      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@cd libft && make all
	@cd printf && make all
	@gcc -Wall -Wextra -Werror server.c libft/libft.a printf/libftprintf.a -o server
	@gcc -Wall -Wextra -Werror client.c libft/libft.a printf/libftprintf.a -o client

clean:
	@cd printf && make clean
	@cd libft && make clean
	@rm -f server
	@rm -f client

fclean: clean
	@cd libft && make fclean
	@cd printf && make fclean

re: fclean all