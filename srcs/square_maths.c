/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_maths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:10:50 by jpeyron           #+#    #+#             */
/*   Updated: 2020/09/29 20:05:43 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"
#include "map.h"

int			has_obstacle(t_square sq, t_map map)
{
	int	x;
	int	y;

	y = sq.len + 1;
	while (--y)
	{
		x = sq.len + 1;
		while (--x)
		{
			if (map.tab[(sq.min_y + y) * (map.length + 1) + (sq.min_x + x)]
					== map.obs
					&& square_contains(sq, sq.min_x + x, sq.min_y + y))
				return (sq.min_y + x);
		}
	}
	return (0);
}

int			has_obstacle_wall(t_square sq, t_map map)
{
	int	x;
	int	y;

	x = sq.len + 1;
	y = sq.len;
	while (--x)
	{
		if (map.tab[(sq.min_y + y) * (map.length + 1) + (sq.min_x + x + 1)]
				== map.obs && square_walls_contains(sq, x + 1, y))
			return (1);
	}
	x = sq.len;
	y += 1;
	while (--y)
	{
		if (map.tab[(sq.min_y + y + 1) * (map.length + 1) + (sq.min_x + x)]
				== map.obs && square_walls_contains(sq, x, y + 1))
			return (1);
	}
	return (0);
}

int			square_contains(t_square sq, int x, int y)
{
	return ((sq.min_x + sq.len) >= x && sq.min_x <= x &&
			(sq.min_y + sq.len) >= y && sq.min_y <= y);
}

int			square_wall_contains(t_square sq, int x, int y)
{
	return ((sq.min_x + sq.len) >= x && (sq.min_y + sq.len) >= y);
}
