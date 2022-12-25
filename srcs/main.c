/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 01:07:07 by jules             #+#    #+#             */
/*   Updated: 2022/04/02 00:09:11 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void		draw_square(t_square sq, t_map map)
{
	int		x;
	int		y;

	y = sq.min_y + sq.len;
	if (y < 0)
		return ;
	while (y >= sq.min_y)
	{
		x = sq.min_x + sq.len;
		while (x >= sq.min_x)
		{
			map.tab[y * map.row_len + x] = map.sq;
			x--;
		}
		y--;
	}
}

void increase_size(t_square *bsq, t_square *sq)
{
	t_square sq_val;

	sq_val = *sq;
	sq->len++;
	if (bsq->len < sq_val.len)
	{
		bsq->min_x = sq_val.min_x;
		bsq->min_y = sq_val.min_y;
		bsq->len = sq_val.len;				
	}
}

void init_map_sq(t_map *map, t_square *sq)
{
	map->tab = NULL;
	map->height = 0;
	map->length = 0;
	set_square(sq, 0);
}

void resolve_map(t_map map, t_square sq)
{
	int			obs_x;
	t_square	bsq;
	t_square	*bsq_ptr;
	t_square	*sq_ptr;
	
	obs_x = -1;
	bsq_ptr = &bsq;
	sq_ptr = &sq;
	set_square(bsq_ptr, -1);
	while (sq.min_y + sq.len < map.height)
	{
		if (sq.min_x + sq.len >= map.row_len
	 		|| bsq.min_x + bsq.len >= map.row_len)
		{
			sq.min_x = 0;
			sq.min_y++;
			sq.len = 0;
			continue ;
		}
		else
			obs_x = has_obstacle_walls(sq, map);		
		if (obs_x == -1)
			increase_size(bsq_ptr, sq_ptr);
		else
			reassign_square(map, &sq, obs_x);
	}
	draw_square(bsq, map);
}

int main(int ac, char **av)
{
	t_map		map;
	t_square	sq;
	int i;
	int in;

	i = 0;
	in = ac ==1;
	while (++i < ac || in)
	{
		init_map_sq(&map, &sq);
		if (in)
			parse_map(&map, NULL);
		else
			parse_map(&map, av[i]);
		resolve_map(map, sq);
		i = -1;
		while (++i < map.height)
		{
			write(1, map.tab + i * map.row_len, map.row_len);
			write(1, "\n", 1);
		}
		free(map.tab);
	}
	return (0);
}