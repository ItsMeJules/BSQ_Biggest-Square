/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:48:57 by jpeyron           #+#    #+#             */
/*   Updated: 2020/09/29 16:12:23 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"
#include "map.h"

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
			map->tab[x][y] = map->sq;
			x--;
		}
		y--;
	}
}

int			reassign_square(t_map map, t_square *sq, int obsX)
{
	if (map.height < sq->minY + sq->len)
		return (0);
	if (map.length < sq->minX + sq->len)
	{
		sq->minX = 0;
		sq->minY++;
	}
	else
		sq->minX = obsX + 1;
	return (1);
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
