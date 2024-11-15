/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:18:47 by tbarret           #+#    #+#             */
/*   Updated: 2023/08/09 17:35:05 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	r;

	r = 0;
	if (nb <= 0 || nb >= 2147483647)
		return (0);
	while (r * r < nb && r <= 46340)
		r++;
	if (r * r == nb)
		return (r);
	return (0);
}