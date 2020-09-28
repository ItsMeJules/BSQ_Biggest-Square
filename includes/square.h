/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:44:44 by jpeyron           #+#    #+#             */
/*   Updated: 2020/09/28 19:09:05 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_H
# define SQUARE_H

t_square	create_square(int x, int y, int len);
int			square_contains(t_square sq, int x, int y);
void		expand_square(t_square *sq, int len);

typedef struct	s_square
{
	int	minX;
	int	minY;
	int	len;
}				t_square;

#endif
