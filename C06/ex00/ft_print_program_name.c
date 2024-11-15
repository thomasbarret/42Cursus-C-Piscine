/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:14:50 by tbarret           #+#    #+#             */
/*   Updated: 2023/08/11 08:00:54 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char const *argv[])
{
	int	i;

	i = 0;
	if (argc)
	{
		while (argv[0][i])
		{
			write(1, &argv[0][i], 1);
			i++;
		}
	}
	return (0);
}
