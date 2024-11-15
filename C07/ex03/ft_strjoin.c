/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:08:44 by tbarret           #+#    #+#             */
/*   Updated: 2023/08/14 09:19:46 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_join_tab(char *str, char *sep, int index, int size)
{
	int		i;
	int		j;
	char	*r;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	while (sep[j])
		j++;
	r = (char *)malloc(sizeof(char) * i + j);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		r[i] = str[i];
		i++;
	}
	while (sep[j] != '\0' && (index < size - 1))
	{
		r[i] = sep[j];
		j++;
		i++;
	}
	return (r);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (dest[c] != '\0')
	{
		c++;
	}
	while (src[i] != '\0')
	{
		dest[c + i] = src[i];
		i++;
	}
	dest[c + i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*r;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (size <= 0)
	{
		r = (char *)malloc(sizeof(char) * 1);
		*r = 0;
		return (r);
	}
	r = (char *)malloc(sizeof(char) * size);
	if (!r)
		return (NULL);
	*r = 0;
	while (i < size)
	{
		r = ft_strcat(r, ft_join_tab(strs[i], sep, i, size));
		i++;
	}
	return (r);
}
