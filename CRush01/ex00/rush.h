/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agolding <agolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:56:14 by agolding          #+#    #+#             */
/*   Updated: 2023/08/13 23:43:18 by agolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H
# include <unistd.h>
# include <stdlib.h>
# define RUSH "rush"

int				ft_number_count(char *str);
int				*ft_split(char *str, int size);

// BOARD.C

struct			s_board{
	int	size;
	int	*values;
	int	*indices;
	int	*mask;
};

struct s_board	*new(int size, int *indices);

void			set_value(struct s_board *this, int id, int value);
void			set_value_and_lock(struct s_board *this, int id, int value);

int				get_value(struct s_board *this, int id);
int				get_value_xy(struct s_board *this, int x, int y);
int				get_mask(struct s_board *this, int id);

int				*get_indices(struct s_board *this, int id);

void			show_result(struct s_board *this);

int				get_idx(int size, int x, int y);
int				get_col(int size, int id);
int				get_row(int size, int id);
int				is_valid_indice(struct s_board *this, int id);
int				is_valid_row(struct s_board *this, int row,
					int col, int indice);
int				is_valid_row_right(struct s_board *this, int row,
					int col, int indice);
int				is_valid_col_right(struct s_board *this,
					int row, int col, int indice);
int				is_valid_col(struct s_board *this,
					int row, int col, int indice);
// Rush.C
void			find_the_only_one(struct s_board *this);
int				can_be_placed(struct s_board *this, int x, int id);
int				find_height(struct s_board *this, int id);
void			solve_skycraper(struct s_board *this);

#endif
