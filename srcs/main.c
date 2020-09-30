/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:27:56 by jpeyron           #+#    #+#             */
/*   Updated: 2020/09/30 23:01:50 by rblondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"
#include "square.h"
#include "map.h"

void	resolve_map(t_map *map, t_square sq)
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
}

void	resolve_one_one(t_map *map)
{
	write(1, (map->tab[0] == map->blank) ? &map->blank : &map->obs, 1);
	/*if(map->tab[0] == map->blank)
	{
		write(1, &map->sq, 1);
		write(1, "\n", 1);
	}
	else
	{
		write(1, &map->obs, 1);*/
		write(1, "\n", 1);
	//}
}

void	resolve_one_line(t_map *map)
{
	int	i;

	i = 0;
	while (map->tab[i] != map->blank)
		i++;
	map->tab[i] = map->sq;
}

#include <stdio.h>

int		main(int ac, char **av)
{
	int 		i;
	t_map		*map;

	i = 0;
	while (++i < ac)
	{
		map = get_map(av[i]);
		if (!map_error(*map))
		{
			write(1, "map error\n", 10);
			continue;
		}
		printf("%i, %i", map->height, map->length);
		if (map->height == 1 && map->length == 1)
		{
			resolve_one_one(map);
			continue;
		}
		if (map->height == 1 || map->length == 1)
			resolve_one_line(map);
		else
			resolve_map(map, *create_square(0, 0, 0));
		write(1, "oui\n", 4);
		write(1, map->tab, map->height * (map->length + 1));
		write(1, "\n", 1);
	}
	return (0);
}
