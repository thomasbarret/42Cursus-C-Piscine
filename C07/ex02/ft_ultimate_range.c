/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:40:27 by tbarret           #+#    #+#             */
/*   Updated: 2023/08/13 15:26:04 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*result;
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	result = (int *)malloc(sizeof(int) * (max - min));
	if (!result)
	{
		*range = NULL;
		return (-1);
	}
	*range = result;
	while (min < max)
	{
		result[i] = min;
		min++;
		i++;
	}
	return (i);
}
