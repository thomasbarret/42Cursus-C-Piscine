/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ft_print_comb2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 08:59:49 by tbarret           #+#    #+#             */
/*   Updated: 2023/08/02 13:48:16 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_2(int nb)
{
	int		f;
	int		s;

	if (nb > 9)
	{
		f = nb / 10;
		s = nb % 10;
		ft_putchar(f + 48);
		ft_putchar(s + 48);
	}
	else
	{
		ft_putchar('0');
		ft_putchar(nb + 48);
	}
}

void	ft_print_comb2(void)
{
	int		i;
	int		o;

	i = 0;
	while (i <= 99)
	{
		o = i + 1;
		while (o <= 99)
		{		
			ft_putnbr_2(i);
			ft_putchar(' ');
			ft_putnbr_2(o);
			if (i < 98 || o < 99)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			++o;
		}
		++i;
	}
}
