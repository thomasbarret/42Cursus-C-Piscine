/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:33:17 by tbarret           #+#    #+#             */
/*   Updated: 2023/08/23 13:50:52 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	char	*swap;

	j = 0;
	i = 0;
	while (tab[j])
		j++;
	while (i < (j - 1))
	{
		if (cmp(tab[i], tab[i + 1]) > 0)
		{
			swap = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = swap;
			i = 1;
		}
		else
			i++;
	}
}
