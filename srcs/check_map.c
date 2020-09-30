/*************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 11:16:49 by rblondel          #+#    #+#             */
/*   Updated: 2020/09/30 17:59:04 by rblondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_map.h"
#include "map.h"

int check_line(char *str)
{
	int i;
	int y;
	int line_len;

	i = 0;
	y = 0;
	if (!str[i])
		return (0);
	while(str[i] != '\n')
		i++;
	line_len = i;
	i = 0;
	while(str[i])
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

int check_char(char *str, char blk, char obs, char sq)
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

int check_len(char *str, int len)
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
	if (y != len)
		return (0);
	return (1);
}
