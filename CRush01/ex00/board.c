/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agolding <agolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:06:07 by agolding          #+#    #+#             */
/*   Updated: 2023/08/13 23:31:555 by agolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

struct s_board	*new(int size, int *indices)
{
	static struct s_board	board;
	int						x;

	board.size = size;
	board.values = (int *)malloc(sizeof(int) * size * size);
	board.mask = (int *)malloc(sizeof(int) * size * size);
	board.indices = indices;
	x = 0;
	while (x < size * size)
	{
		board.mask[x] = 0;
		board.values[x++] = 0;
	}
	return (&board);
}

void	set_value(struct s_board *this, int id, int value)
{
	this->values[id] = value;
}

void	set_value_and_lock(struct s_board *this, int id, int value)
{
	set_value(this, id, value);
	this->mask[id] = 1;
}

int	get_value(struct s_board *this, int id)
{
	return (this->values[id]);
}

int	get_value_xy(struct s_board *this, int x, int y)
{
	return (this->values[get_idx(this->size, x, y)]);
}

void	show_result(struct s_board *this)
{
	int		x;
	char	converted_int;

	x = 0;
	while (x < this->size * this->size)
	{
		converted_int = this->values[x] + '0';
		write(1, &converted_int, 1);
		if (!((x + 1) % this->size))
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		x++;
	}
}

int	*get_indices(struct s_board *this, int id)
{
	static int	indices[4];
	int			row;
	int			col;

	row = id / this->size;
	col = id % this->size;
	indices[0] = this->indices[col];
	indices[1] = this->indices[col + this->size];
	indices[2] = this->indices[row + this->size * 2];
	indices[3] = this->indices[row + this->size * 3];
	return (indices);
}

int	get_mask(struct s_board *this, int id)
{
	return (this->mask[id]);
}

int	get_idx(int size, int x, int y)
{
	return (x + y * size);
}

int	get_col(int size, int id)
{	
	return (id % size);
}

int	get_row(int size, int id)
{
	return (id / size);
}

