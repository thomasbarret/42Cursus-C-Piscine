/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 10:33:21 by tbarret           #+#    #+#             */
/*   Updated: 2023/08/06 19:36:20 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	border(int column)
{
	int	j;

	j = 1;
	while (j <= column)
	{
		if (j == 1 || j == column)
			ft_putchar('o');
		else
			ft_putchar('-');
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
			ft_putchar('|');
		else
			ft_putchar(' ');
		j++;
	}
}

void	rush(int column, int line)
{
	int	i;

	i = 1;
	while (i <= line)
	{
		if (i == 1 || i == line)
		{
			border(column);
		}
		if (i != 1 && i != line)
		{
			middle(column);
		}
		ft_putchar('\n');
		i++;
	}
}
