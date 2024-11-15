# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abutet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/19 12:10:05 by abutet            #+#    #+#              #
#    Updated: 2023/08/20 17:15:38 by abutet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
SRC = cut.c rush2.c rush.c string.c f1.c f2.c ft_split.c

all: $(NAME)

$(NAME):
	cc -Wall -Werror -Wextra -o $(NAME) $(SRC)

fclean:
	rm -f $(NAME)

re: fclean all
