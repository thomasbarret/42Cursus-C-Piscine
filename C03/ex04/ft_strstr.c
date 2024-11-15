/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:49:50 by tbarret           #+#    #+#             */
/*   Updated: 2023/08/15 16:21:40 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	str_i;
	int	find_i;

	str_i = 0;
	if (!to_find[0])
		return (str);
	while (str[str_i] != '\0')
	{
		find_i = 0;
		while (str[str_i + find_i] != '\0'
			&& str[str_i + find_i] == to_find[find_i])
		{
			if (to_find[find_i + 1] == '\0')
				return (&str[str_i]);
			++find_i;
		}
		++str_i;
	}
	return (0);
}
