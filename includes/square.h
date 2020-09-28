/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:44:44 by jpeyron           #+#    #+#             */
/*   Updated: 2020/09/28 18:18:28 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_H
# define SQUARE_H

int			square_contains(t_square sq, t_point pt);
int			square_len(t_square sq, int a);
t_square	create_square(t_point a, t_point b);

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_square
{
	t_point	min;
	t_point	max;
}				t_square;

#endif
