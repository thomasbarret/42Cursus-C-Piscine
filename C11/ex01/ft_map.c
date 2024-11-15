/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:39:59 by tbarret           #+#    #+#             */
/*   Updated: 2023/08/23 11:42:23 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*r;
	int	i;

	i = 0;
	r = (int *)malloc(sizeof(int) * length);
	if (!r)
		return (NULL);
	while (i < length)
	{
		r[i] = (*f)(tab[i]);
		i++;
	}
	return (r);
}
