# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 13:29:41 by tbarret           #+#    #+#              #
#    Updated: 2023/08/21 13:30:00 by tbarret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRC			= ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

CFILE		= ./srcs/

SRCS		= ${addprefix ${CFILE}, ${SRC}}

OBJS		= ${SRCS:.c=.o}

HFILE		= ./includes/

all:		${NAME}

.c.o:
			cc -Wall -Wextra -Werror -c -I ${HFILE} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re