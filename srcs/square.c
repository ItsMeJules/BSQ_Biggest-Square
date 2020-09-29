/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:48:57 by jpeyron           #+#    #+#             */
/*   Updated: 2020/09/29 20:02:26 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "square.h"
#include "map.h"

void		draw_square(t_square sq, t_map **map)
{
	int	x;
	int	y;

	y = sq.min_y + sq.len;
	while (y >= sq.min_y)
	{
		x = sq.min_x + sq.len;
		while (x >= sq.min_x)
		{
			(*map)->tab[y * ((*map)->length + 1) + x] = (*map)->sq;
			x--;
		}
		y--;
	}
}

int			reassign_square(t_map map, t_square *sq, int obs_x)
{
	if (map.height < sq->min_y + sq->len)
		return (0);
	if (map.length <= sq->min_x + sq->len)
	{
		sq->min_x = 0;
		sq->min_y++;
	}
	else
		sq->min_x = obs_x + 1;
	return (1);
}

t_square	*create_square(int x, int y, int len)
{
	t_square	*sq;

	if (!(sq = malloc(sizeof(t_square))))
		return (NULL);
	sq->min_x = x;
	sq->min_y = y;
	sq->len = len;
	return (sq);
}
