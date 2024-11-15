/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:22:29 by abutet            #+#    #+#             */
/*   Updated: 2023/08/20 17:40:07 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	strsize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	size(char *filename)
{
	int		file;
	char	c;
	int		r;

	r = 0;
	file = open(filename, -O_RDONLY);
	while (read(file, &c, 1))
		if (c == ':')
			r++;
	return (r);
}

char	*cut(int x, int y, char *filename)
{
	char	*str;
	char	c;
	int		file;
	int		t_y;
	int		t_x;

	t_x = 0;
	t_y = 0;
	str = (char *)malloc(sizeof(char) * x + 1);
	file = open(filename, -O_RDONLY);
	while (read(file, &c, 1))
	{
		if (t_y == y && t_x < x)
		{
			str[t_x] = c;
			t_x++;
		}
		if (c == '\n')
			t_y++;
	}
	str[t_x] = '\0';
	return (str);
}

int	find_args(struct s_dict this, char *str)
{
	int	i;

	i = 0;
	while (this.prefix[i])
	{
		if (ft_strcmp(this.prefix[i], str) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	security(char *str)
{
	if (!only_num(str))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}
