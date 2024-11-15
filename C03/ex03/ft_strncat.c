/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:57:40 by tbarret           #+#    #+#             */
/*   Updated: 2023/08/06 11:51:50 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	c;

	i = 0;
	c = 0;
	while (dest[c] != '\0')
	{
		c++;
	}
	while (src[i] != '\0' && (i < nb))
	{
		dest[c + i] = src[i];
		i++;
	}
	dest[c + i] = '\0';
	return (dest);
}
