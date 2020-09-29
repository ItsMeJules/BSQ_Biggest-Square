/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:18:19 by rblondel          #+#    #+#             */
/*   Updated: 2020/09/29 17:22:11 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_map.h"
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
	str[sizeof_file + 1] = 0;
	return (str);
}

t_map	*ft_get(char *file_path)
{
	t_map	*map;
	char	*tab_str;
	int		i;

	i = 0;
	tab_str = map_to_str(file_path, count_size(file_path));
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
