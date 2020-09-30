/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 11:16:49 by rblondel          #+#    #+#             */
/*   Updated: 2020/09/30 18:49:12 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"
#include "map.h"

#include <stdio.>

int	check_line(char *str)
{
	int i;
	int y;
	int line_len;

	i = 0;
	y = 0;
	if (!str[i])
		return (0);
	while (str[i] != '\n')
		i++;
	line_len = i;
	i = 0;
	whilei (str[i])
	{
		y = 0;
		while (str[i] != '\n')
		{
			i++;
			y++;
		}
		if (line_len != y)
			return (0);
		i++;
	}
	return (1);
}

int	check_char(char *str, char blk, char obs, char sq)
{
	int i;

	i = 0;
	if (blk < 32 || blk > 126 || obs < 32 || obs > 126 || sq < 32 || sq > 126)
		return (0);
	if (blk == obs || blk == sq || sq == obs)
		return (0);
	while (str[i])
	{
		while (str[i] != '\n')
		{
			if (str[i] != blk && str[i] != obs)
				return (0);
			i++;
		}
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	t_map	*map;
	map = get_map(av[1]);
	printf("%s", map->tab);
	printf("%i\n", check_line(map->tab));
	printf("%i\n", check_char(map->tab, map->blank, map->obs, map->sq));
	return (0);
}
