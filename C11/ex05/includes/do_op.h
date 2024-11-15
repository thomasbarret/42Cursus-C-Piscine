/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:31:38 by tbarret           #+#    #+#             */
/*   Updated: 2023/08/23 08:48:26 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H
# include <unistd.h>

int		ft_add(int a, int b);
int		ft_div(int a, int b);
int		ft_mod(int a, int b);
int		ft_mult(int a, int b);
int		ft_sub(int a, int b);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putnbr(int nb);

#endif