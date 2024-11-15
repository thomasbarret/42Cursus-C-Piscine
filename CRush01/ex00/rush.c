/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agolding <agolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:40:20 by agolding          #+#    #+#             */
/*   Updated: 2023/08/13 23:38:13 by agolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	special_case_handling(struct s_board *this, int id, int *indices)
{
	if (indices[0] == this->size)
		set_value_and_lock(this,
			id,
			this->size - (this->size - 1) + get_row(this->size, id));
	if (indices[1] == this->size)
		set_value_and_lock(this, id, this->size - get_row(this->size, id));
	if (indices[0] == 1 && get_row(this->size, id) == 0)
		set_value_and_lock(this, id, this->size);
	if (indices[1] == 1 && get_row(this->size, id) == this->size)
		set_value_and_lock(this, id, this->size);
	if (indices[2] == this->size)
		set_value_and_lock(this,
			id,
			this->size - (this->size - 1) + get_col(this->size, id));
	if (indices[3] == this->size)
		set_value_and_lock(this, id, this->size - get_col(this->size, id));
	if (indices[2] == 1 && get_col(this->size, id) == 0)
		set_value_and_lock(this, id, this->size);
	if (indices[3] == 1 && get_col(this->size, id) == this->size)
		set_value_and_lock(this, id, this->size);
}

void	find_the_only_one(struct s_board *this)
{
	int	id;
	int	*indices;

	id = 0;
	while (id < this->size * this->size)
	{
		indices = get_indices(this, id);
		special_case_handling(this, id, indices);
		id++;
	}
}

int	can_be_placed(struct s_board *this, int v, int id)
{
	int	row;
	int	col;
	int	i;

	row = get_row(this->size, id);
	col = get_col(this->size, id);
	i = 0;
	while (i < this->size)
	{
		if (get_value_xy(this, col, i) == v || get_value_xy(this, i, row) == v)
			return (0);
		i++;
	}
	return (1);
}

int	is_solved(int id, int size, int is_okay)
{
	return (id == size * size - 1 || is_okay);
}

int	find_height(struct s_board *this, int id)
{
	int	v;
	int	is_okay;

	v = 1;
	is_okay = 0;
	while (v <= this->size)
	{
		if (get_mask(this, id))
		{
			is_okay = find_height(this, id + 1);
			return (is_solved(id, this->size, is_okay));
		}
		if (can_be_placed(this, v, id))
		{
			set_value(this, id, v);
			is_okay = find_height(this, id + 1);
			if (is_solved(id, this->size, is_okay))
				return (1);
		}
		v++;
	}
	return (0);
}
// if (is_valid_indice(this, id))