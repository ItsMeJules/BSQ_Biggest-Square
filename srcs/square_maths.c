/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_maths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:10:50 by jpeyron           #+#    #+#             */
/*   Updated: 2020/09/29 17:02:11 by jpeyron          ###   ########.fr       */
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
		if (change_line(map, sq.min_y + i)[sq.min_x + i] == map.obs &&
				con(sq, sq.min_x + i, sq.min_y + i))
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

void		expand_square(t_square *sq)
{
	sq->x++;
	sq->y++;
	sq->len++;
}
