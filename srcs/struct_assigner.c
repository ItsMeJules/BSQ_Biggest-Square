/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_assigner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:27:45 by rblondel          #+#    #+#             */
/*   Updated: 2020/09/29 19:53:08 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"
#include "map.h"

int		get_nbr_line(char *str)
{
	int i;
	int nbr;

	i = 0;
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += str[i] - 48;
		i++;
	}
	return (nbr);
}

char	get_blank(char *str)
{
	int i;

	i = 0;
	while (str[i] <= '9' && str[i] >= '0')
		i++;
	return (str[i]);
}

char	get_obs(char *str)
{
	int i;

	i = 0;
	while (str[i] <= '9' && str[i] >= '0')
		i++;
	return (str[i + 1]);
}

char	get_sq(char *str)
{
	int i;

	i = 0;
	while (str[i] <= '9' && str[i] >= '0')
		i++;
	return (str[i + 2]);
}

int		get_len(char *str)
{
	int i;

	i = 0;
	while (*str != '\n')
		str++;
	str++;
	while (str[i] != '\n')
		i++;
	return (i);
}
