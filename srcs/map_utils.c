#include "bsq.h"

void	set_char_at(t_map *map, int x, int y, char c)
{
	map->tab[y * map->row_len + x] = c;
}

char	get_char_at(t_map map, int x, int y)
{
	return (map.tab[y * map.row_len + x]);
}

int		check_line(char *str, t_map *map)
{
	int i;

	i = -1;

	while (str[++i])
	{
		if (str[i] != map->blank && str[i] != map->obs)
			return (1);
	}
	return (i);
}