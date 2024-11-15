/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:03:16 by tbarret           #+#    #+#             */
/*   Updated: 2023/08/23 11:45:35 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i < length)
	{
		if ((*f)(tab[i]) != 0)
			c++;
		i++;
	}
	return (c);
}