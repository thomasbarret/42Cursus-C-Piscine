# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 13:29:41 by tbarret           #+#    #+#              #
#    Updated: 2023/08/23 09:13:51 by tbarret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= do-op

SRC			= 	ft_add.c \
				ft_atoi.c \
				ft_div.c \
				ft_main.c \
				ft_mod.c \
				ft_mult.c \
				ft_putnbr.c \
				ft_strcmp.c \
				ft_sub.c

CFILE		= ./srcs/

SRCS		= ${addprefix ${CFILE}, ${SRC}}

OBJS		= ${SRCS:.c=.o}

HFILE		= ./includes/

all:		${NAME}

.c.o:
			cc -Wall -Wextra -Werror -c -I ${HFILE} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			cc -Wall -Wextra -Werror -o ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re