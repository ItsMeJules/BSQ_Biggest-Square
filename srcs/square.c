/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:48:57 by jpeyron           #+#    #+#             */
/*   Updated: 2020/09/28 17:13:45 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_utils.h"
#include "square.h"

int			square_contains(t_square sq, t_point pt)
{
	return (sq.max.x >= pt.x && sq.min.x <= pt.x &&
			sq.max.y >= pt.y && sq.min.y <= pt.y);
}

t_square	create_square(t_point a, t_point b)
{
	t_square	sq;

	if (!(sq = malloc(sizeof(t_square))))
		return (NULL);
	if (!(sq.min = malloc(sizeof(t_point))))
		return (NULL);
	if (!(sq.max = malloc(sizeof(t_point))))
		return (NULL);
	sq.min.x = min(a.x, b.x);
	sq.min.y = min(a.y, b.y);
	sq.max.x = max(a.x, b.x);
	sq.max.y = max(a.y, b.y);
	return (sq);
}
