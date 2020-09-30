/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:44:44 by jpeyron           #+#    #+#             */
/*   Updated: 2020/09/30 14:47:07 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_H
# define SQUARE_H

#include "map.h"

typedef struct	s_square
{
	int	min_x;
	int	min_y;
	int	len;
}				t_square;

int				has_obstacle_wall(t_square sq, t_map map);
int				has_obstacle(t_square sq, t_map map);
int				square_contains(t_square sq, int x, int y);
int				square_walls_contains(t_square sq, int os, int x, int y);
void			expand_square(t_square *sq);

void			draw_square(t_square sq, t_map **map);
int				reassign_square(t_map map, t_square *sq, int obs_x);
t_square		*create_square(int x, int y, int len);

#endif
