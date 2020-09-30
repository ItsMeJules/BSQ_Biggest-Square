/*************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 11:16:49 by rblondel          #+#    #+#             */
/*   Updated: 2020/09/30 22:41:38 by rblondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"
#include "map.h"

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
	while (str[i])
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
	write(1, "test3\n", 6);
	return (1);
}
#include <stdio.h>
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
	write(1, "test2\n", 6);
		while (str[i] != '\n')
		{
	write(1, "test6\n", 6);
	printf("%d,%i\n", str[i], i);
	printf("%c", str[1]);
			if (str[i] != blk && str[i] != obs)
				return (0);
			i++;
		}
		i++;
	}
	write(1, "test4\n", 6);
	return (1);
}

int check_len(char *str, int height)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			y++;
		i++;
	}
	if (y != height)
		return (0);
	write(1, "test3\n", 6);
	return (1);
}

int	map_error(t_map map)
{
	if (check_len(map.tab, map.height)
		&& check_char(map.tab, map.blank, map.obs, map.sq)
			&& check_line(map.tab))
		return (1);
	return (0);
}
