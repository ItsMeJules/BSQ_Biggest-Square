/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:18:19 by rblondel          #+#    #+#             */
/*   Updated: 2020/10/01 12:34:10 by rblondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "map_parser.h"
#include "map.h"

int		count_size(char *filename)
{
	int				fd;
	char			buf[BUF_SIZE + 1];
	int				bytes;
	unsigned long	count;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((bytes = read(fd, buf, BUF_SIZE)))
	{
		if (bytes < 0)
		{
			close(fd);
			return (0);
		}
		count += bytes;
	}
	close(fd);
	return (count);
}

char	*map_to_str(char *filename, int sizeof_file)
{
	int		fd;
	char	*str;

	fd = open(filename, O_RDONLY);
	if (!(str = malloc(sizeof(char) * sizeof_file + 1)))
		return (0);
	read(fd, str, sizeof_file);
	close(fd);
	str[sizeof_file] = 0;
	return (str);
}

char	*str_con_cat(char *str, int length, char *buf, int lenstr)
{
	char	*temp;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!(temp = malloc(sizeof(char) * (length + 1))))
		return (NULL);
	while (i < length)
	{
		if (i < lenstr)
			temp[i] = str[i];
		else
		{
			temp[i] = buf[y];
			y++;
		}
		i++;
	}
	temp[i] = 0;
	return (temp);
}

char	*read_stdin(void)
{
	int		bytes;
	char	*str;
	char	*temp;
	char	buf[BUF_SIZE + 1];
	int		strlen;

	str = NULL;
	if (!(str = malloc(sizeof(char))))
		return (NULL);
	str[0] = 0;
	while ((bytes = read(0, buf, BUF_SIZE)))
	{
		strlen = len(str);
		if (!(temp = malloc(sizeof(char) * bytes + strlen + 1)))
			return (NULL);
		temp = str_con_cat(str, bytes + strlen, buf, strlen);
		free(str);
		str = temp;
		temp = NULL;
	}
	return (str);
}

t_map	*get_map(char *file_path)
{
	t_map	*map;
	char	*tab_str;
	int		i;

	i = 0;
	if (file_path)
		tab_str = map_to_str(file_path, count_size(file_path));
	else
		tab_str = read_stdin();
	if (!(map = malloc(sizeof(t_map))))
		return (NULL);
	map->height = get_nbr_line(tab_str);
	map->blank = get_blank(tab_str);
	map->obs = get_obs(tab_str);
	map->sq = get_sq(tab_str);
	while (tab_str[i] != '\n')
		i++;
	i++;
	map->tab = tab_str + i;
	map->length = get_len(map->tab);
	return (map);
}
