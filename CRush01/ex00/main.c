/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agolding <agolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:35:50 by tbarret           #+#    #+#             */
/*   Updated: 2023/08/13 23:42:13 by agolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_number_count(char *str)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (str[i])
	{
		if (!(i % 2))
		{
			if (str[i] >= '0' && str[i] <= '9')
				c++;
			else
				return (0);
		}
		else
		{
			if (str[i] != ' ' || !str[i + 1])
				return (0);
		}
		i++;
	}
	return (c);
}

int	*ft_split(char *str, int size)
{
	int	index;
	int	tab_i;
	int	*result;

	index = 0;
	tab_i = 0;
	result = (int *)malloc(sizeof(int) * size);
	while (str[index])
	{
		if (!(index % 2))
		{
			result[tab_i] = (str[index] - 48);
			tab_i++;
		}
		index++;
	}
	return (result);
}

int	main(int argc, char *argv[])
{
	int				size;
	int				nbr_arg;
	int				*indices;
	struct s_board	*board;

	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	nbr_arg = ft_number_count(argv[1]);
	size = nbr_arg / 4;
	indices = ft_split(argv[1], nbr_arg);
	board = new(size, indices);
	solve_skycraper(board);
	free(board->values);
	free(board->indices);
	free(board->mask);
	return (0);
}

//	cc -Wall -Wextra -Werror -o rush-01 *.c
//	./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" | cat -e
