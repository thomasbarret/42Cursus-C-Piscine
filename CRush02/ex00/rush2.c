/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:03:09 by abutet            #+#    #+#             */
/*   Updated: 2023/08/20 18:36:28 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include "string.h"

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*dst;

	len = ft_strlen(src);
	dst = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	sep2(char *nb, char *str, int i)
{
	str = ft_strdup(&nb[i]);
	if (str[0] == '0')
		ft_remove_start_zeros(&str);
}

void	sep(char *nb, struct s_dict this)
{
	int		i;
	int		len;
	int		lt;
	char	*str;

	str = ft_strdup(nb);
	lt = ft_strlen(nb);
	len = lt;
	while (len > 0)
	{
		i = 0;
		while (i < len)
		{
			if (dict(this, str) == 1)
			{
				str = ft_strdup(&nb[lt - len + (len - i)]);
				if (str[i] == '0')
					break ;
			}
			else
				str[len - i - 1] = '0';
			i++;
		}
		len = ft_strlen(str);
	}
}
