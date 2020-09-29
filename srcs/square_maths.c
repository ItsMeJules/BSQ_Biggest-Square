/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_maths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:10:50 by jpeyron           #+#    #+#             */
/*   Updated: 2020/09/29 15:19:49 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"
#include "map.h"

int			has_obstacle(t_square sq, t_map map, int (*con)(t_square, int, int))
{
	int		i;

	i = sq.len + 1;
	while (--i)
	{
		if (map.tab[sq.minX + i][sq.minY + i] == map.obs &&
				con(sq, sq.minX + i, sq.minY + i))
			return (1);
	}
	return (0);
}

int			square_contains(t_square sq, int x, int y)
{
	return ((sq.minX + sq.len) >= x && sq.minX <= x &&
			(sq.minY + sq.len) >= y && sq.minY <= y);
}

int			square_wall_contains(t_square sq, int x, int y)
{
	return ((sq.minX + sq.len) >= x && (sq.minY + sq.len) >= y);
}

void		expand_square(t_square *sq, int len)
{
	sq->x += len;
	sq->y += len;
	sq->len += len;
}
