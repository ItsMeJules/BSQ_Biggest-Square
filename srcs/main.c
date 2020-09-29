/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:27:56 by jpeyron           #+#    #+#             */
/*   Updated: 2020/09/29 19:03:52 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_map.h"
#include "map.h"

char	*resolve_map(char *file)
{
	t_map		*map;
	t_square	sq;

	map = get_map(file);
	if (map_error(map->tab))
		return ("map error\n");
	sq = create_square(0, 0, 0);
	while (sq.min_y + sq.len <= map.height + 1)
	{
		if (!has_obstacle(sq, map))
		{
			while (!has_obstacle_wall(sq, map))
			{
				sq.len++;
			}
		}
		else
			sq.len++;
	}
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
