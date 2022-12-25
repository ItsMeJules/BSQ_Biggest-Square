#include "bsq.h"

int	reassign_square(t_map map, t_square *sq, int obs_x)
{
	if (map.height < sq->min_y + sq->len)
		return (0);
	if (map.row_len <= obs_x + 1 + sq->len) // +1 to go past the obstacle
	{
		sq->min_x = 0;
		sq->min_y++;
		sq->len = 0;
	}
	else
	{
		sq->min_x = obs_x + 1; // +1 to go past the obstacle
		sq->len = 0;
	}
	return (1);
}

int	has_obstacle(t_square sq, t_map map)
{
	int	x;
	int	y;

	y = sq.min_x + sq.len;
	while (--y >= sq.min_y)
	{
		x = sq.min_x + sq.len;
		while (--x >= sq.min_x)
		{
			if (get_char_at(map, x, y) == map.obs)
				return (x);
		}
	}
	return (0);
}

void	set_square(t_square *sq, int val)
{
	sq->min_x = val;
	sq->min_y = val;
	sq->len = val;
}

int	has_obstacle_walls(t_square sq, t_map map)
{
	int	x;
	int	y;

	x = sq.min_x + sq.len;
	y = sq.min_y + sq.len;
	while (x >= sq.min_x)
	{
		if (get_char_at(map, x, y) == map.obs)
			return (x);
		x--;
	}
	x = sq.min_x + sq.len;
	while (y >= sq.min_y)
	{
		if (get_char_at(map, x, y) == map.obs)
			return (x);
		y--;
	}
	return (-1);
}