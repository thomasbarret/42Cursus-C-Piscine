/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:34:16 by tbarret           #+#    #+#             */
/*   Updated: 2023/08/13 15:26:10 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*r;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	r = (int *)malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		r[i] = min;
		min++;
		i++;
	}
	return (r);
}
