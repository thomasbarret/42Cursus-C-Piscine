/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:16:20 by tbarret           #+#    #+#             */
/*   Updated: 2023/08/21 18:12:17 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	n;
	int	r;

	i = 0;
	r = 0;
	n = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + (str[i] - 48);
		i++;
	}
	return (r * n);
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

int	ft_convert_base(long int nb, char *base, int *r, int f)
{
	int	s;
	int	i;
	int	j;

	i = 0;
	s = 0;
	j = 1;
	if (!ft_base(base))
		return (0);
	if (nb < 0)
	{
		nb = -nb;
		j *= -1;
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
		f = (f * 10) + (base[r[i]] - 48);
	return ((int)f * j);
}

int	ft_atoi_base(char *str, char *base)
{
	int	r[100];
	int	nbr;

	nbr = ft_atoi(str);
	return (ft_convert_base((long int)nbr, base, r, 0));
}
