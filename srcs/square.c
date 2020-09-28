/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:48:57 by jpeyron           #+#    #+#             */
/*   Updated: 2020/09/28 19:08:58 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"

int			square_contains(t_square sq, int x, int y)
{
	return ((sq.minX + sq.len) >= x && sq.minX <= x &&
			(sq.minY + sq.len) >= y && sq.minY <= y);
}

void		expand_square(t_square *sq, int len)
{
	sq->x += len;
	sq->y += len;
	sq->len += len;
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
