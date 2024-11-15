/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:52:33 by tbarret           #+#    #+#             */
/*   Updated: 2023/08/23 08:45:04 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_type(char *str)
{
	if (ft_strcmp(str, "+") == 0)
		return ('+');
	if (ft_strcmp(str, "-") == 0)
		return ('-');
	if (ft_strcmp(str, "%") == 0)
		return ('%');
	if (ft_strcmp(str, "/") == 0)
		return ('/');
	if (ft_strcmp(str, "*") == 0)
		return ('*');
	return (0);
}

void	ft_calc(int s, int a, int b)
{
	if (s == '+')
		ft_putnbr(ft_add(a, b));
	if (s == '-')
		ft_putnbr(ft_sub(a, b));
	if (s == '/')
		ft_putnbr(ft_div(a, b));
	if (s == '%')
		ft_putnbr(ft_mod(a, b));
	if (s == '*')
		ft_putnbr(ft_mult(a, b));
	ft_putstr("\n");
}

void	ft_result(int s, int a, int b)
{
	if (!s)
	{
		ft_putstr("0\n");
		return ;
	}
	if ((s == '/') && b == 0)
	{
		ft_putstr("Stop : division by zero\n");
		return ;
	}
	if ((s == '%') && b == 0)
	{
		ft_putstr("Stop : modulo by zero\n");
		return ;
	}
	if ((a == 0 && b == 0))
	{
		ft_putstr("0\n");
		return ;
	}
	ft_calc(s, a, b);
}

int	main(int argc, char **argv)
{
	int	a;
	int	b;
	int	s;

	if (argc != 4)
		return (0);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	s = ft_type(argv[2]);
	ft_result(s, a, b);
}
