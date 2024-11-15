/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:17:05 by abutet            #+#    #+#             */
/*   Updated: 2023/08/20 19:07:48 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include "string.h"

char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*dst;

	dst = malloc(sizeof(char) * (n + 1));
	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*num_cut(int m, char *str, int len, struct s_dict this)
{
	char	*th;
	int		i;

	th = (char *)malloc(sizeof(char) * (m * 3 + 1));
	th[0] = '1';
	i = 1;
	while (i <= m * 3)
	{
		th[i] = '0';
		i++;
	}
	dict(this, th);
	str = ft_strdup(&str[len - (m * 3)]);
	if (str[0] == '0')
		ft_remove_start_zeros(&str);
	return (str);
}

void	num_split(char *str, struct s_dict this, int len)
{
	int	m;

	m = len % 3;
	if (m == 0)
	{
		sep(ft_strndup(str, 1), this);
		str[0] = '1';
		sep(ft_strndup(str, 3), this);
	}
	else
		sep(ft_strndup(str, m), this);
}

void	number_cut(struct s_dict this, char *str)
{
	int	len;
	int	m;

	if (str[0] == '0')
		ft_remove_start_zeros(&str);
	while (str)
	{
		len = ft_strlen(str);
		num_split(str, this, len);
		m = (len - 1) / 3;
		if (m > 0)
		{
			str = num_cut(m, str, len, this);
			m = 0;
			if (str[0] == '0')
				ft_remove_start_zeros(&str);
			if (str[0] == '0')
				break ;
		}
		else
			break ;
	}
}
