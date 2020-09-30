/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_maths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:10:50 by jpeyron           #+#    #+#             */
/*   Updated: 2020/09/30 16:57:15 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"
#include "map.h"

int			has_obstacle(t_square sq, t_map map)
{
	int	x;
	int	y;

	y = sq.min_y + sq.len + 1;
	while (--y >= sq.min_y)
	{
		x = sq.min_x + sq.len + 1;
		while (--x >= sq.min_x)
		{
			if (map.tab[(y) * (map.length + 1) + (x)]
					== map.obs
					&& square_contains(sq, x, y))
				return (x);
		}
	}
	return (-1);
}

int			has_obstacle_wall(t_square sq, t_map map)
{
	int	x;
	int	y;

	x = sq.min_x + sq.len + 2;
	y = sq.min_y + sq.len + 1;
	while (--x >= sq.min_x)
	{
		if (map.tab[y * (map.length + 1) + x]
				== map.obs && square_walls_contains(sq, 1, x, y))
			return (x);
	}
	x = sq.min_x + sq.len + 1;
	y += 1;
	while (--y >= sq.min_y)
	{
		if (map.tab[y * (map.length + 1) + x]
				== map.obs && square_walls_contains(sq, 1, x, y))
			return (x);
	}
	return (-1);
}

int			square_contains(t_square sq, int x, int y)
{
	return ((sq.min_x + sq.len) >= x && sq.min_x <= x &&
			(sq.min_y + sq.len) >= y && sq.min_y <= y);
}

int			square_walls_contains(t_square sq, int os, int x, int y)
{
	return x == sq.min_x || x == (sq.min_x + sq.len + os)
		|| y == sq.min_y || y == (sq.min_y + sq.len + os);
}
