/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:14:47 by tbarret           #+#    #+#             */
/*   Updated: 2023/08/20 17:18:44 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> 

int		ft_separator(char c, char *charset);
int		ft_counts(char *str, char *charset);
int		ft_strlen2(char *str, char *charset);
char	*ft_word(char *str, char *charset);

char	**ft_split(char *str, char *charset)
{
	char	**r;
	int		i;

	i = 0;
	r = (char **)malloc(
			sizeof(char *) * (ft_counts(str, charset) + 1));
	while (*str != '\0')
	{
		while (*str != '\0' && ft_separator(*str, charset))
				str++;
		if (*str != '\0')
		{
			r[i] = ft_word(str, charset);
			i++;
		}
		while (*str && !ft_separator(*str, charset))
			str++;
	}
	r[i] = 0;
	return (r);
}

int	ft_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_counts(char *str, char *charset)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ft_separator(str[i], charset))
			i++;
		if (str[i] != '\0')
			c++;
		while (str[i] != '\0' && !ft_separator(str[i], charset))
			i++;
	}
	return (c);
}

int	ft_strlen2(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !ft_separator(str[i], charset))
		i++;
	return (i);
}

char	*ft_word(char *str, char *charset)
{
	int		l;
	int		i;
	char	*word;

	i = 0;
	l = ft_strlen2(str, charset);
	word = (char *)malloc(sizeof(char) * (l + 1));
	while (i < l)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}
