/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:48:57 by jpeyron           #+#    #+#             */
/*   Updated: 2020/09/29 12:01:28 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"
#include "map.h"

int			square_contains(t_square sq, int x, int y)
{
	return ((sq.minX + sq.len) >= x && (sq.minY + sq.len) >= y);
}

int			has_obstacle(t_square sq, t_map map)
{
	int		i;

	i = sq.len + 1;
	while (--i)
	{
		if (map.tab[sq.minX + i][sq.minY + i] == map.obs &&
				square_contains(sq, sq.minX + i, sq.minY + i))
			return (1);
	}
	return (0);
}

void		expand_square(t_square *sq, int len)
{
	sq->x += len;
	sq->y += len;
	sq->len += len;
}

void		draw_square(t_square sq, t_map *map) 
{
	int	x;
	int	y;

	y = sq.len;
	while (sq.minY + y >= sq.minY)
	{
		x = sq.len;
		while (sq.minX + x >= sq.minX)
		{
			map->tab[x][y] = map->obs;
			x--;
		}
		y--;
	}
}

t_square	create_square(int x, int y, int len)
{
	t_square	sq;

	if (!(sq = malloc(sizeof(t_square))))
		return (NULL);
	sq.minX = x;
	sq.minY = y;
	sq.len = len;
	return (sq);
}
