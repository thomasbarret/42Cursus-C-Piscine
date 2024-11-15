/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skycraper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agolding <agolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 23:19:56 by thomas            #+#    #+#             */
/*   Updated: 2023/08/13 23:23:07 by agolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	solve_skycraper(struct s_board *this)
{
	int	has_result;

	find_the_only_one(this);
	has_result = find_height(this, 0);
	if (has_result)
		show_result(this);
	else
		write(2, "Error\n", 6);
}
