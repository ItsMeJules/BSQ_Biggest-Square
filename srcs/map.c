/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:27:53 by jpeyron           #+#    #+#             */
/*   Updated: 2020/09/29 16:52:49 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "square.h"

char	*change_line(t_map map, int line)
{
	char	*line_x;
	int		i;

	line_x = map.tab[0];
	i = 1;
	while (line--)
	{
		line_x = map.tab[i * (map.length + 1)];
		i++;
	}
	return (line_x);
}
