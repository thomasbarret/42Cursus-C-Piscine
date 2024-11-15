/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 10:33:21 by tbarret           #+#    #+#             */
/*   Updated: 2023/08/06 16:20:06 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	top(int column)
{
	int	j;

	j = 1;
	while (j <= column)
	{
		if (j == 1)
			ft_putchar('/');
		else if (j == column)
			ft_putchar('\\');
		else
			ft_putchar('*');
		j++;
	}
}

void	middle(int column)
{
	int	j;

	j = 1;
	while (j <= column)
	{
		if (j == 1 || j == column)
			ft_putchar('*');
		else
			ft_putchar(' ');
		j++;
	}
}

void	bot(int column)
{
	int	j;

	j = 1;
	while (j <= column)
	{
		if (j == 1)
			ft_putchar('\\');
		else if (j == column)
			ft_putchar('/');
		else
			ft_putchar('*');
		j++;
	}
}

void	rush(int column, int line)
{
	int	i;

	i = 1;
	while (i <= line)
	{
		if (i == 1)
		{
			top(column);
		}
		if (i != 1 && i != line)
		{
			middle(column);
		}
		if (i == line)
		{
			bot(column);
		}
		ft_putchar('\n');
		i++;
	}
}
