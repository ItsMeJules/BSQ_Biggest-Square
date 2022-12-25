#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"

typedef struct	s_square
{
	int	min_x;
	int	min_y;
	int	len;
}				t_square;

typedef struct	s_map
{
	char	*tab;
	int		height;
	int		length;
	int		row_len;
	char	blank;
	char	obs;
	char	sq;
}				t_map;

typedef struct	s_parser
{
	int fd;
	char *line;
	int read_ret;
}				t_parser;

char	*str_join(char *str, char *join, int join_len, int str_len);
int 	parse_map_attributes(t_parser *parser, t_map *map);
int		parse_file(t_parser *parser, t_map *map);
int		parse_map(t_map *map, char *file);

void	set_char_at(t_map *map, int x, int y, char c);
char	get_char_at(t_map map, int x, int y);
int		check_line(char *str, t_map *map);

int	reassign_square(t_map map, t_square *sq, int obs_x);
void	set_square(t_square *sq, int val);
int has_obstacle_walls(t_square sq, t_map map);
int	has_obstacle(t_square sq, t_map map);

#endif