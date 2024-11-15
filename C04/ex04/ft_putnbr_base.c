/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:16:20 by tbarret           #+#    #+#             */
/*   Updated: 2023/08/21 17:59:59 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_base(char *b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (b[0] == '\0' || b[1] == '\0')
		return (0);
	while (b[i] != '\0' )
	{
		j = i + 1;
		if (b[i] == '+' || b[i] == '-')
			return (0);
		if (b[i] < 32 || b[i] > 126)
			return (0);
		while (b[j])
		{
			if (b[i] == b[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			s;
	int			r[100];
	int			i;
	long int	nb;

	i = 0;
	s = 0;
	nb = nbr;
	if (!ft_base(base))
		return ;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	while (base[s])
		s++;
	while (nb)
	{
		r[i] = nb % s;
		nb = nb / s;
		i++;
	}
	while (--i >= 0)
		ft_putchar(base[r[i]]);
}
