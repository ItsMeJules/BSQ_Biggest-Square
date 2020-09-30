/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:25:34 by jpeyron           #+#    #+#             */
/*   Updated: 2020/09/30 22:01:24 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct	s_map
{
	char	*tab;
	int		height;
	int		length;
	char	blank;
	char	obs;
	char	sq;
}				t_map;

#endif
