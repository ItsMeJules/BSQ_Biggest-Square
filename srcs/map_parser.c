/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:18:19 by rblondel          #+#    #+#             */
/*   Updated: 2020/10/01 00:38:13 by rblondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "map_parser.h"
#include "map.h"
void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		return ((void)write(1, "-2147483648", 11));
	nb < 0 ? write(1, "-", 1) : 0;
	nb < 0 ? nb = nb * -1 : 0;
	nb >= 10 ? ft_putnbr(nb / 10) : 0;
	nb = (nb % 10) + 48;
	write(1, &nb, 1);
}

int len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		count_size(char *filename)
{
	int				fd;
	char			buf[BUF_SIZE + 1];
	int				bytes;
	unsigned long	count;

	count = 0;
	fd = filename == NULL ? 0 : open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((bytes = read(fd, buf, BUF_SIZE)))
	{
		write(1, buf, bytes);
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
	int i = 0;

	fd = filename == NULL ? 0 : open(filename, O_RDONLY);
	if (!(str = malloc(sizeof(char) * sizeof_file + 1)))
		return (0);
	i = read(fd, str, sizeof_file);
	close(fd);
	str[sizeof_file] = 0;
	ft_putnbr(sizeof_file);
	ft_putnbr(i);
	write(1, &str[8], 1);
	write(1, "tit", 3);
	ft_putnbr(len(str));
	write(1, str, sizeof_file);
	return (str);
}

t_map	*get_map(char *file_path)
{
	t_map	*map;
	char	*tab_str;
	int		i;

	i = 0;
	tab_str = map_to_str(file_path, count_size(file_path));
	write(1, tab_str, 936);
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
