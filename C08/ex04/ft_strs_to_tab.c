/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:38:08 by tbarret           #+#    #+#             */
/*   Updated: 2023/08/15 09:48:32 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	dest = (char *)malloc(sizeof(*src) * i + 1);
	if (!dest)
		return (NULL);
	while (j < i)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*result;
	int			index;

	index = 0;
	result = (t_stock_str *)malloc(sizeof(t_stock_str) * ac + 1);
	if (!result)
		return (NULL);
	while (av[index] && index < ac)
	{
		result[index].size = ft_strlen(av[index]);
		result[index].str = av[index];
		result[index].copy = ft_strdup(av[index]);
		index++;
	}
	result[index].str = 0;
	return (result);
}
