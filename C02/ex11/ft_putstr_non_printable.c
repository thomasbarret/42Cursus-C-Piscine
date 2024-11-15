/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:21:13 by tbarret           #+#    #+#             */
/*   Updated: 2023/08/04 10:41:02 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_printhex(unsigned char c)
{
	char	*b;

	b = "0123456789abcdef";
	ft_putchar(b[c / 16]);
	ft_putchar(b[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str < ' ' || *str == 127)
		{
			ft_putchar('\\');
			ft_printhex(*str);
		}
		else
			ft_putchar(*str);
		str++;
	}
}
