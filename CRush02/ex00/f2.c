/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:29:02 by abutet            #+#    #+#             */
/*   Updated: 2023/08/20 18:53:45 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

struct s_dict	gen(struct s_dict *this, int file, char *filename)
{
	char	*rcut;
	char	**rsplit;
	int		x;
	int		y;
	char	c;

	x = 0;
	y = 0;
	while (read(file, &c, 1))
	{
		if (c != '\n')
			x++;
		else
		{
			rcut = cut(x, y, filename);
			rsplit = ft_split(rcut, ": ");
			this->prefix[y] = rsplit[0];
			this->suffix[y] = rsplit[1];
			y++;
			x = 0;
		}
	}
	return (*this);
}

struct s_dict	new(struct s_dict *this, char *filename)
{
	int		file;

	this->size = size(filename);
	this->prefix = (char **)malloc(sizeof(char *) * this->size);
	this->suffix = (char **)malloc(sizeof(char *) * this->size);
	file = open(filename, -O_RDONLY);
	gen(this, file, filename);
	return (*this);
}
