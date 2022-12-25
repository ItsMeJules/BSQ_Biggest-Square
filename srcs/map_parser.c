/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 01:06:50 by jules             #+#    #+#             */
/*   Updated: 2022/01/20 01:21:28 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*str_join(char *str, char *join, int join_len, int str_len)
{
	char	*new;
	int 	i;
	int		j;

	i = 0;
	if (str == NULL)
	{
		new = malloc((join_len + 1) * sizeof(char));
		if (!new)
			return (NULL);
	}
	else
	{
		new = malloc((join_len + str_len + 1) * sizeof(char));
		if (!new)
			return (NULL);
		while (str[i])
		{
			new[i] = str[i];
			i++;
		}
	}
	free(str);
	j = -1;
	while (join[++j])
		new[i + j] = join[j];
	new[i + j] = 0;
	return (new);
}

int 	parse_map_attributes(t_parser *parser, t_map *map)
{
	int i;

	parser->read_ret = get_next_line(parser->fd, &parser->line);
	if (parser->read_ret <= 0)
		return (1);
	i = 0;
	while (parser->line[i] >= '0' && parser->line[i] <= '9')
	{
		map->height = map->height * 10 + parser->line[i] - '0';
		i++;
	}
	map->blank = parser->line[i];
	map->obs = parser->line[i + 1];
	map->sq = parser->line[i + 2];
	free(parser->line);
	if (map->blank < 32 || map->blank > 126
		|| map->obs < 32 || map->obs > 126
		|| map->sq < 32 || map->sq > 126)
		return (2);
	if (map->blank == map->obs || map->blank == map->sq || map->sq == map->obs)
		return (3);
	return (0);
}

int		check_line_len(t_parser *parser, t_map *map)
{
	int	len;

	if (map->row_len == -1)
	{
		map->row_len = check_line(parser->line, map); // size of first map line so all other lines must be this size
		len = map->row_len;
	}
	else
		len = check_line(parser->line, map);
	if (map->row_len != len)
		return (-1);
	return (len);
}

int		parse_file(t_parser *parser, t_map *map)
{
	int rows;
	int len;

	parser->read_ret = get_next_line(parser->fd, &parser->line); //2nd line read aka first map line
	if (parser->read_ret <= 0)
		return (1);
	rows = 0;
	map->row_len = -1;
	while (parser->read_ret > 0)
	{
		len = check_line_len(parser, map);
		if (len == -1)
			return (2);
		map->tab = str_join(map->tab, parser->line, map->row_len, map->length);
		map->length += len;
		rows++;
		free(parser->line);
		parser->read_ret = get_next_line(parser->fd, &parser->line);
	}
	if (rows != map->height)
		return (3);
	return (0);
}

int		parse_map(t_map *map, char *file)
{
	t_parser parser;
	
	parser.fd = 0;
	if (file)
	{
		parser.fd = open(file, O_RDONLY);
		if (parser.fd == -1)
			return (1);
	}
	if (parse_map_attributes(&parser, map) || parse_file(&parser, map))
	{
		write(1, "map error\n", 10);
		return (2);
	}
	if (parser.fd != 0)
		close(parser.fd);
	return (0);
}