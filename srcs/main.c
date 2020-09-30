/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:27:56 by jpeyron           #+#    #+#             */
/*   Updated: 2020/09/30 19:07:58 by rblondel         ###   ########.fr       */
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

char	*resolve_map(t_map *map, t_square sq)
{
	int			obs_x;
	int			found_x;
	int			found_y;

	while (sq.min_y + sq.len < map->height)
	{
		if ((obs_x = has_obstacle(sq, *map)) == -1)
		{
			while ((obs_x = has_obstacle_wall(sq, *map)) == -1 &&
					sq.len + 1 < map->length)
			{
				found_x = sq.min_x;
				found_y = sq.min_y;
				sq.len++;
			}
			if (obs_x != -1)
				reassign_square(*map, &sq, obs_x);
		}
		else
			reassign_square(*map, &sq, obs_x);
	}
	sq.min_x = found_x;
	sq.min_y = found_y;
	draw_square(sq, &map);
	return (map->tab);
}

int		main(int ac, char **av)
{
	int			i;
	t_map		*map;
	t_square	sq;

	i = 0;
	while (++i < ac)
	{
		map = get_map(av[i]);
		if (!map_error(*map))
		{
			putstr("map error\n");
			continue;
		}
		sq = *create_square(0, 0, 0);
		putstr(resolve_map(map, sq));
		write(1, "\n", 1);
	}
	return (0);
}
