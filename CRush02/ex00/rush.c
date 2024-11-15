/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:43:12 by tbarret           #+#    #+#             */
/*   Updated: 2023/08/20 18:52:16 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include "string.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_realloc(char **str)
{
	int		len;
	char	*str_cpy;

	len = ft_strlen(*str);
	if (!(char *)malloc(sizeof(char) * len))
		return (0);
	str_cpy = (char *)malloc(sizeof(char) * len);
	ft_strncpy(str_cpy, *str, len + 1);
	free(*str);
	*str = str_cpy;
	return (1);
}

void	ft_remove_start_zeros(char **str)
{
	char	*str_cpy;
	int		i;
	int		j;

	if (!(char *)malloc(sizeof(char) * (ft_strlen(*str) + 1)))
		return ;
	str_cpy = (char *)malloc(sizeof(char) * (ft_strlen(*str) + 1));
	i = 0;
	j = 0;
	while ((*str)[i] == '0')
		i++;
	while ((*str)[i])
	{
		str_cpy[j] = (*str)[i];
		i++;
		j++;
	}
	if (j == 0)
		str_cpy[j++] = '0';
	str_cpy[j] = '\0';
	*str = str_cpy;
	ft_realloc(str);
}

char	*ft_remove_multiple_space(char *str)
{
	char	*str_cpy;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(str);
	if (!(char *)malloc(sizeof(char) * (len + 100)))
		return (0);
	str_cpy = (char *)malloc(sizeof(char) * (len + 100));
	i = 1;
	j = 1;
	str_cpy[0] = str[0];
	while (str[i])
	{
		if (!(str[i] == ' ' && str[i - 1] == ' '))
		{
			str_cpy[j] = str[i];
			j++;
		}
		i++;
	}
	str_cpy[j] = '\0';
	ft_realloc(&str_cpy);
	return (str_cpy);
}

int	dict(struct s_dict this, char *nb)
{
	int	index;

	index = find_args(this, nb);
	if (index >= 0)
	{
		ft_putstr(ft_remove_multiple_space(this.suffix[index]));
		write(1, " ", 1);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char			*filename;
	struct s_dict	this;

	if (argc < 2 || argc > 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argv[2])
	{
		if (!security(argv[2]))
			return (0);
		filename = argv[1];
	}
	else
	{
		filename = "numbers.dict";
		if (!security(argv[1]))
			return (0);
	}
	new(&this, filename);
	number_cut(this, argv[1]);
	return (0);
}
