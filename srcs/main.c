/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:27:56 by jpeyron           #+#    #+#             */
/*   Updated: 2020/09/29 20:04:36 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"
#include "square.h"
#include "map.h"

void	putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

char	*resolve_map(char *file)
{
	t_map		*map;
	t_square	sq;
	int			obs_x;

	map = get_map(file);
//	if (map_error(map->tab))
//		return ("map error\n");
	sq = *create_square(0, 0, 0);
	while (sq.min_y + sq.len <= map->height + 1)
	{
		if (!(obs_x = has_obstacle(sq, *map)))
		{
			while (!has_obstacle_wall(sq, *map))
			{
				sq.len++;
			}
			reassign_square(*map, &sq, sq.min_x + sq.len + 1);
		}
		else
			reassign_square(*map, &sq, obs_x + 1);
	}
	draw_square(sq, &map);
	return (map->tab);
}

int	main(int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		putstr(resolve_map(av[i]));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
