/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:42:47 by tbarret           #+#    #+#             */
/*   Updated: 2023/08/20 19:09:49 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H
# define RUSH "rush"

# include "string.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

struct			s_dict{
	int		size;
	char	**prefix;
	char	**suffix;
};

char			**ft_split(char *str, char *charset);

int				strsize(char *str);

int				size(char *filename);

char			*cut(int x, int y, char *filename);

int				find_args(struct s_dict this, char *str);

int				security(char *str);

struct s_dict	gen(struct s_dict *this, int file, char *filename);

struct s_dict	new(struct s_dict *this, char *filename);

int				ft_strlen(char *str);

void			ft_putstr(char *str);

char			*ft_strncpy(char *dest, char *src, unsigned int n);

int				only_num(char *str);

int				ft_strcmp(char *s1, char *s2);

void			sep(char *nb, struct s_dict this);

char			*ft_strdup(char *src);

void			ft_remove_start_zeros(char **str);

void			num_cent(char *str, struct s_dict this);

int				dict(struct s_dict this, char *nb);

void			number_cut(struct s_dict this, char *str);

char			**ft_split(char *str, char *charset);

#endif
