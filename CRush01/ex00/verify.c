/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agolding <agolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 23:41:24 by agolding          #+#    #+#             */
/*   Updated: 2023/08/13 23:43:18 by agolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	is_valid_indice(struct s_board *this, int id)
{
	int	*indices;
	int	value;
	int	col;
	int	row;

	col = get_col(this->size, id);
	row = get_row(this->size, id);
	indices = get_indices(this, id);
	value = is_valid_row(this, row, col, indices[2]);
	value &= is_valid_row_right(this, row, col, indices[3]);
	value &= is_valid_col(this, row, col, indices[0]);
	value &= is_valid_col_right(this, row, col, indices[1]);
	return (value);
}

int	is_valid_row(struct s_board *this, int row, int col, int indice)
{
	int	count;
	int	max;
	int	i;
	int	b_val;

	count = 0;
	max = 0;
	i = 0;
	while (i < this->size && i <= col)
	{
		if (get_value_xy(this, i, row) > max)
		{
			max = get_value_xy(this, i, row);
			count++;
		}
		i++;
	}
	b_val = col < this->size - 1 && count <= indice;
	b_val |= col == this->size - 1 && count == indice;
	return (b_val);
}

int	is_valid_row_right(struct s_board *this, int row, int col, int indice)
{
	int	count;
	int	max;
	int	i;
	int	b_val;

	count = 0;
	max = 0;
	i = this->size - 1;
	if (col == this->size - 1)
		return (1);
	while (i >= 0)
	{
		if (get_value_xy(this, i, row) > max)
		{
			max = get_value_xy(this, i, row);
			count++;
		}
		i--;
	}
	b_val = col < this->size - 1 && count <= indice;
	b_val |= col == this->size - 1 && count == indice;
	return (b_val);
}

int	is_valid_col(struct s_board *this, int row, int col, int indice)
{
	int	count;
	int	max;
	int	i;
	int	b_val;

	count = 0;
	max = 0;
	i = 0;
	while (i < this->size && i <= col)
	{
		if (get_value_xy(this, col, i) > max)
		{
			max = get_value_xy(this, col, i);
			count++;
		}
		i++;
	}
	b_val = (row < this->size - 1 && count <= indice);
	b_val |= (row == this->size - 1 && count == indice);
	return (b_val);
}

int	is_valid_col_right(struct s_board *this, int row, int col, int indice)
{
	int	count;
	int	max;
	int	i;
	int	b_val;

	count = 0;
	max = 0;
	i = this->size - 1;
	if (row == this->size - 1)
		return (1);
	while (i >= 0)
	{
		if (get_value_xy(this, col, i) > max)
		{
			max = get_value_xy(this, col, i);
			count++;
		}
		i--;
	}
	b_val = (row < this->size - 1 && count <= indice);
	b_val |= (row == this->size - 1 && count == indice);
	return (b_val);
}