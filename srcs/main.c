/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:27:56 by jpeyron           #+#    #+#             */
/*   Updated: 2020/09/29 18:01:32 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_map.h"
#include "map.h"

char	*resolve_map(char *file)
{
	t_map	*map;

	map = get_map(file);
	if (map_error(map->tab))
		return ("map error\n");


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
