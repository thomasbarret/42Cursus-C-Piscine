/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:23:42 by tbarret           #+#    #+#             */
/*   Updated: 2023/08/02 16:30:33 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_custom_print(int *t, int size)
{
	int		i;
	int		lower;

	i = 1;
	lower = 1;
	while (i < size)
	{
		if (t[i - 1] >= t[i])
			lower = 0;
		i++;
	}
	if (lower)
	{
		i = 0;
		while (i < size)
			ft_putchar(t[i++] + '0');
		if (t[0] < (10 - size))
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

void	ft_print_combn(int n)
{
	int		i;
	int		result[10];

	i = 0;
	if (n == 1)
		while (i < 10)
			ft_putchar(i++ + '0');
	while (i < n)
		result[i++] = 0;
	while (result[0] <= (10 - n) && n > 1)
	{
		ft_custom_print(result, n);
		result[n - 1]++;
		i = n;
		while (i && n > 1)
		{
			i--;
			if (result[i] > 9)
			{
				result[i - 1]++;
				result[i] = 0;
			}
		}
	}
}
